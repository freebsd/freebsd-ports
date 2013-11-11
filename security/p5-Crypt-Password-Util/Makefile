# Created by: Henk van Oers <hvo.pm@xs4all.nl>
# $FreeBSD$

PORTNAME=	Crypt-Password-Util
PORTVERSION=	0.09
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Crypt password utilities

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-UUID-Random-Patch-UseMRS>=0:${PORTSDIR}/devel/p5-UUID-Random-Patch-UseMRS
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Sort-Versions>=0:${PORTSDIR}/devel/p5-Sort-Versions

USE_PERL5=	modbuild
USES=		perl5

.include <bsd.port.mk>
