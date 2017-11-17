# $FreeBSD$

PORTNAME=	font-awesome
DISTVERSION=	4.7.0
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://fontawesome.io/assets/

MAINTAINER=	dg@syrec.org
COMMENT=	Suite of 675 pictographic icons from Font Awesome

LICENSE=	OFL11

USES=		fonts zip
NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

PLIST_FILES=	${FONTSDIR}/fontawesome-webfont.ttf \
		${FONTSDIR}/FontAwesome.otf

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/*.[t,o]tf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
