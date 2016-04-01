# Created by: TAKAHASHI Kaoru <kaoru@kaisei.org>
# $FreeBSD$

PORTNAME=	Mail-IMAPClient
PORTVERSION=	3.38
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PLOBBES
PKGNAMEPREFIX=	p5-

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Perl5 module to talk to a IMAP4rev1 (RFC2060) server

LICENSE=	ARTPERL10

RUN_DEPENDS=	p5-Digest-HMAC>=0:security/p5-Digest-HMAC \
		p5-Parse-RecDescent>=1.94:devel/p5-Parse-RecDescent \
		p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL \
		p5-Authen-SASL>=0:security/p5-Authen-SASL

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	</dev/null

.include <bsd.port.mk>
