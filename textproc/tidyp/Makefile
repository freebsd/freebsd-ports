# New ports collection makefile for:	tidyp
# Date created:		2010-05-14
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
#
# $FreeBSD$
#

PORTNAME=	tidyp
PORTVERSION=	1.04
CATEGORIES=	textproc www
MASTER_SITES=	http://cloud.github.com/downloads/petdance/tidyp/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A library and program to validate and fix HTML

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS=	ACCESS	"Support Accessibility checks" off \
		ASIAN	"Support Asian encoding" off \
		DEBUG	"Enable debugging" off \
		UTF16	"Support UTF-16 encoding" off

PLIST_FILES=	bin/${PORTNAME} \
		include/${PORTNAME}/buffio.h \
		include/${PORTNAME}/platform.h \
		include/${PORTNAME}/tidyp.h \
		include/${PORTNAME}/tidypenum.h \
		lib/lib${PORTNAME}-${PORTVERSION}.so \
		lib/lib${PORTNAME}-${PORTVERSION}.so.0 \
		lib/lib${PORTNAME}.a \
		lib/lib${PORTNAME}.la \
		lib/lib${PORTNAME}.so
PLIST_DIRS=	include/${PORTNAME}

.include <bsd.port.options.mk>

.if defined(WITH_ACCESS)
CONFIGURE_ARGS+=--enable-access
.endif

.if defined(WITH_ASIAN)
CONFIGURE_ARGS+=--enable-asian
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--enable-debug
.endif

.if defined(WITH_UTF16)
CONFIGURE_ARGS+=--enable-utf16
.endif

.include <bsd.port.mk>
