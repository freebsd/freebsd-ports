# Created by: arved
# $FreeBSD$

PORTNAME=	SNMP-Info
PORTVERSION=	3.70
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module for gathering information from network devices

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp
RUN_DEPENDS=	p5-Class-ISA>0:devel/p5-Class-ISA \
		p5-Module-Info>0:devel/p5-Module-Info \
		p5-NetAddr-IP>0:net-mgmt/p5-NetAddr-IP \
		p5-PPI>0:textproc/p5-PPI
TEST_DEPENDS=	p5-Hook-LexWrap>=0:devel/p5-Hook-LexWrap \
		p5-Test-Class-Most>0:devel/p5-Test-Class-Most \
		p5-Test-Distribution>0:devel/p5-Test-Distribution \
		p5-Test-MockObject>0:devel/p5-Test-MockObject

USES=		perl5
USE_PERL5=	modbuild

NO_ARCH=	yes

.include <bsd.port.mk>
