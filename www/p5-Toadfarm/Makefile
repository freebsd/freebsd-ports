# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Toadfarm
PORTVERSION=	0.60
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JHTHORSEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	One Mojolicious app to rule them all

LICENSE=	ART20

BUILD_DEPENDS=	p5-File-Which>=1.00:${PORTSDIR}/sysutils/p5-File-Which \
		p5-Mojolicious>=5.00:${PORTSDIR}/www/p5-Mojolicious
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
