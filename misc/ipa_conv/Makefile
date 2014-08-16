# Created by: Andrey Simonenko
# $FreeBSD$

PORTNAME=	ipa_conv
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	SF/ipa-system/modules/ipa_conv

MAINTAINER=	simon@comsys.ntu-kpi.kiev.ua
COMMENT=	IPA accounting/database module for converting statistics

BUILD_DEPENDS=	${LOCALBASE}/include/ipa_mod.h:${PORTSDIR}/sysutils/ipa

USES=		libtool tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

PLIST_FILES=	lib/ipa_conv.so \
		man/man8/ipa_conv.8.gz \
		man/ru.KOI8-R/man8/ipa_conv.8.gz

.include <bsd.port.mk>
