# New ports collection makefile for:	ipa_ip6fw
# Date created:				27 December 2005
# Whom:					Andrey Simonenko
#
# $FreeBSD$
#

PORTNAME=	ipa_ip6fw
PORTVERSION=	1.0.2
CATEGORIES=	net
MASTER_SITES=	SF/ipa-system/modules/ipa_ip6fw

MAINTAINER=	simon@comsys.ntu-kpi.kiev.ua
COMMENT=	IPA accounting module for FreeBSD IPv6 Firewall

LICENSE=	BSD

NO_PACKAGE=	Needs to be built uniquely for each host

USE_BZIP2=	yes
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700017
IGNORE=		not supported on your system, as it does not have IPv6 ipfw firewall
.endif

LOCALINCLUDE?=	${LOCALBASE}/include
MAKE_ENV+=	DEBUG_FLAGS="" PREFIX=${PREFIX} LOCALINCLUDE=${LOCALINCLUDE}

BUILD_DEPENDS+=	${LOCALBASE}/include/ipa_mod.h:${PORTSDIR}/sysutils/ipa

PLIST_FILES=	lib/ipa_ip6fw.so

MANCOMPRESSED=	yes
MAN8=		ipa_ip6fw.8
MANLANG=	"" ru.KOI8-R

do-install:
	cd ${WRKSRC} && ${MAKE} install
	cd ${WRKSRC}/man && ${MAKE} LANG_DIR_SRC=ru.KOI8-R clean all install

.include <bsd.port.post.mk>
