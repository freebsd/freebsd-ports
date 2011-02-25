# Ports collection makefile for:	kojoney
# Date created:				5 December 2006
# Whom:					mj <systemoperator@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	kojoney
PORTVERSION=	0.0.4.1
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/Kojoney%20New%20Way/Kojoney%20${PORTVERSION}

MAINTAINER=	systemoperator@gmail.com
COMMENT=	A low level interaction honeypot that emulates an SSH server

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zopeInterface>=3.3.0_1:${PORTSDIR}/devel/py-zopeInterface \
		${PYTHONPREFIX_SITELIBDIR}/Crypto:${PORTSDIR}/security/py-pycrypto \
		${SITE_PERL}/IP/Country.pm:${PORTSDIR}/net/p5-IP-Country

WRKSRC=		${WRKDIR}/kojoney

USE_PYTHON=	2.5+
USE_TWISTED=	conch
USE_OPENSSL=	yes
USE_PERL5_RUN=	yes

.include <bsd.port.mk>
