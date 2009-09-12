# New ports collection makefile for:	ipa_conv
# Date created:				28 July 2009
# Whom:					Andrey Simonenko
#
# $FreeBSD$
#

PORTNAME=	ipa_conv
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	http://ipa-system.sourceforge.net/modules/ipa_conv/ \
		LOCAL/avl

MAINTAINER=	simon@comsys.ntu-kpi.kiev.ua
COMMENT=	IPA accounting/database module for converting statistics

BUILD_DEPENDS=	${LOCALBASE}/include/ipa_mod.h:${PORTSDIR}/sysutils/ipa

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PLIST_FILES=	lib/ipa_conv.la lib/ipa_conv.so

MAN8=		ipa_conv.8
MANLANG=	"" ru.KOI8-R

.include <bsd.port.mk>
