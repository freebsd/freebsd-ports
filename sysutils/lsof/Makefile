# ex:ts=8
# New ports collection makefile for:    lsof
# Version required:     3.87
# Date created:         Sat July 20, 1996
# Whom:                 David O'Brien (obrien@FreeBSD.org)
#
# $Id: Makefile,v 1.30 1998/12/16 19:50:40 billf Exp $
#

DISTNAME=	lsof_4.39_W
PKGNAME=	lsof-4.39
CATEGORIES=	sysutils
MASTER_SITES=	ftp://vic.cc.purdue.edu/pub/tools/unix/lsof/  \
		ftp://ftp.cert.dfn.de/pub/tools/admin/lsof/  \
		ftp://ftp.auscert.org.au/pub/mirrors/vic.cc.purdue.edu/lsof/  \
		ftp://ftp.web.ad.jp/pub/UNIX/tools/lsof/  \
		ftp://ftp.sunet.se/pub/unix/admin/lsof/

MAINTAINER=     obrien@FreeBSD.org

WRKSRC=		${WRKDIR}/${SRCBALL_NAME}
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=	-n freebsd
MAN8=		lsof.8

.if defined(PACKAGE_BUILDING)
.if !exists(/usr/src/sys/miscfs/fdesc/fdesc.h)
BROKEN=	'please install kernel source for offical package builds'
.endif
.endif

SRCBALL_NAME=	${DISTNAME:S/_W$//}

post-extract:
	@( cd ${WRKDIR} ; \
	EXPMD5=`/usr/bin/grep MD5 README.${SRCBALL_NAME} | sed 's/^[ ]*//'` ; \
	CALCMD5=`${MD5} ${SRCBALL_NAME}.tar` ; \
	if [ "$${EXPMD5}"X != "$${CALCMD5}"X ]; then \
		echo "Expected and calculated MD5 signatures don't agree." ; \
		echo "($$EXPMD5 != $$CALCMD5)" ; \
		exit 1 ; \
	fi ; \
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS:S/z//} ${SRCBALL_NAME}.tar \
	)
	@( cd ${WRKSRC} ; echo "y" | ./Inventory || exit 1 )

#pre-patch:
#	@${ECHO_MSG} "===>  Applying distribution patches for ${PKGNAME}"
#	@${SED} -e "s|^--- d|--- dialects/freebsd/d|"  \
#		${DISTDIR}/freebsd_3.0_patch > ${WRKDIR}/p
#	${PATCH} ${PATCH_DIST_ARGS} < ${WRKDIR}/p

do-install:
	${INSTALL} ${COPY} ${STRIP} -o ${BINOWN} -m 2755 -g kmem ${WRKSRC}/lsof ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/lsof.man ${PREFIX}/man/man8/lsof.8
	@${MKDIR} ${PREFIX}/share/lsof
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/* ${PREFIX}/share/lsof
	@/bin/chmod 0444 ${PREFIX}/share/lsof/00*

post-install:
	@${ECHO} "************************************************************"
	@${ECHO} "*                      W a r n i n g                       *"
	@${ECHO} "* A more capable version of LSOF is built if you have      *"
	@${ECHO} "* kernel source installed and /sys exists.                 *"
	@${ECHO} "* If this is the case, please ensure /sys is consistant    *"
	@${ECHO} "* with respect to your running kernel (i.e. not new than). *"
	@${ECHO} "************************************************************"


.include <bsd.port.mk>
