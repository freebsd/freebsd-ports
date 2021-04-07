PORTNAME=	mysql-snmp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2-17
DISTVERSIONSUFFIX=	-g1d0b409
CATEGORIES=	net-mgmt perl5

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Net-SNMP Perl agent for monitoring MySQL servers

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	net-snmp>=0:net-mgmt/net-snmp \
		p5-DBD-mysql>=0:databases/p5-DBD-mysql \
		p5-DBI>=0:databases/p5-DBI \
		p5-Math-BigInt-GMP>=0:math/p5-Math-BigInt-GMP \
		p5-Net-SNMP>=5.4.3:net-mgmt/p5-Net-SNMP \
		p5-Unix-Syslog>=0:sysutils/p5-Unix-Syslog

USES=		perl5 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	masterzen
USE_PERL5=	run test
USE_RC_SUBR=	mysql-snmp
SHEBANG_FILES=	mysql-snmp opennms/* tests/test.pl

NO_ARCH=	yes
NO_BUILD=	yes
SUB_LIST=	PERL=${PERL}

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mysql-snmp ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/snmp/mibs
	${INSTALL_DATA} ${WRKSRC}/MYSQL-SERVER-MIB.txt \
		${STAGEDIR}${PREFIX}/share/snmp/mibs
	${INSTALL_MAN} ${WRKSRC}/mysql-snmp.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} opennms ${STAGEDIR}/${DATADIR})
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/my.cnf ${STAGEDIR}${ETCDIR}/my.cnf.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

do-test:
	@(cd ${WRKSRC} && \
		${SETENV} ${TEST_ENV} ${PERL5} -I ${STAGEDIR}${PREFIX}/sbin ./tests/test.pl)

.include <bsd.port.mk>
