# New ports collection makefile for:	softfail
# Date created:		2007-02-01
# Whom:			Patrick Tracanelli <eksffa@freebsdbrasil.com.br>
#
# $FreeBSD$
#

PORTNAME=	softfail
PORTVERSION=	2.0
CATEGORIES=	mail
MASTER_SITES=	http://www6.freebsdbrasil.com.br/~eksffa/l/dev/qmail-smtpextfork/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jmelo/${PORTNAME}
DISTNAME=	${PORTNAME}_fbsdbrasil-${PORTVERSION}

MAINTAINER=	eksffa@freebsdbrasil.com.br
COMMENT=	Enhaced greylisting system for qmail w/ SMTPEXTFORK patch

LIB_DEPENDS+=	spf2.3:${PORTSDIR}/mail/libspf2

SUB_FILES=	pkg-message
SUB_LIST=	QMAIL_PREFIX=${QMAIL_PREFIX}
PLIST_SUB=	QMAIL_PREFIX=${QMAIL_PREFIX}

PORTDOCS=	README softfail.sql

USE_BZIP2=	yes
USE_MYSQL=	yes
USE_QMAIL=	yes

.if defined(QMAIL_SLAVEPORT) && ( ${QMAIL_SLAVEPORT} != "spamcontrol" && ${QMAIL_SLAVEPORT} != "ldap" )
IGNORE=		software only works with qmail-spamcontrol or qmail-ldap
.else
QMAIL_SLAVEPORT=	spamcontrol
.endif

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
	@${ECHO_MSG} " WITH_MAXDAYSAUTOBLACKINDB=<value>"
	@${ECHO_MSG} "		How long (days) an AUTOmatically"
	@${ECHO_MSG} "		added blacklist entry will exist in DB"
	@${ECHO_MSG} "		(used for rotate-softfail-db program)"
	@${ECHO_MSG} ""
	@${ECHO_MSG} " WITH_REPORTMAIL=<e-mail>"
	@${ECHO_MSG} "		Whom (e-mail address) to report statistics when"
	@${ECHO_MSG} "		qmail-sf.log get rotated."
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
.if defined(WITH_SFGLTIME)
	@${ECHO_CMD} "#define UNBLOCK_AFTER_SEEN	${WITH_SFGLTIME}" \
		>> ${WRKSRC}/conf.h
.endif
.if defined(WITH_SFSEENTIME)
	@${ECHO_CMD} "#define RFCSEENTIME	${WITH_SFSEENTIME}" \
		>> ${WRKSRC}/conf.h
.endif
.if defined(WITH_SFMAXSEENTIMES)
	@${ECHO_CMD} "#define SEENCONSECMAXTIME	${WITH_SFMAXSEENTIMES}" \
		>> ${WRKSRC}/conf.h
.endif
.if defined(WITH_MAXDAYSAUTOBLACKINDB)
	@${ECHO_CMD} "#define MAXDAYSAUTOINDB	${WITH_MAXDAYSAUTOBLACKINDB}" \
		>> ${WRKSRC}/conf.h
.endif

post-patch:
.if defined(WITH_REPORTMAIL)
	@${REINPLACE_CMD} -e 's|changeme@yourdomainname.com|${WITH_REPORTMAIL}|g' \
		${WRKSRC}/rotate-softfail.sh
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/softfail.sql ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
