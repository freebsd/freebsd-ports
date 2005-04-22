# New ports collection makefile for:    apache mod_frontpage
# Date created:		2001/07/24
# Whom:			mb@imp.ch
#
# $FreeBSD$

PORTNAME=	mod_frontpage
PORTVERSION=	1.6.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S/%SUBDIR%/mirfak/g}
DISTFILES=	${PORTNAME}_mirfak-${PORTVERSION}.tar.gz

MAINTAINER=	mbr@FreeBSD.org
COMMENT=	Improved mod_frontpage for Apache, as APXS installation

WRKSRC=		${WRKDIR}/${PORTNAME}_mirfak-${PORTVERSION}

RUN_DEPENDS=	${FPSETPERM}:${PORTSDIR}/www/frontpage

USE_APACHE=	yes
FP_VER=		5.0
FP_DIR=		${PREFIX}/frontpage/version${FP_VER}
FPSETPERM=	${FP_DIR}/set_default_perms.sh

.include <bsd.port.pre.mk>

PKGMESSAGE=	pkg-message

INSTALL_FILE=	${INSTALL} -c -m 555 -o bin -g bin
PKG_PREFIX=	${PREFIX}

.if exists(${APXS})
APXS_WORKS!=	${APXS} -q TARGET 2>/dev/null || ${ECHO} no
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

PERL_CONFIGURE= yes
CONFIGURE_ENV=	PREFIX=${PREFIX} WRKSRC=${WRKSRC}

ONLY_FOR_ARCHS= i386

pre-fetch:
	@${ECHO}
	@${ECHO} "*****************************************************"
	@${ECHO} IMPORTANT
	@${ECHO}
	@${ECHO} This port still has some security issues. Some buffer
	@${ECHO} overflows have been fixed, but since the port depends
	@${ECHO} on ENV[] variables, a local user can still gain a UID
	@${ECHO} of another user. This is a design issue, and also
	@${ECHO} present in the apache13-fp port.
	@${ECHO}
	@${ECHO} Check carefully that the Makefile has FP_UID_MIN and
	@${ECHO} FP_GID_MIN set correctly. If you think security is
	@${ECHO} very important for you, you shouldn't run frontpage
	@${ECHO} at all.
	@${ECHO} "*****************************************************"
	@${ECHO}
	

post-install:
.if (${PREFIX} != "/usr/local")
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's|%%PREFIX%%|${PREFIX}|'
.else
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's|%%PREFIX%%|${PREFIX}|' \
	    | ${GREP} -v "ln"
.endif

.include <bsd.port.post.mk>
