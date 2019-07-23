# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	HTTP-Cookies-Mozilla
PORTVERSION=	2.036
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Cookie storage and management for Mozilla

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-HTTP-Cookies>=1.25:www/p5-HTTP-Cookies
TEST_DEPENDS=	p5-Text-Diff>=0:textproc/p5-Text-Diff \
		sqlite3:databases/sqlite3

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
