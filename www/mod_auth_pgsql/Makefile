# New ports collection makefile for:    apache mod_auth_pgsql
# Date created:		2000/11/10
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$

PORTNAME=	mod_auth_pgsql
PORTVERSION=	0.9.12
CATEGORIES=	www
MASTER_SITES=	http://www.giuseppetanzilli.it/mod_auth_pgsql/dist/

MAINTAINER=	ports@freebsd.org

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/${AP_PORT}
RUN_DEPENDS=	${LOCALBASE}/sbin/${AP_TARGET}:${PORTSDIR}/www/${AP_PORT}
LIB_DEPENDS=	pq.2:${PORTSDIR}/databases/postgresql7

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION:S/a//}

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
CFLAGS:=	`${APXS} -q CFLAGS` ${CFLAGS}
.else
AP_TARGET?=	httpd
AP_SYSCONF?=	${PREFIX}/etc/apache
AP_INCLUDE?=	${PREFIX}/include/apache
AP_LIBEXEC?=	${PREFIX}/libexec/apache
.endif

AUTH_PGSQL_DOCS=	apache/manual/mod/mod_auth_pgsql

PLIST_SUB+=	AUTH_PGSQL_DOCS="${AUTH_PGSQL_DOCS}"

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pgsql=${PREFIX} \
		--with-apxs=${APXS}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/${AUTH_PGSQL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/README \
		${PREFIX}/share/doc/${AUTH_PGSQL_DOCS}/
	${TR} -d \\015 < ${WRKSRC}/mod_auth_pgsql.html \
		> ${PREFIX}/share/doc/${AUTH_PGSQL_DOCS}/index.html
	${CHMOD} ${SHAREMODE} \
		${PREFIX}/share/doc/${AUTH_PGSQL_DOCS}/index.html
	${CHOWN} ${SHAREOWN}:${SHAREGRP} \
		${PREFIX}/share/doc/${AUTH_PGSQL_DOCS}/index.html
	${LN} -sf ${AUTH_PGSQL_DOCS} ${PREFIX}/share/doc/
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
