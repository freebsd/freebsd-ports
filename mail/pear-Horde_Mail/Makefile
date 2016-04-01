# $FreeBSD$

PORTNAME=	Horde_Mail
PORTVERSION=	2.6.3
PORTREVISION=	1
CATEGORIES=	mail www pear

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Mail Library

USES=	horde
USE_HORDE_RUN=	Horde_Exception \
		Horde_Idna \
		Horde_Stream_Filter

# Disabled due to circular dependency
#USE_HORDE_RUN+=	Horde_Mime

# Optional but we want it
RUN_DEPENDS+=	${PEARDIR}/Net/SMTP.php:net/pear-Net_SMTP

.include <bsd.port.mk>
