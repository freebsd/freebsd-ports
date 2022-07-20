PORTNAME=	gnumail
PORTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	mail gnustep
MASTER_SITES=	SAVANNAH/gnustep-nonfsf/
DISTNAME=	GNUMail-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNUstep mail client

LICENSE=	GPLv2

BROKEN=		does not link: Framework/GNUMail/GNUMail.framework/Versions/Current/./libGNUMail.so: undefined reference to __objc_ivar_offset_NSWindow._delegate.

LIB_DEPENDS=	libPantomime.so:mail/pantomime \
		libAddresses.so:mail/addresses

USES=		cpe gnustep

CPE_VENDOR=	gnu
USE_GNUSTEP=	back build gui base
USE_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

.include <bsd.port.mk>
