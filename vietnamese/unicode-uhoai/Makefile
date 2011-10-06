# ex:ts=8
# Ports collection makefile for:  unicode-uhoai
# Date created:			  Tue Nov 27, 2001
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	unicode-uhoai
PORTVERSION=	2.1
PORTREVISION=	2
CATEGORIES=	vietnamese x11-fonts
#MASTER_SITES=	http://www.geocities.com/~starkville/mozilla/
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	obrien
DISTNAME=	uhoaiw21

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	Unicode TrueType Font with UHoai Vietnamese encoding

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	taken care of in do-install target

BUILD_DEPENDS=	ttmkfdir:${PORTSDIR}/x11-fonts/ttmkfdir \
		bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir

do-install:
	@${MKDIR} ${PREFIX}/lib/X11/fonts/TrueType
	${INSTALL_DATA} ${WRKSRC}/uhoaiw21.ttf \
		${PREFIX}/lib/X11/fonts/TrueType
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>

EXTRACT_BEFORE_ARGS+=	-L
