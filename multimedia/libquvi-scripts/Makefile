# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libquvi-scripts
PORTVERSION=	0.4.21
CATEGORIES=	multimedia devel
MASTER_SITES=	SF/quvi/${PORTVERSION:R}/${PORTNAME}/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Embedded lua scripts for libquvi and utility scripts

LICENSE=	LGPL21+
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING

PORTSCOUT=	limit:^0\.4\.

OPTIONS_DEFINE=	NSFW
OPTIONS_SUB=	yes
NSFW_DESC=	Enable adult website support

GNU_CONFIGURE=	yes
NO_ARCH=	yes
USES=		pathfix tar:xz

NSFW_CONFIGURE_WITH=	nsfw

.include <bsd.port.mk>
