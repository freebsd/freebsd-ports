# Ports collection makefile for:  pear-Mail_Mime
# Date created:			  24 October 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Mail_Mime
PORTVERSION=	1.2.1
PORTREVISION=	3
CATEGORIES=	mail www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR classes to create and decode MIME messages

BUILD_DEPENDS=	${PEARDIR}/Mail/mail.php:${PORTSDIR}/mail/pear-Mail
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../devel/pear-PEAR/Makefile.common"

do-install:
	@${CP} -Rp ${WRKSRC}/* ${PEARDIR}/Mail
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/Mail/*
.for BUGMODE in mimeDecode.php mimePart.php xmail.dtd xmail.xsl
	@${CHMOD} a-x ${PEARDIR}/Mail/${BUGMODE}
.endfor

.include <bsd.port.post.mk>
