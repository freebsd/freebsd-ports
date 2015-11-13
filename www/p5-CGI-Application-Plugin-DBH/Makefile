# Created by: Espen Tagestad <espen@tagestad.no>
# $FreeBSD$

PORTNAME=	CGI-Application-Plugin-DBH
PORTVERSION=	4.04
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Easy DBI access from CGI::Application

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-CGI-Application>=0:${PORTSDIR}/www/p5-CGI-Application \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-MockObject>=1.20120301:${PORTSDIR}/devel/p5-Test-MockObject

NO_ARCH=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
