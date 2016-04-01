# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Authen-Simple-PAM
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple PAM authentication

BUILD_DEPENDS=	p5-Authen-Simple>=0:security/p5-Authen-Simple \
		p5-Authen-PAM>=0:security/p5-Authen-PAM
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
