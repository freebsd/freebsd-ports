# Ports collection makefile for:  pear-Mail
# Date created:			  26 November 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Mail
PORTVERSION=	1.1.14
CATEGORIES=	mail www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR class that provides multiple interfaces for sending emails

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		Mail.php Mail/mail.php Mail/null.php Mail/sendmail.php	\
		Mail/smtp.php Mail/RFC822.php
TESTS=		rfc822.phpt smtp_error.phpt

PORTSCOUT=	skipv:1.2.0b1,1.2.0a1,1.2.0a2

LATEST_LINK=	pear-${PORTNAME}
OPTIONS=	PEAR_NET_SMTP "PEAR::Net_SMTP support" off

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_NET_SMTP)
RUN_DEPENDS+=	${PEARDIR}/Net/SMTP.php:${PORTSDIR}/net/pear-Net_SMTP
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
