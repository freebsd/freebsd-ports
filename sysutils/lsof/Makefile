# Created by: David O'Brien <obrien@FreeBSD.org>
# $FreeBSD$

# note: If someone has a fix for a particular ARCH please feel free
#       to commit it.  I (ler) don't have access to all the ARCH's

PORTNAME=	lsof
DISTVERSION=	4.93.2
PORTREVISION=	10
PORTEPOCH=	8
CATEGORIES=	sysutils

MAINTAINER=	ler@FreeBSD.org
COMMENT=	Lists information about open files (similar to fstat(1))

LICENSE=	lsof
LICENSE_NAME=	lsof
LICENSE_FILE=	${FILESDIR}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		shebangfix tar:bzip2

HAS_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	lsof-org

OPTIONS_DEFINE_powerpc64=	AIM BOOKE
OPTIONS_DEFAULT_powerpc64=	AIM

AIM_DESC=	Set for AIM hardware
AIM_CFLAGS=	-DAIM
BOOKE_DESC=	Set for BOOKE hardware
BOOKE_CFLAGS=	-DBOOKE

CFLAGS_powerpc=	-DAIM
CFLAGS_powerpcspe=	-DBOOKE

SHEBANG_FILES=	scripts/sort_res.perl5

.include <bsd.port.pre.mk>

CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=	-n freebsd
CONFIGURE_ENV=	LSOF_CC="${CC}" FREEBSD_SYS="${SRC_BASE}/sys"

# PPC64 needs -lzpool for reasons unknown.  If someone can
# figure out why, I (ler) am all ears.
.if ${ARCH} == powerpc64 || ${ARCH} == powerpc
CONFIGURE_ENV+=	LSOF_CFGL="-lzpool"
. endif

.if !exists(${SRC_BASE}/sys/kern/kern_lockf.c)
IGNORE+=		requires kernel sources
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lsof ${STAGEDIR}${PREFIX}/sbin
	(cd ${WRKSRC} && ${SED} 's/\\$$/\\DUMMY/' Lsof.8 | mandoc -T man | ${SED} 's/DUMMY$$//' > ${WRKSRC}/lsof.8)
	${INSTALL_MAN} ${WRKSRC}/lsof.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/lsof.8
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/lsof
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/* ${STAGEDIR}${PREFIX}/share/lsof
	@${CHMOD} 0444 ${STAGEDIR}${PREFIX}/share/lsof/00*

.include <bsd.port.post.mk>
