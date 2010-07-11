# New ports collection makefile for:	googlog
# Date created:		19 Jun 2007
# Whom:			araujo
#
# $FreeBSD$
#

PORTNAME=	googlog
PORTVERSION=	1.18
CATEGORIES=	sysutils
MASTER_SITES=	http://www.googlog.org/download/
DISTNAME=	GoogLog-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@eitanadler.com
COMMENT=	GoogLog is a simple tool to search inside your syslog files

RUN_DEPENDS=	${SITE_PERL}/Config/Tiny.pm:${PORTSDIR}/devel/p5-Config-Tiny \
		${SITE_PERL}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
		${SITE_PERL}/HTML/Template.pm:${PORTSDIR}/www/p5-HTML-Template

NO_BUILD=	yes
USE_PERL5=	yes

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${WWWDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/GoogLog_cgi.pl ${WWWDIR}/
	${INSTALL_DATA} ${WRKSRC}/googlog.ini ${WWWDIR}/
	${INSTALL_DATA} ${WRKSRC}/index.html ${WWWDIR}/

.if !exists(${INSTALL_PATH}/googlog.ini)
	${INSTALL_DATA} ${WRKSRC}/googlog.ini ${WWWDIR}/
.endif

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
