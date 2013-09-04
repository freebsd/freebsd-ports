# New ports collection makefile for:	nagios-check_mysql_slave
# Date created: 	15 May 2011
# Whom:			Ryan Steinmetz
#
# $FreeBSD$

PORTNAME=	check_mysql_slave
PORTVERSION=	0.1.1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://buhacoff.net/2009/products/check_mysql_slave/archive/ \
		http://mirrors.rit.edu/zi/
PKGNAMEPREFIX=	nagios-

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Nagios Plugin to monitor MySQL replication on a slave

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-DBI>=1.60.7:${PORTSDIR}/databases/p5-DBI \
		p5-DBD-mysql>0:${PORTSDIR}/databases/p5-DBD-mysql

PORTSCOUT=	ignore:1

NO_BUILD=	yes
USES=		perl5
USE_PERL5=	run
DOC_FILES=	check_mysql_slave.html check_mysql_slave.pod

do-install:
	@${MKDIR} ${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${WRKSRC}/check_mysql_slave ${PREFIX}/libexec/nagios/
	${INSTALL_SCRIPT} ${WRKSRC}/check_mysql_slave_epn ${PREFIX}/libexec/nagios/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/docs/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
