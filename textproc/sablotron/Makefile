# New ports collection makefile for:	sablotron
# Date created:		13 Nov 2000
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Sablot
PORTVERSION=	0.51
CATEGORIES=	textproc
MASTER_SITES=	http://download.gingerall.cz/sablot/

MAINTAINER=	skv@protey.ru

LIB_DEPENDS=	iconv.2:${PORTSDIR}/converters/iconv \
		expat.2:${PORTSDIR}/textproc/expat2

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib
USE_GMAKE=	yes
USE_AUTOCONF=	yes
USE_LIBTOOL=	yes

post-patch:
.if defined(WITH_RUSSIAN)
	@${ECHO_MSG} "Patching for russian support..."
	@cd ${WRKDIR} ; \
	if ${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/rus-patch ; then \
		${ECHO_MSG} ">> Patch applied cleanly." ; \
	else \
		${ECHO_MSG} ">> Patch failed to apply cleanly." ; \
		${FALSE} ; \
	fi
.endif

.include <bsd.port.mk>
