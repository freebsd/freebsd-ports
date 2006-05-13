# Ports collection makefile for:        sge
# Date created:				Fri Jul 11, 2003
# Whom:					Brooks Davis <brooks@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sge
PORTVERSION=	${SGE_VERSION}
PORTREVISION=	1
CATEGORIES=	sysutils parallel
MASTER_SITES=	http://gridengine.sunsource.net/files/documents/7/51/
MASTER_SITES+=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brooks
DISTNAME=	sge-V60u7_1_TAG-src

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Sun Grid Engine, a batch queueing system

FETCH_DEPENDS=	wget:${PORTSDIR}/ftp/wget

# We have to use wget because the master site required cookies to
# download the file.
DISABLE_SIZE=	yes
FETCH_CMD=	wget -c

OPTIONS=	BDB "Use DB based spooler (currently broken)" off \
		DRMAA "Support the Java DRMAA API (requires native Java)" on \
		QMON "Qmon support (requires X and Motif)" on

CONFLICTS=	sge-5* sgeee-[0-9]*

EXTRA_PATCHES=	${FILESDIR}/sge-freebsd-pdc.diff

.if !exists(/usr/include/sys/_pthreadtypes.h)
EXTRA_PATCHES=	${FILESDIR}/pthread-types.diff
.endif
NOT_FOR_ARCHS=	alpha

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	${SGE_ROOT}/lib/${SGE_ARCH}

# We have to use fetch because the master site required cookies to
# download the file.
FETCH_DEPENDS=	wget:${PORTSDIR}/ftp/wget
DISABLE_SIZE=	yes
FETCH_CMD=	wget -c

SGE_BASE?=	sge
SGE_ROOT=	${PREFIX}/${SGE_BASE}
SGE_ARCH=	fbsd-${ARCH}
SGE_VERSION=	6.0.7.1
SGE_RELEASE=	6.0u7_1

PLIST_SUB+=	SGE_ARCH=${SGE_ARCH}
PLIST_SUB+=	SGE_BASE=${SGE_BASE}

SUB_FILES=	pkg-message pkg-install
SUB_LIST+=	SGE_BASE=${SGE_BASE}

USE_RC_SUBR=	sge.sh

PKGMESSAGE=	${WRKDIR}/pkg-message
PKGINSTALL=	${WRKDIR}/pkg-install
WRKSRC=		${WRKDIR}/gridengine/source
TMP_SGE_ROOT=	${WRKDIR}/sgeroot
AIMK_CMD=	${SETENV} ${AIMK_ENV} ./aimk ${AIMK_ARGS}

INST_PROGS=	man common \
		sge_qmaster \
		sge_execd \
		sge_shadowd \
		sge_schedd \
		sge_shepherd \
		sge_coshepherd \
		qstat \
		qsub \
		qalter \
		qconf \
		qdel \
		qacct \
		qmod \
		qsh \
		utilbin \
		jobs \
		qhost \
		qmake \
		qtcsh \
		qping \
		qloadsensor.exe \
		sgepasswd \
		${QMON}

MANPREFIX=	${SGE_ROOT}
.include "${.CURDIR}/Makefile.man"
EXCEPTFILES=	arc_depend_irix.asc arc_depend_solaris.asc man testsuite

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 503000
.if ${OSVERSION} < 500000
BROKEN= 	"does not build without libpthread"
.else
IGNORE= 	is not supported for FreeBSD < 5.3
.endif
.endif

.if defined(WITH_BDB)
LIB_DEPENDS=	db-4.2:${PORTSDIR}/databases/db42
PLIST_SUB+=	BDB_SPOOL=
.else
AIMK_ARGS+=	-spool-classic
PLIST_SUB+=	BDB_SPOOL="@comment "
.endif

.if defined(WITH_DRMAA)
USE_JAVA=	yes
JAVA_VERSION=	1.4+
JAVA_OS=	native
JAVA_BUILD=	jdk
JAVA_RUN=	jre
.include "${PORTSDIR}/Mk/bsd.java.mk"
ANT?=		${LOCALBASE}/bin/ant
BUILD_DEPENDS+=	${ANT}:${PORTSDIR}/devel/apache-ant
PLIST_SUB+=	DRMAA=
AIMK_ENV+=	JAVA_HOME=${JAVA_HOME}
.else
AIMK_ARGS+=	-no-java -no-jni
PLIST_SUB+=	DRMAA="@comment "
.endif

.if defined(WITH_QMON)
USE_MOTIF=	yes
PLIST_SUB+=	QMON=
QMON=		qmon
.else
AIMK_ARGS+=	-no-qmon
PLIST_SUB+=	QMON="@comment "
QMON=		noqmon
.endif

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
	@${REINPLACE_CMD} -e 's|^CC = gcc|CC = ${CC}|' \
	    -e 's|^CPP = gcc -E|CPP = ${CPP}|' \
	    ${WRKSRC}/3rdparty/qmake/FREEBSD_*/Makefile \
	    ${WRKSRC}/3rdparty/qmake/FREEBSD_*/glob/Makefile \
	    ${WRKSRC}/3rdparty/qtcsh/FREEBSD_*/Makefile
	@${RM} ${WRKSRC}/dist/util/arch_variables.orig
	@${RM} ${WRKSRC}/dist/util/install_modules/inst_common.sh.orig
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} \
	    ${REINPLACE_CMD} "s|-g -O2|${CFLAGS}|"
	@${SED} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	    -e 's|%%OPENSSLBASE%%|${OPENSSLBASE}|g' < \
	    ${FILESDIR}/aimk.private > ${WRKSRC}/aimk.private
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	    -e 's|%%OPENSSLBASE%%|${OPENSSLBASE}|g' \
	    ${WRKSRC}/scripts/distinst.site

do-build:
	cd ${WRKSRC} && ${AIMK_CMD} -only-depend
	cd ${WRKSRC} && ./scripts/zerodepend
	cd ${WRKSRC} && ${AIMK_CMD} depend
	cd ${WRKSRC} && \
	    ${AIMK_CMD} -debug && \
	    ${AIMK_CMD} -man ${SGE_PRODUCT} &&
	${MKDIR} ${TMP_SGE_ROOT}
	cd ${WRKSRC} && ${SETENV} SGE_ROOT=${TMP_SGE_ROOT} \
	    ./scripts/distinst -local -libs ${SGE_ARCH} -- ${INST_PROGS}

do-install:
	${MKDIR} ${SGE_ROOT}
	cd ${TMP_SGE_ROOT} && \
	    ${FIND} . | ${TAR} cTf - - | ${TAR} xUCf ${SGE_ROOT} -
	cd ${SGE_ROOT} && ${SETENV} SGE_ROOT=${SGE_ROOT} util/setfileperm.sh -auto ${SGE_ROOT}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/../doc && ${FIND} * \( -name CVS \
	    ${EXCEPTFILES:S/^/-o -name /} \) -a -prune -o -type f -print \
	    | ${TAR} cTf - - | ${TAR} xUCf ${DOCSDIR} -
.endif

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}
	@${ECHO}

# Automaticly produce the offical machine dependent bits tarball from
# the temporary root.  This can be used if FreeBSD machines are to be
# included in a shared SGE installation.
release-tar: build
	cd ${TMP_SGE_ROOT} && \
	    ${TAR} cfvz ${.CURDIR}/sge-${SGE_RELEASE}-bin-${SGE_ARCH}.tar.gz \
	    `${FIND} . -name ${SGE_ARCH}`

#########################################################################
# Maintainer support below this line.  No user servicable parts inside. #
#########################################################################

# Build a pkg-plist and Makefile.man
build-plist: build
#.if defined(WITHOUT_BDB) || defined(WITHOUT_JAVA) || defined(WITHOUT_QMON)
#	@echo "ERROR: All OPTIONS must be enabled to build plist!" && ${FALSE}
#.endif
	@${FIND} ${TMP_SGE_ROOT}/* -name man -prune -o \
	    \( -type f -o -type l \) -print | \
	    ${SORT} | \
	    ${SED} -e 's|^${TMP_SGE_ROOT}|%%SGE_BASE%%|' \
		-e 's|${SGE_ARCH}|%%SGE_ARCH%%|' \
		-e 's|\(.*libspool[bc].so\)|%%BDB_SPOOL%%\1|' \
		-e 's|\(.*libXltree.so\)|%%QMON%%\1|' \
		-e 's|\(.*qmon.*\)|%%QMON%%\1|' \
	    > ${PLIST}
	@${FIND} ${WRKSRC}/../doc \( -name CVS \
	    ${EXCEPTFILES:S/^/-o -name /} \) -a -prune -o -type f -print | \
	    ${SORT} | \
	    ${SED} -e 's|${WRKSRC}/../doc|%%PORTDOCS%%%%DOCSDIR%%|' \
	    >> ${PLIST}
	@${FIND} ${TMP_SGE_ROOT}/* -type d | \
	    ${SORT} -r | \
	    ${SED} -e 's|^${TMP_SGE_ROOT}|@dirrm %%SGE_BASE%%|' \
		-e 's|${SGE_ARCH}|%%SGE_ARCH%%|' \
		-e 's|\(.*qmon.*\)|%%QMON%%\1|' \
	    >> ${PLIST}
	@${FIND} ${WRKSRC}/../doc \( -name CVS \
	    ${EXCEPTFILES:S/^/-o -name /} \) -a -prune -o -type d -print | \
	    ${SORT} -r | \
	    ${SED} -e 's|${WRKSRC}/../doc|%%PORTDOCS%%@dirrm %%DOCSDIR%%|' \
	    >> ${PLIST}
	@echo '@unexec rmdir %D/%%SGE_BASE%%/ 2>/dev/null || ( echo "Configuration information saved.  If you will *NOT* use this package anymore," && echo "please remove %D/%%SGE_BASE%% and its contents manually.")' >> ${PLIST}
	@echo "# Do not edit!  Auto-generated file." > ${.CURDIR}/Makefile.man
	@echo "# See build-plist target in Makefile." >> ${.CURDIR}/Makefile.man
	@echo "#" >> ${.CURDIR}/Makefile.man
	@${FIND} ${TMP_SGE_ROOT}/man -type f | ${XARGS} ${GREP} -H ^\\.so | \
	    ${SED} \
	    -e 's|.*/\([^ :/][^ :/]*\):.*/\([^ :/][^ :/]*\)$$|MLINKS+=\2 \1|' \
	    >> ${.CURDIR}/Makefile.man
	@${FIND} ${TMP_SGE_ROOT}/man -type f | ${XARGS} ${GREP} -L ^\\.so | \
	    ${SED} -e 's|.*man\([0-9LN]\)/\(.*\)|MAN\1+=\2|' \
	    >> ${.CURDIR}/Makefile.man

.include <bsd.port.post.mk>
