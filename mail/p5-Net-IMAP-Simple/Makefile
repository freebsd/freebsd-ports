# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-IMAP-Simple
PORTVERSION=	1.2210
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for simple IMAP account handling

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-IO-Socket-SSL>0:security/p5-IO-Socket-SSL \
		p5-Net-SSLeay>=0:security/p5-Net-SSLeay \
		p5-Parse-RecDescent>=0:devel/p5-Parse-RecDescent
RUN_DEPENDS:=	${BUILD_DEPENDS}

PORTSCOUT=	skipv:1.20271

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
