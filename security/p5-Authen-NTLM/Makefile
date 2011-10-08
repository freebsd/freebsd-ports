# New ports collection makefile for:   p5-Authen-NTLM
# Date created:                        June 07 2006
# Whom:                                James Thomason <james@divide.org>
#
#
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

PERL_CONFIGURE=	yes

MAN3=		Authen::NTLM.3

.include <bsd.port.mk>
