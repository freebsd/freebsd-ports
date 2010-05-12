# New ports collection makefile for: rsyslog4-mysql
# Date created:     29 December 2008
# Whom:             Cristiano Rolim Pereira <cristianorolim@hotmail.com>
#
# $FreeBSD$
#

COMMENT=	MySQL output module for rsyslog
MASTERDIR=	${.CURDIR}/../rsyslog55

MNAME=	mysql
USE_MYSQL=	yes

CONFIGURE_ARGS+=--enable-mysql

do-install:
	@${INSTALL_PROGRAM} \
		${WRKSRC}/plugins/ommysql/.libs/ommysql.so ${PREFIX}/lib/rsyslog
	@${INSTALL_DATA} \
		${WRKSRC}/plugins/ommysql/ommysql.la ${PREFIX}/lib/rsyslog
post-install:
.ifndef NOPORTEXAMPLES
	@${INSTALL} -d ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/plugins/ommysql/createDB.sql ${EXAMPLESDIR}/mysql_createDB.sql
.endif
.include "${MASTERDIR}/Makefile"
