# New ports collection makefile for:	www/p5-Catalyst-Plugin-Email
# Date created:				29 Mar 2009
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Email
PORTVERSION=	0.08
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Send emails with Catalyst

RUN_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Email-Send>=0:${PORTSDIR}/mail/p5-Email-Send \
		p5-Email-MIME>=0:${PORTSDIR}/mail/p5-Email-MIME \
		p5-Email-MIME-Creator>=0:${PORTSDIR}/mail/p5-Email-MIME-Creator
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN3=	Catalyst::Plugin::Email.3

.include <bsd.port.mk>
