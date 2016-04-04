# Created by: Frank Mayhar <frank@exit.com>
# $FreeBSD$

PORTNAME=	Apache-Session
PORTVERSION=	1.93
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Persistence framework for session data

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DBI>=0:databases/p5-DBI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS+=	p5-Test-Deep>=0.082:devel/p5-Test-Deep \
		p5-Test-Exception>=0.15:devel/p5-Test-Exception \
		p5-Test-Database>=0:databases/p5-Test-Database

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
