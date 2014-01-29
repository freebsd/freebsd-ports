# Created by: mj <systemoperator@gmail.com>
# $FreeBSD$

PORTNAME=	kojoney
PORTVERSION=	0.0.4.2
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	systemoperator@gmail.com
COMMENT=	A low level interaction honeypot that emulates an SSH server

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.interface>=3.3.0_1:${PORTSDIR}/devel/py-zope.interface \
		${PYTHONPREFIX_SITELIBDIR}/Crypto:${PORTSDIR}/security/py-pycrypto \
		p5-IP-Country>=0:${PORTSDIR}/net/p5-IP-Country

WRKSRC=		${WRKDIR}/kojoney

USE_PYTHON=	yes
USE_OPENSSL=	yes
USES=		perl5 twisted:conch
USE_PERL5=	run

NO_STAGE=	yes
.include <bsd.port.mk>
