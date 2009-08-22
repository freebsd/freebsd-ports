# New ports collection makefile for:	p5-openxpki-client-html-mason
# Date created:				03 Oct 2006
# Whom:					svysh
#
# $FreeBSD$
#

PORTNAME=	openxpki-client-html-mason
PORTVERSION=	0.9.1396
CATEGORIES=	security perl5
MASTER_SITES=	SF/openxpki/openxpki/0.9.1300
PKGNAMEPREFIX=	p5-
DISTNAME=	OpenXPKI-Client-HTML-Mason-${PORTVERSION}
DIST_SUBDIR=	openxpki

MAINTAINER=	svysh@pn.sinp.msu.ru
COMMENT=	Web interface for local openxpki daemon

BUILD_DEPENDS=	\
	${SITE_PERL}/OpenXPKI/Client.pm:${PORTSDIR}/security/p5-openxpki-client \
	${SITE_PERL}/Apache/Mason.pm:${PORTSDIR}/www/p5-HTML-Mason \
	${SITE_PERL}/Data/SpreadPagination.pm:${PORTSDIR}/textproc/p5-Data-SpreadPagination
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	OpenXPKI::Client::HTML::Mason.3 \
	OpenXPKI::Client::HTML::Mason::CRR.3 \
	OpenXPKI::Client::HTML::Mason::Config.3 \
	OpenXPKI::Client::HTML::Mason::Javascript.3 \
	OpenXPKI::Client::HTML::Mason::Menu.3
USE_GMAKE=	yes
PERL_CONFIGURE=	yes

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@${CP} -R ${WRKSRC}/htdocs ${DOCSDIR}/
	@${ECHO_MSG} ""
	@${ECHO_MSG} "==================================================================="
	@${ECHO_MSG} "===> Mason htdocs for ${DISTNAME}"
	@${ECHO_MSG} "===> installed in ${DOCSDIR}"
	@${ECHO_MSG} "==================================================================="
	@${ECHO_MSG} ""
.if !defined(BATCH)
	@sleep 3
.endif
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	@${CP} -R ${WRKSRC}/eg ${EXAMPLESDIR}/
	@${ECHO_MSG} ""
	@${ECHO_MSG} "==================================================================="
	@${ECHO_MSG} "===> Examples of simple Mason configuration via httpd.conf directives"
	@${ECHO_MSG} "===> installed in ${EXAMPLESDIR}"
	@${ECHO_MSG} "==================================================================="
	@${ECHO_MSG} ""
.if !defined(BATCH)
	@sleep 3
.endif
.endif
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}
	@${MKDIR} ${DATADIR}
	@${CP} -R ${WRKSRC}/bin ${DATADIR}/
	@${ECHO_MSG} ""
	@${ECHO_MSG} "==================================================================="
	@${ECHO_MSG} "===> Examples of CGI scripts for ${DISTNAME}"
	@${ECHO_MSG} "===> installed in ${DATADIR}"
	@${ECHO_MSG} "==================================================================="
	@${ECHO_MSG} ""
.if !defined(BATCH)
	@sleep 3
.endif
.endif

.include <bsd.port.mk>
