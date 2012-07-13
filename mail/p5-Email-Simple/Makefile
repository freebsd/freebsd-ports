# New ports collection makefile for:	p5-Email-Simple
# Date created:				August 31 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	Email-Simple
PORTVERSION=	2.102
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple parsing of RFC2822 message format and headers

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Email-Date-Format>=0:${PORTSDIR}/mail/p5-Email-Date-Format
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Email::Simple.3 \
		Email::Simple::Creator.3 \
		Email::Simple::Header.3

.include <bsd.port.mk>
