# $FreeBSD$

PORTNAME=	Horde_Mail
PORTVERSION=	2.1.2
CATEGORIES=	mail www pear

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Mail Library

USE_HORDE_RUN=	Horde_Exception \
		Horde_Stream_Filter

# Disabled due to circular dependency
#USE_HORDE_RUN+=	Horde_Mime

# Optional but we want it
RUN_DEPENDS+=	${PEARDIR}/Net/SMTP.php:${PORTSDIR}/net/pear-Net_SMTP

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
