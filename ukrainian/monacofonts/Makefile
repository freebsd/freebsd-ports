# Created by: mi@aldan.algebra.com
# $FreeBSD$

PORTNAME=	monaco
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	ukrainian x11-fonts
MASTER_SITES=	http://www.brama.com/compute/unix/
PKGNAMEPREFIX=	koi8-u-
PKGNAMESUFFIX=	-x11
DISTNAME=	${PORTNAME}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	A collection of 5 "fixed" fonts for X11 from www.brama.com

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

USES=		zip

WRKSRC=		${WRKDIR}/Monaco.bdf

MAKEFILE=	${FILESDIR}/Makefile
MAKE_ENV+=	INSTALL_DATA="${INSTALL_DATA}" MKDIR="${MKDIR}"
MAKE_ARGS+=	-j 2

NO_STAGE=	yes
post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
