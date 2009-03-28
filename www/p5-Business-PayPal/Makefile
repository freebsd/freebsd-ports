# New ports collection makefile for:	p5-Business-PayPal
# Date created:				Fri 29 Sep 2006
# Whom:					Steven Kreuzer
#
# $FreeBSD$
#

PORTNAME=	Business-PayPal
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Perl extension for automating PayPal transactions

BUILD_DEPENDS=	p5-Net-SSLeay>=1.35:${PORTSDIR}/security/p5-Net-SSLeay \
		p5-Digest-MD5>=2.38:${PORTSDIR}/security/p5-Digest-MD5 \
		p5-CGI.pm>=3.42:${PORTSDIR}/www/p5-CGI.pm
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Business::PayPal.3

.include <bsd.port.mk>
