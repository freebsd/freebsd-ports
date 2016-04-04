# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Mail-Tools
PORTVERSION=	2.14
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	MailTools-${PORTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl5 modules for dealing with Internet e-mail messages

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-TimeDate>=0:devel/p5-TimeDate
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	YES

#pre-install: test

.include <bsd.port.mk>
