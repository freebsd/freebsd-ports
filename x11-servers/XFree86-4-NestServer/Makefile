# New ports collection makefile for:	XFree86-NestServer
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	NestServer
PORTVERSION=	4.2.0
CATEGORIES=	x11-servers
MASTER_SITES=	${MASTER_SITE_XFREE:S/$/:x/} \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=	${PORTVERSION}/:x \
			anholt/:local
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X${PORTVERSION:S/.//g}src-1.tgz:x Wraphelp.gz:local
EXTRACT_ONLY=	X${PORTVERSION:S/.//g}src-1.tgz

MAINTAINER=	anholt@freebsd.org

XFREE86_VERSION=	4
USE_IMAKE=		YES
DIST_SUBDIR=		xc
WRKSRC=			${WRKDIR}/xc
PATCHDIR=		${.CURDIR}/../../x11/XFree86-4-libraries/files
MAKE_ENV=		MAN_INSTALL_TARGET=installXnest.man
ALL_TARGET=		FreeBSDPortsBuild
INSTALL_TARGET=		installXnest installXserver.man
MANCOMPRESSED=		yes
MAN1=			Xnest.1 Xserver.1

post-extract:
	${GUNZIP_CMD} -c ${DISTDIR}/${DIST_SUBDIR}/Wraphelp.gz > \
		${WRKSRC}/lib/Xdmcp/Wraphelp.c

do-configure:
	cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure
	@cd ${WRKSRC}; ${MAKE} FreeBSDPortsConfigure

.include <bsd.port.mk>
