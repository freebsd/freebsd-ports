# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	HTTP-Cookies-Mozilla
PORTVERSION=	2.03
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Cookie storage and management for Mozilla

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTTP-Cookies>=0:${PORTSDIR}/www/p5-HTTP-Cookies
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Text-Diff>=0:${PORTSDIR}/textproc/p5-Text-Diff \
		sqlite3:${PORTSDIR}/databases/sqlite3

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
