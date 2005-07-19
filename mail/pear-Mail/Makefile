# Ports collection makefile for:  pear-Mail
# Date created:			  26 November 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Mail
PORTVERSION=	1.1.6
CATEGORIES=	mail www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR class that provides multiple interfaces for sending emails

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		Mail.php Mail/mail.php Mail/null.php Mail/sendmail.php	\
		Mail/smtp.php Mail/RFC822.php
TESTS=		rfc822.phpt

LATEST_LINK=	pear-${PORTNAME}
OPTIONS=	PEAR_NET_SMTP "PEAR::Net_SMTP support" off

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_NET_SMTP)
RUN_DEPENDS+=	${PEARDIR}/Net/SMTP.php:${PORTSDIR}/net/pear-Net_SMTP
.endif

.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
