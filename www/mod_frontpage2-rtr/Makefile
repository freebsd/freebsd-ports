# New ports collection makefile for:    Microsoft FrontPage Extensions
# Date created:         Tue Feb  4 13:59:20 CST 2003
# Whom:                 hetzels@westbend.net
#
# $FreeBSD$
#

PORTNAME=	mod_frontpage
PORTVERSION=	5.0.2.2635
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	# Requries manual fetch of files from http://www.rtr.com/
PKGNAMESUFFIX=	${AP_VERSION:S/+//}
DISTFILES=	${FRONTPAGE}

MAINTAINER=	swhetzel@gmail.com
COMMENT=	Microsoft mod_frontpage (by RTR) for Apache ${FP_AP_VER}

FORBIDDEN=	Remote code execution vulnerability

RUN_DEPENDS=	${LOCALBASE}/${FP_SETPERM}:${PORTSDIR}/www/frontpage

DIST_SUBDIR=	fp${PORTVERSION:S/.//g}

ONLY_FOR_ARCHS=	i386 ia64 amd64 alpha sparc64

PATCH_WRKSRC=	${WRKDIR}

FPDIR=		frontpage/version${FP_VER}

EXTRACT_FILES=	${FPDIR}/apache-fp/mod_frontpage.c \
		${FPDIR}/apache2/mod_fpcgid.c \
		${FPDIR}/apache2/mod_fpcgid.h \
		${FPDIR}/apache2/mod_frontpage.c \
		${FPDIR}/apache2/mod_frontpage.h \
		${FPDIR}/apache2/mod_suexec.h

USE_APACHE?=	20+
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

AP_EXTRAS=	-Wc,-DFREEBSD

FP_SETPERM=	${FPDIR}/set_default_perms.sh

.ifdef WITH_MODFP_COMPAT
AP_EXTRAS+=	-DIMPROVED_MODFP_COMPAT
.endif
.ifdef WITH_DISABLED
AP_EXTRAS+=	-DDEFAULT_TO_OFF
.endif

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../frontpage/Makefile.fp.common"

.if ${APACHE_VERSION} >= 20
FP_AP_VER=	2.0
WRKSRC=		${WRKDIR}/${FPDIR}/apache2
SRC_FILE=	mod_frontpage.c mod_fpcgid.c
.else
FP_AP_VER=	1.3
WRKSRC=		${WRKDIR}/${FPDIR}/apache-fp
PKGMESSAGE=	${MASTERDIR}/pkg-message13
.endif

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@if ! (cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${_DISTDIR}/${FRONTPAGE} ${EXTRACT_AFTER_ARGS} ${EXTRACT_FILES}); \
	then \
		exit 1; \
	fi

post-install:
.if (${PREFIX} != "/usr/local")
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's|%%PREFIX%%|${PREFIX}|'
.else
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's|%%PREFIX%%|${PREFIX}|' \
		| ${GREP} -v "ln"
.endif

.include <bsd.port.post.mk>
