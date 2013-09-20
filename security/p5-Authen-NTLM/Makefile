# Created by: James Thomason <james@divide.org>
# $FreeBSD$

PORTNAME=	Authen-NTLM
PORTVERSION=	1.09
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME:C/.*-//}-${PORTVERSION}

MAINTAINER=	james@divide.org
COMMENT=	An NTLM authentication module

BUILD_DEPENDS=	p5-Digest-HMAC>=0:${PORTSDIR}/security/p5-Digest-HMAC
RUN_DEPENDS=	p5-Digest-HMAC>=0:${PORTSDIR}/security/p5-Digest-HMAC

USES=		perl5
USE_PERL5=	configure

MAN3=		Authen::NTLM.3

NO_STAGE=	yes
.include <bsd.port.mk>
