# Ports collection makefile for:        sge
# Date created:				Fri Jul 11, 2003
# Whom:					Brooks Davis <brooks@FreeBSD.org>
#
# $FreeBSD$
# $Aero: ports/sge/Makefile,v 1.3 2004/01/21 22:26:12 brooks Exp $
#

PORTNAME=	sge
PORTVERSION=	5.3.5.20040120
CATEGORIES=	sysutils parallel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brooks

MAINTAINER=	brooks@FreeBSD.org
COMMENT?=	Sun Grid Engine, a batch queueing system

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext

USE_BZIP2=	yes
USE_OPENSSL=	yes
USE_GMAKE=	yes
USE_MOTIF=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	${SGE_ROOT}/lib/${SGE_ARCH}

SGE_BASE?=	sge
SGE_ROOT=	${PREFIX}/${SGE_BASE}
SGE_ARCH=	fbsd-${ARCH}
SGE_RELEASE=	5.3p5-snap-20040120

PLIST_SUB+=	SGE_ARCH=${SGE_ARCH}
PLIST_SUB+=	SGE_BASE=${SGE_BASE}
.if defined(PKGNAMESUFFIX)
.if ${PKGNAMESUFFIX} == ee
PLIST_SUB+=	SGE="@comment "
PLIST_SUB+=	SGEEE=
.endif
.else
PLIST_SUB+=	SGE=
PLIST_SUB+=	SGEEE="@comment "
.endif

PKGMESSAGE=	${WRKDIR}/pkg-message
WRKSRC=		${WRKDIR}/${DISTNAME}/source
MANPREFIX=	${SGE_ROOT}
MAN1=		qacct.1 qalter.1 qconf.1 qdel.1 qhold.1 qhost.1 qlogin.1 \
		qmake.1 qmod.1 qmon.1 qresub.1 qrls.1 qrsh.1 qselect.1 \
		qsh.1 qstat.1 qsub.1 qtcsh.1 sge_ckpt.1 sge_intro.1 \
		submit.1
MAN5=		access_list.5 accounting.5 calendar_conf.5 checkpoint.5 \
		complex.5 host_conf.5 hostgroup.5 project.5 qtask.5 \
		queue_conf.5 sched_conf.5 sge_aliases.5 sge_conf.5 \
		sge_h_aliases.5 sge_pe.5 sge_request.5 share_tree.5 \
		user.5 usermapping.5
MAN8=		sge_commd.8 sge_execd.8 sge_qmaster.8 sge_schedd.8 \
		sge_shadowd.8 sge_shepherd.8 sgecommdcntl.8
EXCEPTFILES=	arc_depend_irix.asc arc_depend_solaris.asc man

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" \
	    -e "s|%%X11BASE%%|${X11BASE}|g" \
	    -e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
	    ${WRKSRC}/dist/util/arch_variables \
	    ${WRKSRC}/dist/pvm/src/aimk
	@${REINPLACE_CMD} -e "s|%%CC%%|${CC}|g" -e "s|%%CXX%%|${CXX}|g" \
	    -e "s|%%CFLAGS%%|${CFLAGS}|g" -e "s|%CXXFLAGS%%|${CXXFLAGS}|g" \
	    ${WRKSRC}/aimk \
	    ${WRKSRC}/dist/pvm/src/aimk
	@${RM} ${WRKSRC}/dist/util/arch_variables.orig
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} \
	    ${REINPLACE_CMD} "s|-g -O2|${CFLAGS}|"

do-build:
	cd ${BUILD_WRKSRC} && ./aimk -only-depend
	cd ${BUILD_WRKSRC} && ./scripts/zerodepend
	cd ${BUILD_WRKSRC} && ./aimk depend
	cd ${BUILD_WRKSRC} && ./aimk -secure -debug
	cd ${BUILD_WRKSRC} && ./aimk -man ${SGE_PRODUCT}
	cd ${BUILD_WRKSRC} && ${LN} -fs ./scripts/distinst myinst

pre-install:
.if defined(MASTERDIR)
	${SH} ${MASTERDIR}/pkg-install ${PKGNAME} PRE-INSTALL
.else
	${SH} pkg-install ${PKGNAME} PRE-INSTALL
.endif

do-install:
	${MKDIR} ${SGE_ROOT}
	${CHOWN} sgeadmin:sgeadmin ${SGE_ROOT}
	cd ${BUILD_WRKSRC} && ${SETENV} SGE_ROOT=${SGE_ROOT} ./myinst -allall ${SGEEE_FLAG} ${SGE_ARCH}
	cd ${SGE_ROOT} && ${SETENV} SGE_ROOT=${SGE_ROOT} util/setfileperm.sh -auto -noresport sgeadmin sgeadmin ${SGE_ROOT}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/../doc && ${FIND} * \( -name nonexistant \
	    ${EXCEPTFILES:S/^/-o -name /} \) -a -prune -o -print \
	    | ${TAR} cTf - - | ${TAR} xUCf ${DOCSDIR} -
.endif

# Automaticly produce the offical machine dependent tarball
release-tar: install
	cd ${SGE_ROOT} && \
	    ${TAR} cfvz ${.CURDIR}/sge-${SGE_RELEASE}-bin-${SGE_ARCH}.tar.gz \
	    `find . -name ${SGE_ARCH}`

post-install:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
	    -e 's|%%SGE_BASE%%|${SGE_BASE}|g' \
	    < ${FILESDIR}/pkg-message.in > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}
	@${ECHO}

.include <bsd.port.mk>
