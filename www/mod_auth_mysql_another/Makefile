# New ports collection makefile for:    apache mod_auth_mysql_another
# Date created:		2002/04/20
# Whom:			mbr@freebsd.org
#
# $FreeBSD$

PORTNAME=	mod_auth_mysql_another
PORTVERSION=	1.0
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.kcilink.com/pub/
DISTNAME=       mod_auth_mysql
EXTRACT_SUFX=	.c.gz

MAINTAINER=	mbr@FreeBSD.org

BUILD_DEPENDS=	${PREFIX}/sbin/apxs:${PORTSDIR}/www/${AP_PORT}
LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
RUN_DEPENDS=	${PREFIX}/sbin/${AP_TARGET}:${PORTSDIR}/www/${AP_PORT}

.include <bsd.port.pre.mk>

APXS=		${PREFIX}/sbin/apxs

AP_PORT?=	apache13
.if exists(${APXS})
APXS_WORKS!=	${APXS} -q TARGET 2>/dev/null || echo no
.endif
.if exists(${APXS}) && ${APXS_WORKS} != no
AP_TARGET!=	${APXS} -q TARGET
AP_SYSCONF!=	${APXS} -q SYSCONFDIR
AP_INCLUDE!=	${APXS} -q INCLUDEDIR
AP_LIBEXEC!=	${APXS} -q LIBEXECDIR
.else
AP_TARGET?=	httpd
AP_SYSCONF?=	${PREFIX}/etc/apache
AP_INCLUDE?=	${PREFIX}/include/apache
AP_LIBEXEC?=	${PREFIX}/libexec/apache
.endif

AUTH_MYSQL_DOCS= apache/manual/mod/mod_auth_mysql_another

PLIST_SUB=	AUTH_MYSQL_DOCS="${AUTH_MYSQL_DOCS}"

PKGMESSAGE=	${WRKSRC}/.install_notes

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} -p ${WRKDIR}/mod_auth_mysql
	@for file in ${EXTRACT_ONLY}; do \
		${CP} ${_DISTDIR}/$$file ${WRKDIR}/mod_auth_mysql; \
		${EXTRACT_CMD} -d ${WRKDIR}/mod_auth_mysql/$$file; \
	done
.if !defined(EXTRACT_PRESERVE_OWNERSHIP)
	@if [ `id -u` = 0 ]; then \
		${CHMOD} -R ug-s ${WRKDIR}; \
		${CHOWN} -R 0:0 ${WRKDIR}; \
	fi
.endif

post-patch:
	@${CP} ${WRKDIR}/mod_auth_mysql/Makefile ${WRKDIR}/mod_auth_mysql/Makefile.new
	@(${SED} -e 's|%%PREFIX%%|${PREFIX}|g' | \
	    ${SED} -e 's|%%APXS%%|${APXS}|g' | \
	    ${SED} -e 's|%%APXSFLAGS%%|${APXSFLAGS}|g') \
	    < ${WRKDIR}/mod_auth_mysql/Makefile.new \
	    > ${WRKDIR}/mod_auth_mysql/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/${AUTH_MYSQL_DOCS}
	@${INSTALL_DATA} ${FILESDIR}/USAGE ${PREFIX}/share/doc/${AUTH_MYSQL_DOCS}
	@@(cd ${PREFIX}/share/doc && ${LN} -sf ${PREFIX}/share/doc/${AUTH_MYSQL_DOCS} mod_auth_mysql_another)
.endif

.include <bsd.port.post.mk>
