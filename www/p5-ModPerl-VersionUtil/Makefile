# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ModPerl-VersionUtil
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Makes it easier to investigate your mod_perl version

BUILD_DEPENDS=	p5-Class-Data-Inheritable>=0.02:${PORTSDIR}/devel/p5-Class-Data-Inheritable
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	configure
USES=		perl5

MAN3=		ModPerl::VersionUtil.3

.include <bsd.port.mk>
