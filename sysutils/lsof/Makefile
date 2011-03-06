# ex:ts=8
# Ports collection makefile for:  lsof
# Date created:			  Sat July 20, 1996
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	lsof
PORTVERSION=	4.85C
PORTEPOCH=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://www.SpringDaemons.com/stas/ \
		http://ftp.cerias.purdue.edu/pub/tools/unix/sysutils/lsof/ \
		ftp://lsof.itap.purdue.edu/pub/tools/unix/lsof/  \
		ftp://lsof.itap.purdue.edu/pub/tools/unix/lsof/NEW/ \
		http://www.lerctr.org/lsof/ \
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
DISTNAME=	${PORTNAME}_${PORTVERSION}${DISTNAME_SUFFIX}

MAINTAINER=	ler@lerctr.org
COMMENT=	Lists information about open files (similar to fstat(1))

#Please leave the below line in for the next clean up.
FIXUP_RELEASE=	YES
.if defined(FIXUP_RELEASE)
DISTNAME_SUFFIX=.freebsd
.else
SRCBALL_NAME=	${DISTNAME:S/_W$//}_src
WRKSRC=		${WRKDIR}/${DISTNAME}/${SRCBALL_NAME}
.endif

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=	-n freebsd
CONFIGURE_ENV=	LSOF_CC="${CC}"
FREEBSD_SYS?=	${SRC_BASE}/sys
PLIST_FILES=	sbin/lsof
MAN8=		lsof.8

.if !defined(FIXUP_RELEASE)
post-extract:
	@( cd ${WRKDIR}/${DISTNAME} ; \
	EXPMD5=`${SED} -n 's/^[[:blank:]]*\(MD5*=*\)/\1/p' README.${DISTNAME}` ; \
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

post-install:
	cd ${PREFIX} && \
	    ${FIND} -s share/lsof -type f -o -type l >>${TMPPLIST} ;\
	    ${FIND} -d share/lsof -type d \
	        | ${SED} -e 's/^/@dirrm /g' >>${TMPPLIST}

.include <bsd.port.mk>
