# Created by: araujo
# $FreeBSD$

PORTNAME=	googlog
PORTVERSION=	1.18
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.googlog.org/download/
DISTNAME=	GoogLog-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Simple tool to search inside your syslog files

BUILD_DEPENDS=	p5-Config-Tiny>=0:${PORTSDIR}/devel/p5-Config-Tiny \
		p5-HTML-Template>=0:${PORTSDIR}/www/p5-HTML-Template
RUN_DEPENDS=	p5-Config-Tiny>=0:${PORTSDIR}/devel/p5-Config-Tiny \
		p5-HTML-Template>=0:${PORTSDIR}/www/p5-HTML-Template

DEPRECATED=	no upstream project
EXPIRATION_DATE=	2013-08-01

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

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
