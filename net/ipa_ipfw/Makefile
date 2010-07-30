# New ports collection makefile for:	ipa_ipfw
# Date created:				27 December 2005
# Whom:					Andrey Simonenko
#
# $FreeBSD$
#

PORTNAME=	ipa_ipfw
PORTVERSION=	1.0.2
CATEGORIES=	net
MASTER_SITES=	SF/ipa-system/modules/ipa_ipfw

MAINTAINER=	simon@comsys.ntu-kpi.kiev.ua
COMMENT=	IPA accounting module for FreeBSD IP Firewall

LICENSE=	BSD

NO_PACKAGE=	Needs to be built uniquely for each host

USE_BZIP2=	yes
USE_LDCONFIG=	yes

OPTIONS=	DEBUG_INFO "Produce debugging info" off \
		MAN_KOI8_R "Install Russian manual pages" off

.include <bsd.port.pre.mk>

.if !defined(WITH_DEBUG_INFO)
MAKE_ENV+=	DEBUG_FLAGS=""
.endif

BUILD_DEPENDS+=	${LOCALBASE}/include/ipa_mod.h:${PORTSDIR}/sysutils/ipa

PLIST_FILES=	lib/ipa_ipfw.so

MANCOMPRESSED=	yes
MAN8=		ipa_ipfw.8
MANLANG=	""
.if defined(WITH_MAN_KOI8_R)
MANLANG+=	ru.KOI8-R
.endif

do-install:
	cd ${WRKSRC} && ${MAKE} install
.if defined(WITH_MAN_KOI8_R)
	cd ${WRKSRC}/man && ${MAKE} LANG_DIR_SRC=ru.KOI8-R clean all install
.endif

.include <bsd.port.post.mk>
