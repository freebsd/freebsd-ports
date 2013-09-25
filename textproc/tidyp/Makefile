# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
# $FreeBSD$

PORTNAME=	tidyp
PORTVERSION=	1.04
CATEGORIES=	textproc www
MASTER_SITES=	http://cloud.github.com/downloads/petdance/tidyp/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library and program to validate and fix HTML

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	ACCESS ASIAN DEBUG UTF16
ACCESS_DESC=	Accessibility checks
ASIAN_DESC=	Asian encodings

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

.if ${PORT_OPTIONS:MACCESS}
CONFIGURE_ARGS+=--enable-access
.endif

.if ${PORT_OPTIONS:MASIAN}
CONFIGURE_ARGS+=--enable-asian
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--enable-debug
.endif

.if ${PORT_OPTIONS:MUTF16}
CONFIGURE_ARGS+=--enable-utf16
.endif

.include <bsd.port.mk>
