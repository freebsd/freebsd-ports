# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
# $FreeBSD$

PORTNAME=	tidyp
PORTVERSION=	1.04
PORTREVISION=	1
CATEGORIES=	textproc www
MASTER_SITES=	http://cloud.github.com/downloads/petdance/tidyp/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library and program to validate and fix HTML

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		libtool

OPTIONS_DEFINE=	ACCESS ASIAN DEBUG UTF16
ACCESS_DESC=	Accessibility checks
ASIAN_DESC=	Asian encodings

PLIST_SUB=	PORTVERSION=${PORTVERSION}

ACCESS_CONFIGURE_ENABLE=access
ASIAN_CONFIGURE_ENABLE=	asian
DEBUG_CONFIGURE_ENABLE=	debug
UTF16_CONFIGURE_ENABLE=	utf16

.include <bsd.port.mk>
