# Created by: Olivier Girard <Olivier.Girard@univ-angers.fr>
# $FreeBSD$

PORTNAME=	MIME-EncWords
PORTVERSION=	1.014.3
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	Olivier.Girard@univ-angers.fr
COMMENT=	Deal with RFC 2047 encoded words (improved)

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-MIME-Charset>=1.010.1:mail/p5-MIME-Charset
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
