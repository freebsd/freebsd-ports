# Created by: Cristiano Rolim Pereira <cristianorolim@hotmail.com>
# $FreeBSD$

COMMENT=	PostgreSQL output module for rsyslog
MASTERDIR=	${.CURDIR}/../rsyslog6

MNAME=	pgsql
USE_PGSQL=	yes

CONFIGURE_ARGS+=--enable-pgsql

NO_STAGE=	yes
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
