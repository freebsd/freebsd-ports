PORTNAME=	check_mysql_slave
PORTVERSION=	0.1.1
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://buhacoff.net/2009/products/check_mysql_slave/archive/ \
		ZI
PKGNAMEPREFIX=	nagios-

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Nagios Plugin to monitor MySQL replication on a slave
WWW=		http://buhacoff.net/software/check_mysql_slave

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-DBI>=1.60.7:databases/p5-DBI \
		${DBD_MYSQL}

PORTSCOUT=	ignore:1

NO_BUILD=	yes
NO_ARCH=	yes
USES=		mysql perl5 shebangfix
SHEBANG_FILES=	check_mysql_slave check_mysql_slave_epn
USE_PERL5=	run
DOC_FILES=	check_mysql_slave.html check_mysql_slave.pod

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${WRKSRC}/check_mysql_slave \
		${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${WRKSRC}/check_mysql_slave_epn \
		${STAGEDIR}${PREFIX}/libexec/nagios
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/docs/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
