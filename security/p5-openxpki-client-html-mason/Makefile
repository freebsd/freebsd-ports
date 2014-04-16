# Created by: Sergei Vyshenski <svysh@pn.sinp.msu.ru>
# $FreeBSD$

PORTNAME=	openxpki-client-html-mason
PORTVERSION=	0.9.1396
CATEGORIES=	security perl5
MASTER_SITES=	SF/openxpki/openxpki/0.9.1300
PKGNAMEPREFIX=	p5-
DISTNAME=	OpenXPKI-Client-HTML-Mason-${PORTVERSION}
DIST_SUBDIR=	openxpki

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Web interface for local openxpki daemon

OPTIONS_DEFINE=	DOCS EXAMPLES

BUILD_DEPENDS=	\
	p5-openxpki-client>=0:${PORTSDIR}/security/p5-openxpki-client \
	p5-HTML-Mason>=0:${PORTSDIR}/www/p5-HTML-Mason \
	p5-Data-SpreadPagination>=0:${PORTSDIR}/textproc/p5-Data-SpreadPagination
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gmake perl5
USE_PERL5=	configure

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -R ${WRKSRC}/htdocs ${STAGEDIR}${DOCSDIR}/
	@${ECHO_MSG} ""
	@${ECHO_MSG} "==================================================================="
	@${ECHO_MSG} "===> Mason htdocs for ${DISTNAME}"
	@${ECHO_MSG} "===> installed in ${DOCSDIR}"
	@${ECHO_MSG} "==================================================================="
	@${ECHO_MSG} ""
.if !defined(BATCH)
	@sleep 3
.endif
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/eg ${STAGEDIR}${EXAMPLESDIR}/
	@${ECHO_MSG} ""
	@${ECHO_MSG} "==================================================================="
	@${ECHO_MSG} "===> Examples of simple Mason configuration via httpd.conf directives"
	@${ECHO_MSG} "===> installed in ${EXAMPLESDIR}"
	@${ECHO_MSG} "==================================================================="
	@${ECHO_MSG} ""
.if !defined(BATCH)
	@sleep 3
.endif
	${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -R ${WRKSRC}/bin ${STAGEDIR}${DATADIR}/
	@${ECHO_MSG} ""
	@${ECHO_MSG} "==================================================================="
	@${ECHO_MSG} "===> Examples of CGI scripts for ${DISTNAME}"
	@${ECHO_MSG} "===> installed in ${DATADIR}"
	@${ECHO_MSG} "==================================================================="
	@${ECHO_MSG} ""
.if !defined(BATCH)
	@sleep 3
.endif

.include <bsd.port.mk>
