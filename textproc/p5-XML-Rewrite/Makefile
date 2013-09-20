# Created by: Patrick Powell <papowell@astart.com>
# $FreeBSD$

PORTNAME=	XML-Rewrite
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	papowell@astart.com
COMMENT=	XML processing and rewriting

RUN_DEPENDS=	p5-Log-Report>=0.21:${PORTSDIR}/devel/p5-Log-Report \
		p5-XML-Compile-Cache>=0:${PORTSDIR}/textproc/p5-XML-Compile-Cache \
		p5-XML-LibXML>=1.70:${PORTSDIR}/textproc/p5-XML-LibXML
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=	xmlrewrite.1
MAN3=	XML::Rewrite.3 \
	XML::Rewrite::Schema.3

NO_STAGE=	yes
.include <bsd.port.mk>
