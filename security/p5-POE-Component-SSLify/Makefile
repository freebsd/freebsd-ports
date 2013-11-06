# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	POE-Component-SSLify
PORTVERSION=	1.008
CATEGORIES=	security perl5
MASTER_SITES=	CPAN/${PORTNAME:C/-.*//}/APOCAL
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Integrate SSL into POE

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Net-SSLeay>=1.36:${PORTSDIR}/security/p5-Net-SSLeay \
		p5-POE>=1.267:${PORTSDIR}/devel/p5-POE \
		p5-Task-Weaken>=1.03:${PORTSDIR}/devel/p5-Task-Weaken
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
