# New ports collection makefile for:    apache mod_auth_mysql
# Date created:		2000/05/19
# Whom:			jim@thehouselys.net
#
# $FreeBSD$

PORTNAME=	mod_auth_mysql
PORTVERSION=	2.20
CATEGORIES=	www
MASTER_SITES=	http://bourbon.netvision.net.il/mysql/mod_auth_mysql/ \
		http://download.sourceforge.net/mirrors/mysql/Downloads/Contrib/ \
		http://web.mysql.com/Contrib/

MAINTAINER=	jeh@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/${AP_PORT}
LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
RUN_DEPENDS=	${LOCALBASE}/sbin/${AP_TARGET}:${PORTSDIR}/www/${AP_PORT}

.include <bsd.port.pre.mk>

APXS=		${LOCALBASE}/sbin/apxs

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

AUTH_MYSQL_DOCS=	apache/manual/mod/mod_auth_mysql

PLIST_SUB=	AUTH_MYSQL_DOCS="${AUTH_MYSQL_DOCS}"

PKGMESSAGE=	${WRKSRC}/.install_notes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-mysql=${PREFIX} \
		--with-apxs=${APXS}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/${AUTH_MYSQL_DOCS}
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/${AUTH_MYSQL_DOCS}
	@${INSTALL_DATA} ${WRKSRC}/USAGE ${PREFIX}/share/doc/${AUTH_MYSQL_DOCS}
	@@(cd ${PREFIX}/share/doc && ${LN} -sf ${AUTH_MYSQL_DOCS} mod_auth_mysql)
.endif

.include <bsd.port.post.mk>
