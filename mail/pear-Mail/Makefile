# Ports collection makefile for:  pear-Mail
# Date created:			  26 November 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Mail
PORTVERSION=	1.1.3
CATEGORIES=	mail www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR class that provides multiple interfaces for sending emails

BUILD_DEPENDS=	${PEARDIR}/Net/SMTP.php:${PORTSDIR}/net/pear-Net_SMTP
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		Mail.php Mail/mail.php Mail/null.php Mail/sendmail.php	\
		Mail/smtp.php Mail/RFC822.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
