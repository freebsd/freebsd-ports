# New ports collection makefile for: The Globus Toolkit
# Date created: 4 April 2005
# Whom:   brooks@aero.org
#
# $FreeBSD$
#

PORTNAME=	globus
PORTVERSION=	4.0.3
PORTREVISION=	20060825
CATEGORIES=	net java parallel
MASTER_SITES=	ftp://ftp.globus.org/pub/gt4/4.0/${PORTVERSION}/%SUBDIR%/src/:installers,updates
MASTER_SITE_SUBDIR=	installers/:installers updates/:updates
DISTNAME=	gt${PORTVERSION}-all-source-installer
DISTFILES=	${INSTALLER}:installers \
		${UPDATE_BUNDLES:C/:[^:]*$/${BUNDLE_SUFX}:updates/}
DIST_SUBDIR=	globus
EXTRACT_ONLY=	${INSTALLER}

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Grid computing toolkit

BUILD_DEPENDS=	gtar:${PORTSDIR}/archivers/gtar
RUN_DEPENDS=	${LOCALBASE}/bin/sudo:${PORTSDIR}/security/sudo

INSTALLER=	${DISTNAME}${EXTRACT_SUFX}
BUNDLE_SUFX=	.tar.gz

# Updates from http://www.globus.org/toolkit/advisories.html
#
# The format is <file name minus .tar.gz>:<flavor list>
#UPDATE_BUNDLES+=	globus_gass_copy-3.21:%FLAVOR%,%FLAVOR%pthr

HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_LDCONFIG=	${GLOBUS_LOCATION}/lib

GLOBUS_BASE?=	globus
GLOBUS_LOCATION=${TARGETDIR}/${GLOBUS_BASE}
TMP_GLOBUS_LOCATION=	${WRKDIR}/globus
TMP_GLOBUS_ENV=	GLOBUS_LOCATION=${TMP_GLOBUS_LOCATION} \
		GPT_LOCATION=${TMP_GLOBUS_LOCATION} \
		PATH=${TMPBINDIR}:${PATH} \
		LD_LIBRARY_PATH=${TMP_GLOBUS_LOCATION}/lib
TMPBINDIR=	${WRKDIR}/tmpbin

CONFIGURE_ARGS=	--prefix=${TMP_GLOBUS_LOCATION} ${CONFIGURE_TARGET}
CONFIGURE_ENV+=	${TMP_GLOBUS_ENV}
MAKE_ENV+=	${TMP_GLOBUS_ENV}

PLIST_SUB+=	BASE_FLAVOR=${BASE_FLAVOR} \
		GLOBUS_BASE=${GLOBUS_BASE} \
		PERL_ARCH=${PERL_ARCH}

MANPREFIX=	${GLOBUS_LOCATION}
.include "${.CURDIR}/Makefile.man"

PKGMESSAGE=	${WRKDIR}/pkg-message

SUB_FILES=	pkg-message
SUB_LIST+=	GLOBUS_LOCATION=${GLOBUS_LOCATION}

USE_JAVA=	yes
JAVA_VERSION=	1.4+
JAVA_OS=	native
JAVA_BUILD=	jdk
JAVA_RUN=	jdk
CONFIGURE_ENV+=	JAVA_HOME=${JAVA_HOME} JAVAC_PATH=${JAVAC}
ANT=		${LOCALBASE}/bin/ant
BUILD_DEPENDS+=	${ANT}:${PORTSDIR}/devel/apache-ant
CONFIGURE_ENV+=	ANT_PATH=${ANT}

CPIOARGS=       --quiet -pdum

.include <bsd.port.pre.mk>

.if (${ARCH} == "i386") || (${ARCH} == "powerpc")
ARCHBITS?=32
PERL_ARCH=	${ARCH}-freebsd-64int
.else
ARCHBITS?=64
PERL_ARCH=	${ARCH}-freebsd
.endif
BASE_FLAVOR=	gcc${ARCHBITS}dbg

post-patch:
	cd ${WRKSRC}/gpt/packaging_tools/etc/ ; \
	    tar xfzv globus_core-src.tar.gz ; \
	    ${CP} ${WRKSRC}/source-trees/core/source/configure globus_core-4.30/ ; \
	    ${CP} ${WRKSRC}/source-trees/core/source/config/accompiler.m4 globus_core-4.30/config ; \
	    tar cfzv globus_core-src.tar.gz globus_core-4.30 ; \
	    ${RM} -r globus_core-4.30

# HACK: this is under defined(GNU_CONFIGURE) in do-configure, but we
# have to do it ourselves because we can't set GNU_CONFIGURE and install
# under WRKDIR.  See ports/67436 for a solution.
pre-configure:
	@CONFIG_GUESS_DIRS=$$(${FIND} ${WRKDIR} -name config.guess -o -name config.sub \
		| ${XARGS} -n 1 ${DIRNAME}); \
	for _D in $${CONFIG_GUESS_DIRS}; do \
		${CP} -f ${TEMPLATES}/config.guess $${_D}/config.guess; \
		${CHMOD} a+rx $${_D}/config.guess; \
		${CP} -f ${TEMPLATES}/config.sub $${_D}/config.sub; \
		${CHMOD} a+rx $${_D}/config.sub; \
	done

pre-build:
	${MKDIR} ${WRKSRC}/gpt/packaging_tools/etc/gpt
	${MKDIR} ${TMPBINDIR}
	${LN} -s `which gmake` ${TMPBINDIR}/make || ${TRUE}
	ls -l ${TMPBINDIR}

post-build:
.for _B in ${UPDATE_BUNDLES}
	${SETENV} ${TMP_GLOBUS_ENV} ${TMP_GLOBUS_LOCATION}/sbin/gpt-build \
	    --builddir=${WRKDIR}/BUILD -update \
	    ${DISTDIR}/${DIST_SUBDIR}/${_B:C/:[^:]*$/${BUNDLE_SUFX}/} \
	    ${_B:C/^.*://:S/%FLAVOR%/${BASE_FLAVOR}/g:S/,/ /g}
.endfor
	${FIND} ${TMP_GLOBUS_LOCATION}/etc/gpt/packages/ -name bak -depth 2 | \
	    ${XARGS} ${RM} -rf
	${FIND} ${TMP_GLOBUS_LOCATION} -type d -name CVS | xargs ${RM} -r
	${RM} -rf ${TMP_GLOBUS_LOCATION}/man/cat*

do-install:
	@${MKDIR} ${GLOBUS_LOCATION}
	@cd ${TMP_GLOBUS_LOCATION} && \
	    ${FIND} . -name \*.orig ${EXCEPTFILES:S/^/-o -name /} -o -print | \
	    ${CPIO} ${CPIOARGS} -R ${BINOWN}:${BINGRP} ${GLOBUS_LOCATION}

post-install:
	@${CAT} ${PKGMESSAGE}

build-plist:
	@${RM} -rf ${PLIST} && ${TOUCH} ${PLIST}
	@${FIND} ${TMP_GLOBUS_LOCATION}/* -name man -prune -o -type l | \
	    ${SED} -e 's|${TMP_GLOBUS_LOCATION}|%%GLOBUS_BASE%%|' \
	    -e 's|${BASE_FLAVOR}|%%BASE_FLAVOR%%|g' \
	    -e 's|${PERL_ARCH}|%%PERL_ARCH%%|g' | \
	    ${GREP} -v %%GLOBUS_BASE%%/man | \
	    ${SORT} >> ${PLIST}
	@${FIND} ${TMP_GLOBUS_LOCATION}/* -name man -prune -o -type f | \
	    ${SED} -e 's|${TMP_GLOBUS_LOCATION}|%%GLOBUS_BASE%%|' \
	    -e 's|${BASE_FLAVOR}|%%BASE_FLAVOR%%|g' \
	    -e 's|${PERL_ARCH}|%%PERL_ARCH%%|g' | \
	    ${GREP} -v %%GLOBUS_BASE%%/man | \
	    ${SORT} >> ${PLIST}
	@${FIND} ${TMP_GLOBUS_LOCATION} -type d | \
	    ${SED} -e 's|${TMP_GLOBUS_LOCATION}|@dirrm %%GLOBUS_BASE%%|' \
	    -e 's|${BASE_FLAVOR}|%%BASE_FLAVOR%%|g' \
	    -e 's|${PERL_ARCH}|%%PERL_ARCH%%|g' | \
	    ${SORT} -r >> ${PLIST}
	@echo "# Do not edit!  Auto-generated file." > ${.CURDIR}/Makefile.man
	@echo "# See build-plist target in Makefile." >> ${.CURDIR}/Makefile.man
	@echo "#" >> ${.CURDIR}/Makefile.man
	@${FIND} ${TMP_GLOBUS_LOCATION}/man/ -type l | \
	    ${XARGS} -n1 -I link ${SH} -c 'echo MLINKS+= `realpath link` link' | \
	    ${SED} -e 's|${TMP_GLOBUS_LOCATION}/man/[cm]a[nt]./||g' | \
	    ${SORT} >> ${.CURDIR}/Makefile.man
	@${FIND} ${TMP_GLOBUS_LOCATION}/man/ -type f | \
	     ${SED} -e 's|${TMP_GLOBUS_LOCATION}/man/man\([0-9LN]\)/\(.*\)|MAN\1+=\2|' \
	    -e 's|${BASE_FLAVOR}|$${BASE_FLAVOR}|g' | \
	     ${SORT} >> ${.CURDIR}/Makefile.man

.include <bsd.port.post.mk>
