# New ports collection makefile for:    Microsoft FrontPage Extensions
# Date created:         Tue Feb  4 13:59:20 CST 2003
# Whom:                 hetzels@westbend.net
#
# $FreeBSD$
#

PORTNAME=	mod_frontpage
PORTVERSION=	5.0.2.2635
PORTREVISION=	0
CATEGORIES=	www
MASTER_SITES=	# Requries manual fetch of files from http://www.rtr.com/
PKGNAMESUFFIX=	${AP_VER}
DISTFILES=	${FRONTPAGE}

MAINTAINER=	hetzels@westbend.net
COMMENT=	Microsoft mod_frontpage (by RTR) for Apache ${FP_AP_VER}

RUN_DEPENDS=	${LOCALBASE}/${FP_SETPERM}:${PORTSDIR}/www/frontpage

DIST_SUBDIR=	fp${PORTVERSION:S/.//g}

ONLY_FOR_ARCHS=	i386 ia64 amd64 alpha sparc64

USE_REINPLACE=	yes

WANT_APACHE?=	2

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../apache2/Makefile.modules.3rd"
.include "${.CURDIR}/../frontpage/Makefile.fp.common"

.ifdef WITH_APACHE2
FP_AP_VER=	2.0
APACHE=		apache2
.else
FP_AP_VER=	1.3
APACHE=		apache
.endif

FPDIR=		frontpage/version${FP_VER}
FP_INSTALL=	${FPDIR}/fp_install.sh
FP_SETPERM=	${FPDIR}/set_default_perms.sh

.ifdef WITH_MODFP_COMPAT
FP_ARGS=	-DIMPROVED_MODFP_COMPAT
.endif
.ifdef WITH_DISABLED
FP_ARGS+=	-DDEFAULT_TO_OFF
.endif

NO_WRKSUBDIR=	yes
EXTRACT_FILES=	${FPDIR}/apache-fp/mod_frontpage.c \
		${FPDIR}/apache2/mod_fpcgid.c \
		${FPDIR}/apache2/mod_fpcgid.h \
		${FPDIR}/apache2/mod_frontpage.c \
		${FPDIR}/apache2/mod_frontpage.h \
		${FPDIR}/apache2/mod_suexec.h

PLIST_SUB+=	FP_VER=${FP_VER} \
		APACHE=${APACHE}

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@if ! (cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${_DISTDIR}/${FRONTPAGE} ${EXTRACT_AFTER_ARGS} ${EXTRACT_FILES}); \
	then \
		exit 1; \
	fi

do-build:
.ifdef WITH_APACHE2
	@${APXS} -c -Wc,-DFREEBSD ${FP_ARGS} ${WRKDIR}/${FPDIR}/apache2/mod_frontpage.c \
		${WRKDIR}/${FPDIR}/apache2/mod_fpcgid.c
.else
	@(cd ${WRKDIR}/${FPDIR}/apache-fp && \
		${APXS} -c -Wc,-DFREEBSD ${FP_ARGS} ${WRKDIR}/${FPDIR}/apache-fp/mod_frontpage.c)
.endif

do-install:
.ifdef WITH_APACHE2
	@${APXS} -i -a -n frontpage ${WRKDIR}/${FPDIR}/apache2/mod_frontpage.la
.else
	@${APXS} -i -a -n frontpage ${WRKDIR}/${FPDIR}/apache-fp/mod_frontpage.so
.endif

post-install:
.if (${PREFIX} != "/usr/local")
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's|%%PREFIX%%|${PREFIX}|'
.else
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's|%%PREFIX%%|${PREFIX}|' \
		| ${GREP} -v "ln"
.endif

.include <bsd.port.post.mk>
