# New ports collection makefile for:    davical
# Date created:                 Tue May 13 09:59:22 EST 2008
# Whom:                         Maurice Castro <maurice@castro.aus.net>
#
# $FreeBSD$
#

PORTNAME=	davical
PORTVERSION=	0.9.4
CATEGORIES?=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=		rscds
DISTNAME=	libawl-php-0.25.tar.gz \
		rscds-${PORTVERSION}

MAINTAINER=	maurice@castro.aus.net
COMMENT=	A simple CalDAV server using a postgres backend

RUN_DEPENDS=	${LOCALBASE}/include/php/ext/pgsql:${PORTSDIR}/databases/php5-pgsql \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML \
		${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg \
		${LOCALBASE}/bin/pwgen:${PORTSDIR}/sysutils/pwgen

NO_BUILD=	yes

SUB_FILES=	pkg-message httpd-davical.conf
WRKSRC=		${WRKDIR}/rscds-${PORTVERSION}

DAVICALDIR?=	${PREFIX}/www/${PORTNAME}
DOCDIR?=	${PREFIX}/share/doc/DAViCal

do-install:
	${MKDIR} ${DAVICALDIR}
	${CP} -rpv ${WRKSRC}/htdocs ${DAVICALDIR}
	${RM} ${DAVICALDIR}/htdocs/*.orig
	${CP} -rpv ${WRKSRC}/inc ${DAVICALDIR}
	${CP} -rpv ${WRKDIR}/libawl-php-0.25/inc ${DAVICALDIR}
	${CP} -rpv ${WRKDIR}/libawl-php-0.25/dba ${DAVICALDIR}
	${MKDIR} ${DAVICALDIR}/config
	${CP} -pv ${WRKSRC}/config/example-config.php ${DAVICALDIR}/config/config.php
	${MKDIR} ${DOCDIR}
	${CP} -prv ${WRKSRC}/config ${DOCDIR}
	${CP} -prv ${WRKSRC}/docs ${DOCDIR}
	${CP} -prv ${WRKSRC}/scripts ${DOCDIR}
	${CP} -prv ${WRKSRC}/dba ${DOCDIR}
	${SED} 's:AWLDIR="$${DBADIR}/../../awl":AWLDIR="${PREFIX}/www/davical":' ${WRKSRC}/dba/create-database.sh > ${DOCDIR}/dba/create-database.sh
	${CP} -pv ${WRKDIR}/httpd-davical.conf ${DOCDIR}
	${CP} -pv ${WRKSRC}/README ${DOCDIR}
	${CP} -pv ${WRKSRC}/INSTALL ${DOCDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
