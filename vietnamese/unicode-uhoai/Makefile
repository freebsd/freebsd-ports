# ex:ts=8
# Ports collection makefile for:  unicode-uhoai
# Date created:			  Tue Nov 27, 2001
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	unicode-uhoai
PORTVERSION=	2.1
CATEGORIES=	vietnamese x11-fonts
MASTER_SITES=	http://www.geocities.com/~starkville/mozilla/
DISTNAME=	uhoaiw21

MAINTAINER=	obrien@FreeBSD.org

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes
NO_BUILD=	taken care of in do-install target

.include <bsd.port.pre.mk>

BUILD_DEPENDS=	ttmkfdir:${PORTSDIR}/x11-fonts/ttmkfdir
.if ${XFREE86_VERSION} == 4
BUILD_DEPENDS+=	bdftopcf:${PORTSDIR}/x11/XFree86-4-clients
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
.endif

do-install:
	@${MKDIR} ${PREFIX}/lib/X11/fonts/TrueType
	${INSTALL_DATA} ${WRKSRC}/uhoaiw21.ttf \
		${PREFIX}/lib/X11/fonts/TrueType
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>

EXTRACT_BEFORE_ARGS+=	-L
