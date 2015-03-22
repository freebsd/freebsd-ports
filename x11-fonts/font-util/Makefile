# Created by: Pawel Worach
# $FreeBSD$

PORTNAME=	font-util
PORTVERSION=	1.3.0
PORTREVISION=	2
MASTER_SITES=	XORG/individual/font
CATEGORIES=	x11-fonts

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Create an index of X font files in a directory

USES=		pathfix tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-fontrootdir=${PREFIX}/share/fonts

.include <bsd.port.mk>
