# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	HTTP-Link-Parser
PORTVERSION=	0.200
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Parse HTTP Link headers

LICENSE=	MIT

BUILD_DEPENDS=	p5-URI>=1.30:${PORTSDIR}/net/p5-URI \
		p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-RDF-Trine>=0:${PORTSDIR}/textproc/p5-RDF-Trine
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
