# New ports collection makefile for:    xdvi
# Date created:         1 October 1994
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	xdvi
PORTVERSION=	pl20
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications
DISTNAME=	${PORTNAME}-20
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jmz@FreeBSD.org

DIST_SUBDIR=	xdvi	# to share distfiles with japanese/xdvi
USE_IMAKE=	yes
USE_GMAKE=	yes
XMKMF=		xmkmf
.if defined(PACKAGE_BUILDING)
SCRIPTS_ENV=	PACKAGE_BUILDING=${PACKAGE_BUILDING}
.else
IS_INTERACTIVE=	yes
.endif

MAN1=		xdvi.1

do-install:
	@${MKDIR} ${PREFIX}/man/man1
	@${MKDIR} ${PREFIX}/bin
	@(cd ${WRKSRC}; ${GMAKE} install.man \
		MANDIR=${PREFIX}/man/man1 MANSUFFIX=1)
	@(cd ${WRKSRC}; ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} xdvi.man)
	@(cd ${WRKSRC}; ${GMAKE} -f Makefile install BINDIR=${PREFIX}/bin)
	@(cd ${WRKSRC}; ${INSTALL_SCRIPT} MakeTeXPK ${PREFIX}/bin)

post-install:
	@if [ -f ${WRKDIR}/post-install ]; then sh ${WRKDIR}/post-install; fi

.include <bsd.port.mk>
