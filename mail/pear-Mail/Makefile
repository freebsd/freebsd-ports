# Ports collection makefile for:  pear-Mail
# Date created:			  26 November 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Mail
PORTVERSION=	1.1.2
CATEGORIES=	mail www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR class that provides multiple interfaces for sending emails

BUILD_DEPENDS=	${PEARDIR}/Net/SMTP.php:${PORTSDIR}/net/pear-Net_SMTP
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../devel/pear-PEAR/Makefile.common"

do-install:
	@${CP} -Rp ${WRKSRC}/* ${PEARDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/Mail*
	@${CHMOD} a-x ${PEARDIR}/Mail.php

.include <bsd.port.post.mk>
