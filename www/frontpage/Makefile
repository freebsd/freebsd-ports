# New ports collection makefile for:    Microsoft FrontPage Extensions
# Date created:         Sat Oct 24 16:30:00 CDT 2001
# Whom:                 hetzels@westbend.net
#
# $FreeBSD$
#

PORTNAME=	frontpage
PORTVERSION=	5.0.2.4803
CATEGORIES=	www
MASTER_SITES=	# Needs to be manually fetched from http://www.rtr.com
DISTFILES=	${FRONTPAGE}

MAINTAINER=	swhetzel@gmail.com
COMMENT=	Microsoft Frontpage 2002 Extensions

DEPRECATED=	End-of-life occurred on June 30, 2006.
EXPIRATION_DATE=2006-12-01

EXTRACT_ONLY=
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
BATCH?=		NO

USE_PERL5_RUN=	yes

USE_RC_SUBR=	yes
RC_SCRIPTS=	frontpage:0010
RC_SCRIPT_PREFIX=	${RC_SCRIPTS:S/${RC_SCRIPTS:C/:[^:]+$//}//:S/://}
RC_SCRIPT=	${RC_SCRIPTS:C/:[^:]+$//}

SUB_FILES=	${RC_SCRIPT}.sh
SUB_LIST+=	RC_SUBR=${RC_SUBR} PERL5=${PERL} FP_VER=${FP_VER}

.include <bsd.port.pre.mk>
.include "${.CURDIR}/Makefile.fp.common"

.if (${OSVERSION} >= 700007 || ( ${OSVERSION} < 700000 && ${OSVERSION} >= 600101 ))
RCD_SCRIPT=	${RC_SCRIPT}
.else
RCD_SCRIPT=	${RC_SCRIPT_PREFIX}.${RC_SCRIPT}.sh
.endif
PLIST_SUB+=	RCD_SCRIPT=${RCD_SCRIPT}

FP_INSTALL=	${FP_DIR}/fp_install.sh
FP_SETPERM=	${FP_DIR}/set_default_perms.sh
FP_DOCS=	readme.htm readme_apache_dso.txt LICENSE.TXT

EXTRACT_FILES=	${FP_INSTALL} ${FP_SETPERM}

.if ${ARCH} == alpha
FP_MACHINE=	alpha
.elif ${ARCH} == sparc64
FP_MACHINE=	solaris
.elif defined(WANT_BSDI_EXTENSIONS)
FP_MACHINE=	bsdi
.elif ${ARCH} == i386
.if ${OSVERSION} >= 500000
LIB_DEPENDS+=	c.4:${PORTSDIR}/misc/compat4x
FP_MACHINE=	freebsd
.endif
.elif ${ARCH} == amd64
.if ${OSVERSION} >= 500000
LIB_DEPENDS+=	c.4:${PORTSDIR}/misc/compat4x
.endif
.if ${OSVERSION} >= 600000
LIB_DEPENDS+=	crypt.2:${PORTSDIR}/misc/compat5x
.endif
FP_MACHINE=	freebsd
.endif

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@if ! (cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${_DISTDIR}/${FRONTPAGE} ${EXTRACT_AFTER_ARGS} ${EXTRACT_FILES}); \
	then \
		exit 1; \
	fi

post-patch:
.if !defined(PATCH_DEBUG)
	@${REINPLACE_CMD} -E -e 's:PREFIX:${PREFIX}:g' \
			  -e 's:(machine=\")freebsd\":\1${FP_MACHINE}\":g' \
			  -e 's:DOCSDIR:${DOCSDIR}:g' ${WRKDIR}/${FP_INSTALL}
.endif

do-install:
	@${ECHO_MSG} "===> Untaring FrontPage Extensions to ${PREFIX}"
	@(cd ${PREFIX} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${_DISTDIR}/${FRONTPAGE} ${EXTRACT_AFTER_ARGS})
	@${INSTALL_SCRIPT} ${WRKDIR}/${FP_INSTALL} ${PREFIX}/${FP_INSTALL}
	@${INSTALL_SCRIPT} ${WRKDIR}/${FP_SETPERM} ${PREFIX}/${FP_SETPERM}
	@${PREFIX}/${FP_SETPERM}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for DOC in ${FP_DOCS}
	@${INSTALL_DATA} ${PREFIX}/${FP_DIR}/${DOC} ${DOCSDIR}
.endfor
.endif
.for RMFILE in ${FP_DOCS} apache-fp/httpd
	@${RM}	${PREFIX}/${FP_DIR}/${RMFILE}
.endfor

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${RC_SCRIPT}.sh \
		${PREFIX}/etc/rc.d/${RCD_SCRIPT}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
