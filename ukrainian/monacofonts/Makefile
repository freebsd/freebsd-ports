PORTNAME=	monaco
PORTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	ukrainian x11-fonts
MASTER_SITES=	http://www.brama.com/compute/unix/
PKGNAMEPREFIX=	koi8-u-
PKGNAMESUFFIX=	-x11
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@virtual-estates.net
COMMENT=	Collection of 5 "fixed" fonts for X11 from www.brama.com
WWW=		http://www.brama.com/compute/unix.html

BUILD_DEPENDS=	bdftopcf:x11-fonts/bdftopcf \
		mkfontscale:x11-fonts/mkfontscale

USES=		fonts zip

WRKSRC=		${WRKDIR}/Monaco.bdf
FONTNAME=	koi8-u-monaco

MAKEFILE=	${FILESDIR}/Makefile
MAKE_ENV+=	INSTALL_DATA="${INSTALL_DATA}" MKDIR="${MKDIR}"
MAKE_ENV+=	FONTSDIR="${FONTSDIR}"

.include <bsd.port.mk>
