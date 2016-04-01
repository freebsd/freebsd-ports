# Created by: Jacques Marneweck <jacques@php.net>
# $FreeBSD$

PORTNAME=	Perlbal
PORTVERSION=	1.80
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DORMANDO
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Reverse-proxy load balancer and webserver

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-BSD-Resource>=0:devel/p5-BSD-Resource \
		p5-Danga-Socket>=1.44:devel/p5-Danga-Socket \
		p5-HTTP-Date>=0:www/p5-HTTP-Date \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-IO-AIO>=0:devel/p5-IO-AIO \
		p5-Net-Netmask>=0:net-mgmt/p5-Net-Netmask \
		p5-libwww>=0:www/p5-libwww
BUILD_DEPENDS:=	${RUN_DEPENDS}

OPTIONS_DEFINE=	DOCS

USES=		perl5
USE_PERL5=	configure
USE_RC_SUBR=	perlbal

post-patch:
	@${REINPLACE_CMD} 's,/etc/perlbal,${PREFIX}/etc/perlbal,g' \
		${WRKSRC}/lib/Perlbal/Manual/Configuration.pod \
		${WRKSRC}/lib/Perlbal/Plugin/Include.pm \
		${WRKSRC}/perlbal
	@${RM} ${WRKSRC}/lib/Perlbal/Manual/Configuration.pod.bak \
		${WRKSRC}/lib/Perlbal/Plugin/Include.pm.bak \

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
