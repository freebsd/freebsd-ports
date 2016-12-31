# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Mojolicious-Plugin-SetUserGroup
PORTVERSION=	0.005
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DBOOK
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Mojolicious plugin to set unprivileged credentials

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Mojolicious>=6.0:www/p5-Mojolicious \
		p5-Unix-Groups>=0:devel/p5-Unix-Groups
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuildtiny

.include <bsd.port.mk>
