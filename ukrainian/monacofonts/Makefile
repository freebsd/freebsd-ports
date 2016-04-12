# Created by: mi@aldan.algebra.com
# $FreeBSD$

PORTNAME=	monaco
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	ukrainian x11-fonts
MASTER_SITES=	http://www.brama.com/compute/unix/
PKGNAMEPREFIX=	koi8-u-
PKGNAMESUFFIX=	-x11
DISTNAME=	${PORTNAME}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Collection of 5 "fixed" fonts for X11 from www.brama.com

BUILD_DEPENDS=	bdftopcf:x11-fonts/bdftopcf \
		mkfontdir:x11-fonts/mkfontdir \
		mkfontscale:x11-fonts/mkfontscale

USES=		fonts zip

WRKSRC=		${WRKDIR}/Monaco.bdf
FONTNAME=	koi8-u-monaco

MAKEFILE=	${FILESDIR}/Makefile
MAKE_ENV+=	INSTALL_DATA="${INSTALL_DATA}" MKDIR="${MKDIR}"
MAKE_ENV+=	FONTSDIR="${FONTSDIR}"

.include <bsd.port.mk>
