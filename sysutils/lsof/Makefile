# Created by: David O'Brien <obrien@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lsof
DISTVERSION=	4.90G
PORTREVISION=	1
PORTEPOCH=	8
CATEGORIES=	sysutils
MASTER_SITES=	http://ftp.cerias.purdue.edu/pub/tools/unix/sysutils/lsof/ \
		ftp://lsof.itap.purdue.edu/pub/tools/unix/lsof/  \
		ftp://lsof.itap.purdue.edu/pub/tools/unix/lsof/NEW/ \
		LOCAL/ler/lsof \
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

MAINTAINER=	ler@FreeBSD.org
COMMENT=	Lists information about open files (similar to fstat(1))

LICENSE=lsof
LICENSE_NAME=lsof
LICENSE_FILE=${FILESDIR}/LICENSE
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
