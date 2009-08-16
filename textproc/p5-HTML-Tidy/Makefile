# New ports collection makefile for:	p5-HTML-Tidy
# Date Created:				8 june 2004
# Whom:					mat
#
# $FreeBSD$
#

PORTNAME=	HTML-Tidy
PORTVERSION=	1.08
PORTREVISION=	1
CATEGORIES=	textproc www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Web validation in a Perl object using tidy

BUILD_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww
LIB_DEPENDS=	tidy:${PORTSDIR}/www/tidy-lib
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		HTML::Tidy.3 HTML::Tidy::Message.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
