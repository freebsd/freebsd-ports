# Created by: Mathieu Arnold <mat@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CGI-Framework
PORTVERSION=	0.23
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple-to-use, lightweight web CGI framework

BUILD_DEPENDS=	p5-HTML-Template>=0:${PORTSDIR}/www/p5-HTML-Template \
		p5-CGI-Session>=0:${PORTSDIR}/www/p5-CGI-Session \
		p5-CGI.pm>=0:${PORTSDIR}/www/p5-CGI.pm
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
