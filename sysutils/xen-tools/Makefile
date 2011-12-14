# New ports collection makefile for:    xen-tools
# Date created:                         13 December 2011
# Whom:                                 Evan Sarmiento <esarmiento@wayfair.com>
#
# $FreeBSD$

PORTNAME=	xen-tools
PORTVERSION=	4.0.1
CATEGORIES=	sysutils
DISTNAME=	xen-${PORTVERSION}

MAINTAINER=	esarmiento@wayfair.com
COMMENT=	Xen tools within FreeBSD domU

MASTER_SITES=	http://bits.xensource.com/oss-xen/release/${PORTVERSION}/

USE_GMAKE=	yes
USE_PYTHON=	yes

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
	${INSTALL_PROGRAM} ${WRKSRC}/tools/misc/xen-detect ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/xenstore/xenstore ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/xenstore/xenstore-control ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/xenstore/libxenstore.so.3.0 ${PREFIX}/lib

post-install:
	${LN} -sf ${PREFIX}/bin/xenstore ${PREFIX}/bin/xenstore-chmod
	${LN} -sf ${PREFIX}/bin/xenstore ${PREFIX}/bin/xenstore-exists
	${LN} -sf ${PREFIX}/bin/xenstore ${PREFIX}/bin/xenstore-list
	${LN} -sf ${PREFIX}/bin/xenstore ${PREFIX}/bin/xenstore-ls
	${LN} -sf ${PREFIX}/bin/xenstore ${PREFIX}/bin/xenstore-read
	${LN} -sf ${PREFIX}/bin/xenstore ${PREFIX}/bin/xenstore-rm
	${LN} -sf ${PREFIX}/bin/xenstore ${PREFIX}/bin/xenstore-write

.include <bsd.port.mk>
