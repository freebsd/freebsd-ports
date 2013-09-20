# Created by: Cristiano Rolim Pereira <cristianorolim@hotmail.com>
# $FreeBSD$

COMMENT=	MySQL output module for rsyslog
MASTERDIR=	${.CURDIR}/../rsyslog6

MNAME=	mysql
USE_MYSQL=	yes

CONFIGURE_ARGS+=--enable-mysql

NO_STAGE=	yes
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
