# New ports collection makefile for:	p5-HTML-Tidy
# Date Created:				8 june 2004
# Whom:					mat
#
# $FreeBSD$
#

PORTNAME=	HTML-Tidy
PORTVERSION=	1.52
CATEGORIES=	textproc www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Web validation in a Perl object using tidy

BUILD_DEPENDS=	${SITE_PERL}/LWP/Simple.pm:${PORTSDIR}/www/p5-libwww
LIB_DEPENDS=	tidyp:${PORTSDIR}/textproc/tidyp
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		HTML::Tidy.3 HTML::Tidy::Message.3

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/Makefile.PL

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
