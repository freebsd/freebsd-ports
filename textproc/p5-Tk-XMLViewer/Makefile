# Created by: vanilla
# $FreeBSD$

PORTNAME=	Tk-XMLViewer
PORTVERSION=	0.21
PORTREVISION=	4
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Tk::XMLViewer - Tk widget to display XML

BUILD_DEPENDS=	p5-Tk>=0:x11-toolkits/p5-Tk \
		p5-XML-Parser>=0:textproc/p5-XML-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
