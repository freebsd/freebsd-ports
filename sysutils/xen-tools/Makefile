# Created by: Evan Sarmiento <esarmiento@wayfair.com>
# $FreeBSD$

PORTNAME=	xen-tools
PORTVERSION=	4.1.3
PORTREVISION=	3
CATEGORIES=	sysutils
DISTNAME=	xen-${PORTVERSION}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Xen tools within FreeBSD domU

MASTER_SITES=	http://bits.xensource.com/oss-xen/release/${PORTVERSION}/
DISTFILES=	xen-${PORTVERSION}.tar.gz

USES=		gmake
USE_PYTHON=	yes

ONLY_FOR_ARCHS=		amd64 i386 ia64
ONLY_FOR_ARCHS_REASON=	"not yet ported to anything other than amd64, i386, or ia64"

PLIST_FILES=	lib/libxenstore.so.3.0 \
		bin/xen-detect \
		bin/xenstore \
		bin/xenstore-control \
		bin/xenstore-chmod \
		bin/xenstore-exists \
		bin/xenstore-list \
		bin/xenstore-ls \
		bin/xenstore-read \
		bin/xenstore-rm \
		bin/xenstore-write

do-build:
	cd ${WRKSRC}/tools && ${GMAKE} -C include
	cd ${WRKSRC}/tools/misc && ${GMAKE} xen-detect
	cd ${WRKSRC}/tools/xenstore && ${GMAKE} clients

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tools/misc/xen-detect ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/xenstore/xenstore ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/xenstore/xenstore-control ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/xenstore/libxenstore.so.3.0 ${STAGEDIR}${PREFIX}/lib
	${LN} -sf ${PREFIX}/bin/xenstore ${STAGEDIR}${PREFIX}/bin/xenstore-chmod
	${LN} -sf ${PREFIX}/bin/xenstore ${STAGEDIR}${PREFIX}/bin/xenstore-exists
	${LN} -sf ${PREFIX}/bin/xenstore ${STAGEDIR}${PREFIX}/bin/xenstore-list
	${LN} -sf ${PREFIX}/bin/xenstore ${STAGEDIR}${PREFIX}/bin/xenstore-ls
	${LN} -sf ${PREFIX}/bin/xenstore ${STAGEDIR}${PREFIX}/bin/xenstore-read
	${LN} -sf ${PREFIX}/bin/xenstore ${STAGEDIR}${PREFIX}/bin/xenstore-rm
	${LN} -sf ${PREFIX}/bin/xenstore ${STAGEDIR}${PREFIX}/bin/xenstore-write

.include <bsd.port.mk>
