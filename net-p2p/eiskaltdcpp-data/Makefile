# New ports collection makefile for: net-p2p/eiskaltdc
# Date created:		28 Aug 2009
# Whom:			Stas Timokhin <stast@bsdportal.ru>
#
# $FreeBSD$
#

PORTNAME=	eiskaltdcpp-data
PORTVERSION=	2.1.1
CATEGORIES=	net-p2p
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	eiskaltdcpp-${DISTVERSION}

MAINTAINER=	gelraen.ua@gmail.com
COMMENT=	Shared data for EiskaltDC++ GUIs

PROJECTHOST=	eiskaltdc

USE_BZIP2=	yes
NO_BUILD=	yes

OPTIONS=	EMOTICONS	"Install emoticons"	on \
		EXAMPLES	"Install script examples"	on \
		LUASCRIPTS	"Install lua script examples"	off \
		SOUNDS	"Install sound files"	on

.include <bsd.port.options.mk>

DATA_DIR=	${PREFIX}/share/eiskaltdcpp

.if defined(WITH_EMOTICONS)
PLIST_SUB+=	EMOTICONS=""
.else
PLIST_SUB+=	EMOTICONS="@comment "
.endif

.if defined(WITH_EXAMPLES)
PLIST_SUB+=	EXAMPLES=""
.else
PLIST_SUB+=	EXAMPLES="@comment "
.endif

.if defined(WITH_LUASCRIPTS)
PLIST_SUB+=	LUASCRIPTS=""
.else
PLIST_SUB+=	LUASCRIPTS="@comment "
.endif

.if defined(WITH_SOUNDS)
PLIST_SUB+=	SOUNDS=""
.else
PLIST_SUB+=	SOUNDS="@comment "
.endif

do-install:
	${MKDIR} ${DATA_DIR}
	${TOUCH} ${DATA_DIR}/keep_me
.if defined(WITH_EMOTICONS)
	${CP} -rv ${WRKSRC}/emoticons ${DATA_DIR}
.endif
.if defined(WITH_EXAMPLES)
	${MKDIR} ${DATA_DIR}/examples
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${DATA_DIR}/examples
.endif
.if defined(WITH_LUASCRIPTS)
	${CP} -rv ${WRKSRC}/luascripts ${DATA_DIR}
.endif
.if defined(WITH_SOUNDS)
	${CP} -rv ${WRKSRC}/sounds ${DATA_DIR}
.endif

.include <bsd.port.mk>
