# New ports collection makefile for:	CGI::XMLApplication
# Date created:		13 Dec 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	CGI-XMLApplication
PORTVERSION=	1.1.3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CGI
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Object Oriented Interface for CGI Script Applications

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML \
		${SITE_PERL}/${PERL_ARCH}/XML/LibXSLT.pm:${PORTSDIR}/textproc/p5-XML-LibXSLT
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		CGI::XMLApplication.3

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/*.pl	${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.pm		${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.xsl	${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
