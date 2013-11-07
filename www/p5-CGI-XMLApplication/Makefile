# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	CGI-XMLApplication
PORTVERSION=	1.1.3
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Object Oriented Interface for CGI Script Applications

BUILD_DEPENDS=	p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-XML-LibXSLT>=0:${PORTSDIR}/textproc/p5-XML-LibXSLT
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/*.pl ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.pm ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.xsl ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
