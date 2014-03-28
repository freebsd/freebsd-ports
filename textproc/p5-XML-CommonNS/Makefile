# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	XML-CommonNS
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	List of commonly used namespaces

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-XML-NamespaceFactory>=0:${PORTSDIR}/textproc/p5-XML-NamespaceFactory
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
