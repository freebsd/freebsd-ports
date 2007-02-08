# New ports collection makefile for:	softfail
# Date created:		2007-02-01
# Whom:			Patrick Tracanelli <eksffa@freebsdbrasil.com.br>
#
# $FreeBSD$
#

PORTNAME=	softfail
PORTVERSION=	1.15
CATEGORIES=	mail
MASTER_SITES=	http://www6.freebsdbrasil.com.br/~eksffa/l/dev/qmail-smtpextfork/
DISTNAME=	${PORTNAME}_fbsdbrasil-${PORTVERSION}

MAINTAINER=	eksffa@freebsdbrasil.com.br
COMMENT=	Enhaced greylisting system for qmail w/ SMTPEXTFORK patch

SUB_FILES=	pkg-message
SUB_LIST=	QMAIL_PREFIX=${QMAIL_PREFIX}
PLIST_SUB=	QMAIL_PREFIX=${QMAIL_PREFIX}

PORTDOCS=	README softfail.sql

USE_BZIP2=	yes
USE_MYSQL=	yes
USE_QMAIL=	yes

.if defined(QMAIL_SLAVEPORT) && ${QMAIL_SLAVEPORT} != "spamcontrol"
IGNORE=		this software only works with qmail-spamcontrol
.endif

QMAIL_SLAVEPORT=	spamcontrol

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

crontab-entry: extract
	@cd ${WRKSRC} && ${MAKE} crontab-entry

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You can use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} " WITH_MYSQL_SERVER=<value>	Set MySQL server address"
	@${ECHO_MSG} " WITH_MYSQL_USER=<value>	Set user to log into mysql"
	@${ECHO_MSG} " WITH_MYSQL_PASSWD=<value>	Set user's password to mysql"
	@${ECHO_MSG} " WITH_MYSQL_DB=<value>		Set MySQL database to use"
	@${ECHO_MSG} ""
	@${ECHO_MSG} " WITH_UNBLOCK_TIME=<value>	How long (minutes) before"
	@${ECHO_MSG} "				accepting greylisted e-mails"
	@${ECHO_MSG} " WITH_SEEN_TIME=<value>		Minium time a retry should wait"
	@${ECHO_MSG} " WITH_SEEN_MAXTIMES=<value>	Number of times we will allow"
	@${ECHO_MSG} "				WITH_SEEN_TIME be not respected"
	@${ECHO_MSG} "				before AUTO blacklisting IP"
	@${ECHO_MSG} " WITH_MAXDAYS_AUTO=<value>	How long (days) an AUTOmatically"
	@${ECHO_MSG} "				added entry will exist in DB"
	@${ECHO_MSG} ""

pre-build:
.if defined(WITH_MYSQL_SERVER)
	@${ECHO_CMD} "#define MYSQLSERVER	\"${WITH_MYSQL_SERVER}\"" \
		>> ${WRKSRC}/conf.h
	@${REINPLACE_CMD} -e 's|@"localhost"|@"${WITH_MYSQL_SERVER}"|g' \
		${WRKSRC}/softfail.sql
.endif
.if defined(WITH_MYSQL_USER)
	@${ECHO_CMD} "#define MYSQLUSER	\"${WITH_MYSQL_USER}\"" \
		>> ${WRKSRC}/conf.h
	@${REINPLACE_CMD} -e 's|to softfail@|to ${WITH_MYSQL_USER}@|g' \
		${WRKSRC}/softfail.sql
.endif
.if defined(WITH_MYSQL_PASSWD)
	@${ECHO_CMD} "#define MYSQLPASSWORD	\"${WITH_MYSQL_PASSWD}\"" \
		>> ${WRKSRC}/conf.h
	@${REINPLACE_CMD} -e "s|identified by 'softfail40'|identified by '${WITH_MYSQL_PASSWD}'|g" \
		${WRKSRC}/softfail.sql
.endif
.if defined(WITH_MYSQL_DB)
	@${ECHO_CMD} "#define MYSQLDB		\"${WITH_MYSQL_DB}\"" \
		>> ${WRKSRC}/conf.h
	@${REINPLACE_CMD} -e 's|IF EXISTS softfail|IF EXISTS ${WITH_MYSQL_DB}|g' \
		${WRKSRC}/softfail.sql
	@${REINPLACE_CMD} -e 's|CREATE DATABASE softfail|CREATE DATABASE ${WITH_MYSQL_DB}|g' \
		${WRKSRC}/softfail.sql
	@${REINPLACE_CMD} -e 's|GRANT all ON softfail|GRANT all ON ${WITH_MYSQL_DB}|g' \
		${WRKSRC}/softfail.sql
	@${REINPLACE_CMD} -e 's|USE softfail|USE ${WITH_MYSQL_DB}|g' \
		${WRKSRC}/softfail.sql
.endif
.if defined(WITH_UNBLOCK_TIME)
	@${ECHO_CMD} "#define UNBLOCK_AFTER_SEEN	${WITH_UNBLOCK_TIME}" \
		>> ${WRKSRC}/conf.h
.endif
.if defined(WITH_SEEN_TIME)
	@${ECHO_CMD} "#define RFCSEENTIME	${WITH_SEEN_TIME}" \
		>> ${WRKSRC}/conf.h
.endif
.if defined(WITH_SEEN_MAXTIMES)
	@${ECHO_CMD} "#define SEENCONSECMAXTIME	${WITH_SEEN_MAXTIMES}" \
		>> ${WRKSRC}/conf.h
.endif
.if defined(WITH_MAXDAYS_AUTO)
	@${ECHO_CMD} "#define MAXDAYSAUTOINDB	${WITH_MAXDAYS_AUTO}" \
		>> ${WRKSRC}/conf.h
.endif

post-patch:
.if defined(WITH_REPORTMAIL)
	@${REINPLACE_CMD} -e 's|changeme@yourdomainname.com|${WITH_REPORTMAIL}|g' \
		${WRKSRC}/rotate-softfail.sh
.endif

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/softfail.sql ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
