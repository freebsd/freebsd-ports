# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	XML-RSS-LibXML
PORTVERSION=	0.31.02
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	XML::RSS with XML::LibXML

BUILD_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-DateTime-Format-Mail>=0:${PORTSDIR}/devel/p5-DateTime-Format-Mail \
		p5-DateTime-Format-W3CDTF>=0:${PORTSDIR}/devel/p5-DateTime-Format-W3CDTF \
		p5-UNIVERSAL-require>=0:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		p5-XML-LibXML>=1.66:${PORTSDIR}/textproc/p5-XML-LibXML
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/tools/benchmark.pl ${STAGEDIR}${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
