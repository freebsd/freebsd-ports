# New ports collection makefile for:   p5-Authen-NTLM
# Date created:                        June 07 2006
# Whom:                                James Thomason <james@divide.org>
#
#
# $FreeBSD$

PORTNAME=	NTLM
PORTVERSION=	1.05
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Authen
PKGNAMEPREFIX=	p5-

MAINTAINER=	james@divide.org
COMMENT=	An NTLM authentication module

RUN_DEPENDS=	p5-Digest-HMAC>=0:${PORTSDIR}/security/p5-Digest-HMAC

PERL_CONFIGURE=	yes

MAN3=	Authen::NTLM.3

.include <bsd.port.mk>
