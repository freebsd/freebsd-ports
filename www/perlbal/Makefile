# Created by: Jacques Marneweck <jacques@php.net>
# $FreeBSD$

PORTNAME=	Perlbal
PORTVERSION=	1.80
CATEGORIES=	www
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DORMANDO
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Reverse-proxy load balancer and webserver

RUN_DEPENDS=	p5-BSD-Resource>=0:${PORTSDIR}/devel/p5-BSD-Resource \
		p5-Danga-Socket>=1.44:${PORTSDIR}/devel/p5-Danga-Socket \
		p5-HTTP-Date>=0:${PORTSDIR}/www/p5-HTTP-Date \
		p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-IO-AIO>=0:${PORTSDIR}/devel/p5-IO-AIO \
		p5-Net-Netmask>=0:${PORTSDIR}/net-mgmt/p5-Net-Netmask \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure
USE_RC_SUBR=	perlbal

MAN1=		perlbal.1
MAN3=		Perlbal.3 \
		Perlbal::FAQ.3 \
		Perlbal::Manual.3 \
		Perlbal::Manual::Configuration.3 \
		Perlbal::Manual::Contributing.3 \
		Perlbal::Manual::Credits.3 \
		Perlbal::Manual::Debugging.3 \
		Perlbal::Manual::FailOver.3 \
		Perlbal::Manual::HighPriority.3 \
		Perlbal::Manual::Hooks.3 \
		Perlbal::Manual::Install.3 \
		Perlbal::Manual::Internals.3 \
		Perlbal::Manual::LoadBalancer.3 \
		Perlbal::Manual::Logging.3 \
		Perlbal::Manual::Management.3 \
		Perlbal::Manual::Plugins.3 \
		Perlbal::Manual::ReverseProxy.3 \
		Perlbal::Manual::Roles.3 \
		Perlbal::Manual::Selector.3 \
		Perlbal::Manual::WebServer.3 \
		Perlbal::Plugin::Cgilike.3 \
		Perlbal::Plugin::FlvStreaming.3 \
		Perlbal::Plugin::Include.3 \
		Perlbal::Plugin::MaxContentLength.3 \
		Perlbal::Plugin::Palimg.3 \
		Perlbal::Plugin::Redirect.3 \
		Perlbal::Plugin::Throttle.3 \
		Perlbal::Plugin::XFFExtras.3 \
		Perlbal::Test.3 \
		Perlbal::Util.3

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} 's,/etc/perlbal,${PREFIX}/etc/perlbal,g' \
		${WRKSRC}/lib/Perlbal/Manual/Configuration.pod \
		${WRKSRC}/lib/Perlbal/Plugin/Include.pm \
		${WRKSRC}/perlbal

	@${RM} ${WRKSRC}/lib/Perlbal/Manual/Configuration.pod.bak \
		${WRKSRC}/lib/Perlbal/Plugin/Include.pm.bak \

.ifndef NOPORTDOCS
post-install:
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${DOCSDIR}
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS+=	p5-Test-Simple>=0.94:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
