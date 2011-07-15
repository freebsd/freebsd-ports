# New ports collection makefile for:	nagios-check_mysql_slave
# Date created: 	15 May 2011
# Whom:			Ryan Steinmetz
#
# $FreeBSD$

PORTNAME=	check_mysql_slave
PORTVERSION=	0.1.1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://buhacoff.net/2009/products/check_mysql_slave/archive/ \
		http://people.rit.edu/rpsfa/
PKGNAMEPREFIX=	nagios-

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Nagios Plugin to monitor MySQL replication on a slave

RUN_DEPENDS=	p5-DBI>=1.60.7:${PORTSDIR}/databases/p5-DBI \
		p5-DBD-mysql>0:${PORTSDIR}/databases/p5-DBD-mysql

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_BUILD=	yes
USE_PERL5_RUN=	yes
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
