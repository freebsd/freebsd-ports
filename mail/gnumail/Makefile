PORTNAME=	gnumail
DISTVERSION=	1.4.0
PORTREVISION=	3
CATEGORIES=	mail gnustep
MASTER_SITES=	SAVANNAH/gnustep-nonfsf/
DISTNAME=	GNUMail-${DISTVERSION}

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	GNUstep mail client
WWW=		https://www.nongnu.org/gnustep-nonfsf/gnumail/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/Documentation/COPYING

LIB_DEPENDS=	libAddresses.so:mail/addresses \
		libPantomime.so:mail/pantomime

USES=		cpe gnustep
CPE_VENDOR=	gnu
USE_GNUSTEP=	back base build gui
USE_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/GNUMail.app/GNUMail
.for i in Account Advanced Colors Compose Emoticon Filtering Fonts Import MIME PGP Receiving Sending Viewing
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GNUMail/${i}.*/${i}
.endfor
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Library/Frameworks/GNUMail.framework/Versions/${DISTVERSION:R:R}/libGNUMail.so.${DISTVERSION}

.include <bsd.port.mk>
