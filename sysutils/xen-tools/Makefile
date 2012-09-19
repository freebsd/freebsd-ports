# New ports collection makefile for:    xen-tools
# Date created:                         13 December 2011
# Whom:                                 Evan Sarmiento <esarmiento@wayfair.com>
#
# $FreeBSD$

PORTNAME=	xen-tools
PORTVERSION=	4.1.3
PORTREVISION=	2
CATEGORIES=	sysutils
DISTNAME=	xen-${PORTVERSION}

MAINTAINER=	feld@feld.me
COMMENT=	Xen tools within FreeBSD domU

MASTER_SITES=	http://bits.xensource.com/oss-xen/release/${PORTVERSION}/:xensource \
		https://github.com/${GIT_ACCOUNT}/${GIT_PROJECT}/tarball/${GIT_VERSION}/:github
DISTFILES=	xen-${PORTVERSION}.tar.gz:xensource \
		${GIT_ACCOUNT}-${GIT_PROJECT}-${GIT_VERSION}.tar.gz:github

FETCH_ARGS=	-pRr
GIT_ACCOUNT=	felderado
GIT_PROJECT=	freebsd-xen-tools-scripts
GIT_VERSION=	bfb06da
GITSRC=		${WRKDIR}/${GIT_ACCOUNT}-${GIT_PROJECT}-${GIT_VERSION}/src/

USE_GMAKE=	yes
USE_PYTHON=	yes
USE_RC_SUBR=	xe-daemon

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
		bin/xenstore-write \
		sbin/xe-daemon \
		sbin/xe-update-guest-attrs \
		sbin/xe_wrapper

do-build:
	cd ${WRKSRC}/tools && ${GMAKE} -C include
	cd ${WRKSRC}/tools/misc && ${GMAKE} xen-detect
	cd ${WRKSRC}/tools/xenstore && ${GMAKE} clients

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tools/misc/xen-detect ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/xenstore/xenstore ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/xenstore/xenstore-control ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/xenstore/libxenstore.so.3.0 ${PREFIX}/lib
	${INSTALL_SCRIPT} ${GITSRC}/usr/local/sbin/xe-daemon ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${GITSRC}/usr/local/sbin/xe-update-guest-attrs ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${FILESDIR}/xe_wrapper ${PREFIX}/sbin

post-install:
	${LN} -sf ${PREFIX}/bin/xenstore ${PREFIX}/bin/xenstore-chmod
	${LN} -sf ${PREFIX}/bin/xenstore ${PREFIX}/bin/xenstore-exists
	${LN} -sf ${PREFIX}/bin/xenstore ${PREFIX}/bin/xenstore-list
	${LN} -sf ${PREFIX}/bin/xenstore ${PREFIX}/bin/xenstore-ls
	${LN} -sf ${PREFIX}/bin/xenstore ${PREFIX}/bin/xenstore-read
	${LN} -sf ${PREFIX}/bin/xenstore ${PREFIX}/bin/xenstore-rm
	${LN} -sf ${PREFIX}/bin/xenstore ${PREFIX}/bin/xenstore-write

.include <bsd.port.mk>
