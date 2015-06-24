# Created by: ijliao
# $FreeBSD$

PORTNAME=	CGI-Cookie-Splitter
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Split big cookies into smaller ones

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-CGI-Simple>=0:${PORTSDIR}/www/p5-CGI-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502200
TEST_DEPENDS+=	p5-Test-Simple>=1.001.014:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
