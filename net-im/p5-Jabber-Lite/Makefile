# New ports collection makefile for:	p5-Jabber-Lite
# Date created:		2007-09-03
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Jabber-Lite
PORTVERSION=	0.8
CATEGORIES=	net-im perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Jabber
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Standalone library for communicating with Jabber servers

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${SITE_PERL}/Authen/SASL.pm:${PORTSDIR}/security/p5-Authen-SASL \
		${SITE_PERL}/IO/Socket/SSL.pm:${PORTSDIR}/security/p5-IO-Socket-SSL

PERL_CONFIGURE=	yes

MAN3=		Jabber::Lite.3

.include <bsd.port.mk>
