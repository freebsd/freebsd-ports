# New ports collection makefile for: mod_auth_pwcheck
# Date created:		2001/08/08
# Whom:			Anton Voronin <anton@urc.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	mod_auth_pwcheck
PORTVERSION=	1.0
CATEGORIES=	www
MASTER_SITES=	http://www.chelcom.ru/~anton/projects/files/

MAINTAINER=	anton@urc.ac.ru

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/${AP_CATEGORY}/${AP_PORT}
RUN_DEPENDS=	${LOCALBASE}/sbin/${AP_TARGET}:${PORTSDIR}/${AP_CATEGORY}/${AP_PORT} \
		${LOCALBASE}/sbin/pwcheck:${PORTSDIR}/security/cyrus-sasl

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

APXS?=		${LOCALBASE}/sbin/apxs
.if exists(${APXS})
AP_MOD_SSL_SUFFIX!=	${APXS} -q CFLAGS 2>/dev/null \
		| ${GREP} DMOD_SSL >/dev/null \
		|| ${ECHO} -modssl
AP_CATEGORY!=	${APXS} -q CFLAGS 2>/dev/null \
		| ${GREP} DRUSSIAN_APACHE >/dev/null \
		|| ${ECHO} www
AP_TARGET!=	${APXS} -q TARGET 2>/dev/null || ${ECHO}
AP_LIBEXEC!=	${APXS} -q LIBEXECDIR 2>/dev/null | ${SED} 's@^${PREFIX}/@@'
.else
AP_CATEGORY=	www
.endif

AP_PORT=	apache13${AP_MOD_SSL_SUFFIX}
AUTH_PWCHECK_DOCS=	share/doc/apache/manual/mod/mod_auth_pwcheck
PLIST_SUB=	AUTH_PWCHECK_DOCS="${AUTH_PWCHECK_DOCS}" \
		AP_LIBEXEC="${AP_LIBEXEC}" \
		APXS="${APXS}"

.include <bsd.port.post.mk>
