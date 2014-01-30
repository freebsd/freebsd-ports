# Created by: Dereckson <dereckson@gmail.com>
# $FreeBSD$

PORTNAME=	Crypt-Random-Source
PORTVERSION=	0.07
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	dereckson@gmail.com
COMMENT=	Get weak or strong random data from pluggable sources

LICENSE=	ART20

BUILD_DEPENDS=	p5-Any-Moose>=0.11:${PORTSDIR}/devel/p5-Any-Moose \
		p5-Capture-Tiny>=0.08:${PORTSDIR}/devel/p5-Capture-Tiny \
		p5-Module-Find>=0:${PORTSDIR}/devel/p5-Module-Find \
		p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-namespace-clean>=0.08:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-use-ok>0:${PORTSDIR}/devel/p5-Test-use-ok

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
