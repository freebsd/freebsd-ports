# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Authen-Simple-LDAP
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple LDAP authentication

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Authen-Simple>=0:security/p5-Authen-Simple \
		p5-perl-ldap>=0:net/p5-perl-ldap
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
