PORTNAME=	Horde_Mail
PORTVERSION=	2.6.6
CATEGORIES=	mail www pear

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Mail Library
WWW=		https://pear.horde.org

LICENSE=	BSD2CLAUSE

# Optional but we want it
RUN_DEPENDS+=	${PEARDIR}/Net/SMTP.php:net/pear-Net_SMTP@${PHP_FLAVOR}

USES=	horde cpe
USE_HORDE_RUN=	Horde_Exception \
		Horde_Idna \
		Horde_Stream_Filter

# Disabled due to circular dependency
#USE_HORDE_RUN+=	Horde_Mime

NO_ARCH=	yes

.include <bsd.port.mk>
