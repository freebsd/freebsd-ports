# Created by: Dennis Herrmann <adox@mcx2.org>
# $FreeBSD$

PORTNAME=	WWW-FreeProxy
PORTVERSION=	0.04
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Fetch proxies from free proxy lists

BUILD_DEPENDS=	p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		WWW::FreeProxy.3 WWW::FreeProxy::Proxy4Free.3 WWW::FreeProxy::Samair.3 WWW::FreeProxy::Look.3 WWW::FreeProxy::PublicProxyServers.3

NO_STAGE=	yes
.include <bsd.port.mk>
