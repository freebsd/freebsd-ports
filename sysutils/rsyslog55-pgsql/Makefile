# New ports collection makefile for: rsyslog4-pgsql
# Date created:     29 December 2008
# Whom:             Cristiano Rolim Pereira <cristianorolim@hotmail.com>
#
# $FreeBSD$
#

COMMENT=	PostgreSQL output module for rsyslog
MASTERDIR=	${.CURDIR}/../rsyslog55

MNAME=	pgsql
USE_PGSQL=	yes

CONFIGURE_ARGS+=--enable-pgsql

do-install:
	@${INSTALL_PROGRAM} \
		${WRKSRC}/plugins/ompgsql/.libs/ompgsql.so ${PREFIX}/lib/rsyslog
	@${INSTALL_DATA} \
		${WRKSRC}/plugins/ompgsql/ompgsql.la ${PREFIX}/lib/rsyslog
post-install:
.ifndef NOPORTEXAMPLES
	@${INSTALL} -d ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/plugins/ompgsql/createDB.sql ${EXAMPLESDIR}/pgsql_createDB.sql
.endif
.include "${MASTERDIR}/Makefile"
