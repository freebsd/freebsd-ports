# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Toadfarm
PORTVERSION=	0.74
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JHTHORSEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	One Mojolicious app to rule them all

LICENSE=	ART20

BUILD_DEPENDS=	p5-File-Which>=1.00:sysutils/p5-File-Which \
		p5-Mojolicious>=5.00:www/p5-Mojolicious
RUN_DEPENDS:=	${BUILD_DEPENDS}

PORTSCOUT=	skipv:0.0801,0.1001,0.1301,0.1601,0.1701,0.2601,0.2602,0.4301

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
