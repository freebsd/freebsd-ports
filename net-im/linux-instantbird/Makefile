# $FreeBSD$

PORTNAME=	instantbird
DISTVERSION=	1.5
DISTVERSIONSUFFIX=.${LOCALE}.linux-i686
PORTREVISION=	1
CATEGORIES=	net-im irc ipv6
MASTER_SITES=	http://ftp.instantbird.com/instantbird/releases/${DISTVERSION}/ \
		GOOGLE_CODE

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Instant Messaging client based on XULRunner and libpurple

BROKEN=		Unfetchable (google code has gone away)

USES=		tar:bzip2
USE_LINUX=	libxml2 #avahiglib avahilibs

ALL_LOCALES=	cs de en-US es-ES et fr nl pl pt-BR ru sk sv-SE uk
LOCALE=		${${PORT_OPTIONS:MLANG_*}}
PLIST_SUB=	LOCALE="${LOCALE}"
EXTRACT_AFTER_ARGS=--exclude '*/searchplugins'

OPTIONS_DEFAULT=LANG_US
OPTIONS_SINGLE=	L10N

L10N_DESC?= 	Localization

.for l in ${ALL_LOCALES}
OPTIONS_SINGLE_L10N+=LANG_${l:tu:C/.*-//}
LANG_${l:tu:C/.*-//}= ${l}
. if defined(PACKAGE_BUILDING)
DISTFILES+=	${DISTNAME:S/${LOCALE}/${l}/}${EXTRACT_SUFX}
. endif
.endfor

.include "${.CURDIR}/../../www/linux-seamonkey/Makefile.common"
.include <bsd.port.mk>
