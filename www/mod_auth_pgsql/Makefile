# New ports collection makefile for:    apache mod_auth_pgsql
# Date created:		2000/11/10
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$

PORTNAME=	mod_auth_pgsql
PORTVERSION=	0.9.12
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://www.giuseppetanzilli.it/mod_auth_pgsql/dist/

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	Allows users to use PostgreSQL databases for user authentication

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/${APACHE_PORT}
RUN_DEPENDS=	${LOCALBASE}/sbin/${AP_TARGET}:${PORTSDIR}/${APACHE_PORT}

USE_PGSQL=	yes

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION:S/a//}

.include <bsd.port.pre.mk>

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

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pgsql=${PREFIX} \
		--with-apxs=${APXS}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README \
		${DOCSDIR}
	${TR} -d \\015 < ${WRKSRC}/mod_auth_pgsql.html \
		> ${DOCSDIR}/index.html
	${CHMOD} ${SHAREMODE} \
		${DOCSDIR}/index.html
	${CHOWN} ${SHAREOWN}:${SHAREGRP} \
		${DOCSDIR}/index.html
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
