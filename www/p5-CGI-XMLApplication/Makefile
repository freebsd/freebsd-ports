# New ports collection makefile for:	CGI::XMLApplication
# Date created:		13 Dec 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	CGI-XMLApplication
PORTVERSION=	1.0.2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CGI
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@protey.ru

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/XML/LibXSLT.pm:${PORTSDIR}/textproc/p5-XML-LibXSLT
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		CGI::XMLApplication.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

post-install:
.ifndef(NOPORTDOCS)
		@${MKDIR} ${EXAMPLESDIR}
		${INSTALL_SCRIPT} ${WRKSRC}/examples/*.pl ${EXAMPLESDIR}
		${INSTALL_DATA} ${WRKSRC}/examples/*.pm ${EXAMPLESDIR}
		${INSTALL_DATA} ${WRKSRC}/examples/*.xsl ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
