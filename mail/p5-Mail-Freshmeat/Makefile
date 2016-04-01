# Created by: will
# $FreeBSD$

PORTNAME=	Mail-Freshmeat
PORTVERSION=	1.20
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:FOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to parse daily newsletters from freshmeat.net

BUILD_DEPENDS=	p5-Mail-Tools>=0:mail/p5-Mail-Tools
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
