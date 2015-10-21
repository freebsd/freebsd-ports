# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Reddit-Client
PORTVERSION=	1.072
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Methods and object wrappers for objects exposed by the Reddit API

BUILD_DEPENDS=	p5-IO-Capture>=0:${PORTSDIR}/devel/p5-IO-Capture \
		p5-JSON>=2.53:${PORTSDIR}/converters/p5-JSON \
		p5-URI-Encode>0:${PORTSDIR}/www/p5-URI-Encode \
		p5-URI>0:${PORTSDIR}/net/p5-URI \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww \
		p5-File-Path-Expand>=0:${PORTSDIR}/devel/p5-File-Path-Expand
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-MockModule>=0:${PORTSDIR}/devel/p5-Test-MockModule

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
