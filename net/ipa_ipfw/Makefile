# Created by: Andrey Simonenko
# $FreeBSD$

PORTNAME=	ipa_ipfw
PORTVERSION=	1.1
CATEGORIES=	net
MASTER_SITES=	SF/ipa-system/modules/ipa_ipfw

MAINTAINER=	simon@comsys.ntu-kpi.kiev.ua
COMMENT=	IPA accounting module for FreeBSD IP Firewall

LICENSE=	BSD

NO_PACKAGE=	Needs to be built uniquely for each host

USE_BZIP2=	yes
USE_LDCONFIG=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

LOCALINCLUDE?=	${LOCALBASE}/include
MAKE_ENV+=	DEBUG_FLAGS="" PREFIX=${PREFIX} LOCALINCLUDE=${LOCALINCLUDE}
MAKE_ENV+=	NO_WCAST_ALIGN.clang=yes

BUILD_DEPENDS+=	${LOCALBASE}/include/ipa_mod.h:${PORTSDIR}/sysutils/ipa

PLIST_FILES=	lib/ipa_ipfw.so

MANCOMPRESSED=	yes
MAN8=		ipa_ipfw.8
MANLANG=	"" ru.KOI8-R

do-install:
	cd ${WRKSRC} && ${MAKE} install
	cd ${WRKSRC}/man && ${MAKE} LANG_DIR_SRC=ru.KOI8-R clean all install

.include <bsd.port.post.mk>
