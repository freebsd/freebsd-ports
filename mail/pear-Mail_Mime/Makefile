# Ports collection makefile for:  pear-Mail_Mime
# Date created:			  24 October 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Mail_Mime
PORTVERSION=	1.2.1
PORTREVISION=	4
CATEGORIES=	mail www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR classes to create and decode MIME messages

BUILD_DEPENDS=	${PEARDIR}/Mail/mail.php:${PORTSDIR}/mail/pear-Mail
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Mail
FILES=		mime.php mimeDecode.php mimePart.php xmail.dtd xmail.xsl

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
