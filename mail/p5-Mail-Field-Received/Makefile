# New ports collection makefile for:	p5-Mail-Field-Received
# Date created:				July 12 2004
# Whom:	      				Andrea Venturoli <freebsd@netfence.it>
#
# $FreeBSD$
#

PORTNAME=	Mail-Field-Received
PORTVERSION=	0.26
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Perl5 modules for parsing of `Received' headers in e-mails

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Mail-Tools>0:${PORTSDIR}/mail/p5-Mail-Tools
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Differences>0:${PORTSDIR}/devel/p5-Test-Differences

USES=		perl5
USE_PERL5=	configure

MAN3=		Mail::Field::Received.3

.include <bsd.port.mk>
