# Ports collection makefile for:  pear-Mail
# Date created:			  26 November 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Mail
DISTVERSION=	1.2.0
PORTEPOCH=	1
CATEGORIES=	mail www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR class that provides multiple interfaces for sending emails

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		Mail.php Mail/mail.php Mail/null.php Mail/sendmail.php	\
		Mail/smtp.php Mail/RFC822.php
TESTS=		rfc822.phpt smtp_error.phpt

LATEST_LINK=	pear-${PORTNAME}
OPTIONS=	PEAR_NET_SMTP "PEAR::Net_SMTP support" off

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_NET_SMTP)
RUN_DEPENDS+=	${PEARDIR}/Net/SMTP.php:${PORTSDIR}/net/pear-Net_SMTP
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
