# New ports collection makefile for:	v6eval
# Date created:		Mon Jan  6 23:07:28 GMT 2003
# Whom:			TANAKA Takashi <tanaka@tahi.org>
#
# $FreeBSD$
#

PORTNAME=	v6eval
PORTVERSION=	2.0.2
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.tahi.org/release/v6eval/

MAINTAINER=	tanaka@tahi.org

RUN_DEPENDS=	${SITE_PERL}/Expect.pm:${PORTSDIR}/lang/p5-Expect

USE_PERL5=	yes
USE_OPENSSL=	yes

post-install:
	@${SED} -e 's#@LOCALBASE@#${LOCALBASE}#' ${PKGMESSAGE}

.include <bsd.port.mk>
