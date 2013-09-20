# $FreeBSD$

PORTNAME=	STF-Dispatcher-PSGI
PORTVERSION=	1.11
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DMAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for pluggable STF dispatcher interface

RUN_DEPENDS=	\
	p5-Class-Accessor-Lite>0:${PORTSDIR}/devel/p5-Class-Accessor-Lite \
	p5-HTTP-Date>0:${PORTSDIR}/www/p5-HTTP-Date \
	p5-Plack>0:${PORTSDIR}/www/p5-Plack \
	p5-Plack-Middleware-Header>0:${PORTSDIR}/www/p5-Plack-Middleware-Header
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Net-STF-Client>0:${PORTSDIR}/www/p5-Net-STF-Client \
	p5-Test-TCP>0:${PORTSDIR}/devel/p5-Test-TCP

USES=	perl5
USE_PERL5=	modbuild

MAN3=	STF::Dispatcher::Impl::File.3 \
	STF::Dispatcher::Impl::Hash.3 \
	STF::Dispatcher::PSGI.3 \
	STF::Dispatcher::PSGI::HTTPException.3 \
	STF::Dispatcher::Test.3

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS+=	p5-Test-Simple>=0.98:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
