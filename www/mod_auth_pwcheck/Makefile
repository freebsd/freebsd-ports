# New ports collection makefile for: mod_auth_pwcheck
# Date created:		2001/08/08
# Whom:			Anton Voronin <anton@chelcom.ru>
#
# $FreeBSD$
#

PORTNAME=	mod_auth_pwcheck
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.chelcom.ru/~anton/projects/files/

MAINTAINER=	anton@chelcom.ru
COMMENT=	Apache module for user authentication via Cyrus pwcheck daemon

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/${APACHE_PORT}
RUN_DEPENDS=	${LOCALBASE}/sbin/${AP_TARGET}:${PORTSDIR}/${APACHE_PORT} \
		${LOCALBASE}/sbin/pwcheck:${PORTSDIR}/security/cyrus-sasl

WRKSRC=		${WRKDIR}/${PORTNAME}
APACHE_PORT?=	${AP_CATEGORY}/${AP_PORT}
MAKE_ARGS+=	DOC_DIR="${DOCSDIR}"

.include <bsd.port.pre.mk>

.if exists(${APXS})
AP_MOD_SSL_SUFFIX!=	${APXS} -q CFLAGS 2>/dev/null \
		| ${GREP} DMOD_SSL >/dev/null \
		|| ${ECHO} -modssl
AP_CATEGORY!=	${APXS} -q CFLAGS 2>/dev/null \
		| ${GREP} DRUSSIAN_APACHE >/dev/null \
		&& ${ECHO} russian \
		|| ${ECHO} www
AP_TARGET!=	${APXS} -q TARGET 2>/dev/null
AP_LIBEXEC!=	${APXS} -q LIBEXECDIR 2>/dev/null | ${SED} 's@^${PREFIX}/@@'
AP_SYSCONF!=	${APXS} -q SYSCONFDIR 2>/dev/null
.else
AP_CATEGORY=	www
.endif

AP_PORT=	apache13${AP_MOD_SSL_SUFFIX}
PLIST_SUB=	AP_LIBEXEC="${AP_LIBEXEC}" \
		AP_SYSCONF="${AP_SYSCONF}" \
		APXS="${APXS}"

.include <bsd.port.post.mk>
