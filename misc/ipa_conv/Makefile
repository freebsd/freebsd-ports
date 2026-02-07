PORTNAME=	ipa_conv
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	SF/ipa-system/modules/ipa_conv

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IPA accounting/database module for converting statistics
WWW=		https://ipa-system.sourceforge.net/modules/ipa_conv/

BUILD_DEPENDS=	${LOCALBASE}/include/ipa_mod.h:sysutils/ipa

USES=		libtool tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
INSTALL_TARGET=	install-strip

PLIST_FILES=	lib/ipa_conv.so \
		share/man/man8/ipa_conv.8.gz \
		share/man/ru.KOI8-R/man8/ipa_conv.8.gz

.include <bsd.port.mk>
