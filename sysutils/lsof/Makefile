# ex:ts=8
# Ports collection makefile for:  lsof
# Date created:			  Sat July 20, 1996
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	lsof
PORTVERSION=	4.76.1.1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://lsof.itap.purdue.edu/pub/tools/unix/lsof/  \
		ftp://lsof.itap.purdue.edu/pub/tools/unix/lsof/NEW/ \
		ftp://ftp.ayamura.org/pub/lsof/ \
		ftp://ftp.ayamura.org/pub/lsof/NEW/ \
		ftp://ftp.cerias.purdue.edu/pub/tools/unix/sysutils/lsof/ \
		ftp://ftp.cerias.purdue.edu/pub/tools/unix/sysutils/lsof/NEW/ \
		ftp://gd.tuwien.ac.at/utils/admin-tools/lsof/ \
		ftp://gd.tuwien.ac.at/utils/admin-tools/lsof/NEW/ \
		ftp://ftp.sunet.se/pub/unix/admin/lsof/  \
		ftp://ftp.sunet.se/pub/unix/admin/lsof/NEW/ \
		ftp://ftp.cert.dfn.de/pub/tools/admin/lsof/  \
		ftp://ftp.cert.dfn.de/pub/tools/admin/lsof/NEW/ \
		ftp://ftp.tau.ac.il/pub/unix/admin/
FIXUP_RELEASE=
.if defined(FIXUP_RELEASE)
DISTNAME=	${PORTNAME}_4.77A.freebsd
.else
DISTNAME=	${PORTNAME}_${PORTVERSION}
.endif

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	Lists information about open files (similar to fstat(1))

.if defined(FIXUP_RELEASE)
WRKSRC=		${WRKDIR}/${DISTNAME}
.else
WRKSRC=		${WRKDIR}/${DISTNAME}/${SRCBALL_NAME}
.endif
USE_BZIP2=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=	-n freebsd
CONFIGURE_ENV=	LSOF_CC="${CC}"
FREEBSD_SYS?=	/usr/src/sys
PLIST_FILES=	sbin/lsof
MAN8=		lsof.8

SRCBALL_NAME=	${DISTNAME:S/_W$//}_src

.if !defined(FIXUP_RELEASE)
post-extract:
	@( cd ${WRKDIR}/${DISTNAME} ; \
	EXPMD5=`${GREP} MD5 README.${DISTNAME} | ${SED} 's/[ 	]*//'` ; \
	CALCMD5=`${MD5} ${SRCBALL_NAME}.tar` ; \
	if [ "$${EXPMD5}"X != "$${CALCMD5}"X ]; then \
		${ECHO} "Expected and calculated MD5 signatures don't agree." ; \
		${ECHO} "($$EXPMD5 != $$CALCMD5)" ; \
		exit 1 ; \
	fi ; \
	${CAT} ${SRCBALL_NAME}.tar ${EXTRACT_AFTER_ARGS} \
	)
	@( cd ${WRKSRC} ; ${ECHO_CMD} "y" | ./Inventory || exit 1 )
.endif

#pre-patch:
#	@${ECHO_MSG} "===>  Applying distribution patches for ${PKGNAME}"
#	@${SED} -e "s|^--- d|--- dialects/freebsd/d|"  \
#		${DISTDIR}/freebsd_3.0_patch > ${WRKDIR}/p
#	${PATCH} ${PATCH_DIST_ARGS} < ${WRKDIR}/p

do-install:
	${INSTALL} ${COPY} ${STRIP} -o ${BINOWN} -m 2755 -g kmem ${WRKSRC}/lsof ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/lsof.8 ${MAN8PREFIX}/man/man8/lsof.8
	@${MKDIR} ${PREFIX}/share/lsof
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/* ${PREFIX}/share/lsof
	@${CHMOD} 0444 ${PREFIX}/share/lsof/00*

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500019
.if !exists(${FREEBSD_SYS}/miscfs/fdesc/fdesc.h)
.if defined(PACKAGE_BUILDING)
BROKEN=	'please install kernel source for official package builds'
.endif

pre-configure:
	@${ECHO} ""
	@${ECHO} "************************************************************"
	@${ECHO} "*                      W a r n i n g                       *"
	@${ECHO} "* A more capable version of LSOF is built if you have      *"
	@${ECHO} "* the complete kernel source installed.                    *"
	@${ECHO} "* If your kernel sources are somewhere other than          *"
	@${ECHO} "* /usr/src/sys, you may set the FREEBSD_SYS variable       *"
	@${ECHO} "* to the correct path.                                     *"
	@${ECHO} "************************************************************"
	@${ECHO} ""
.endif
.endif

post-install:
	cd ${PREFIX} && \
	    ${FIND} -s share/lsof -type f -o -type l >>${TMPPLIST} ;\
	    ${FIND} -d share/lsof -type d \
	        | ${SED} -e 's/^/@dirrm /g' >>${TMPPLIST}

.include <bsd.port.post.mk>
