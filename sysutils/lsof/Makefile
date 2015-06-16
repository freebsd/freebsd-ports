# Created by: David O'Brien <obrien@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lsof
DISTVERSION=	4.89E
PORTEPOCH=	8
CATEGORIES=	sysutils
MASTER_SITES=	http://ftp.cerias.purdue.edu/pub/tools/unix/sysutils/lsof/ \
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
DISTNAME=	${PORTNAME}_${DISTVERSION}${DISTNAME_SUFFIX}

MAINTAINER=	ler@lerctr.org
COMMENT=	Lists information about open files (similar to fstat(1))

LICENSE=lsof
LICENSE_NAME=lsof
LICENSE_TEXT=Lsof has no license.  Its use and distribution are subject to these \
terms and conditions, found in each lsof source file.  (The copyright \
year in or format of the notice may vary slightly.) \
 \
    /* \
     * Copyright 2002 Purdue Research Foundation, West Lafayette, \
     * Indiana 47907.  All rights reserved. \
     * \
     * Written by Victor A. Abell \
     * \
     * This software is not subject to any license of the American \
     * Telephone and Telegraph Company or the Regents of the \
     * University of California. \
     * \
     * Permission is granted to anyone to use this software for \
     * any purpose on any computer system, and to alter it and \
     * redistribute it freely, subject to the following \
     * restrictions: \
     * \
     * 1. Neither the authors nor Purdue University are responsible \
     *    for any consequences of the use of this software. \
     * \
     * 2. The origin of this software must not be misrepresented, \
     *    either by explicit claim or by omission.  Credit to the \
     *    authors and Purdue University must appear in documentation \
     *    and sources. \
     * \
     * 3. Altered versions must be plainly marked as such, and must \
     *    not be misrepresented as being the original software. \
     * \
     * 4. This notice may not be removed or altered. \
     */
LICENSE_PERMS=	 dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

#Please leave the below line in for the next clean up.
FIXUP_RELEASE=	YES
.if defined(FIXUP_RELEASE)
DISTNAME_SUFFIX=.freebsd
.else
SRCBALL_NAME=	${DISTNAME:S/_W$//}_src
WRKSRC=		${WRKDIR}/${DISTNAME}/${SRCBALL_NAME}
.endif
HAS_CONFIGURE=	yes

USES=		shebangfix tar:bzip2
SHEBANG_FILES=	scripts/sort_res.perl5

.include <bsd.port.pre.mk>

.if !empty(ARCH:Marm*) && ((${OSVERSION} < 1001505) || (${OSVERSION} > 1100000 && ${OSVERSION} < 1100052))
BROKEN=	Not supported on ARM platform below release 10.1 or a more recent current
.endif

CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=	-n freebsd
CONFIGURE_ENV=	LSOF_CC="${CC}" FREEBSD_SYS="${SRC_BASE}/sys"

.if !exists(${SRC_BASE}/sys/kern/kern_lockf.c)
IGNORE=		requires kernel sources
.endif

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
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${SRCBALL_NAME}.tar ${EXTRACT_AFTER_ARGS} \
	)
	@( cd ${WRKSRC} ; ${ECHO_CMD} "y" | ./Inventory || exit 1 )
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lsof ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/lsof.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/lsof.8
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/lsof
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/* ${STAGEDIR}${PREFIX}/share/lsof
	@${CHMOD} 0444 ${STAGEDIR}${PREFIX}/share/lsof/00*

.include <bsd.port.post.mk>
