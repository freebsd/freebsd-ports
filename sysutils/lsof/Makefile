# note: If someone has a fix for a particular ARCH please feel free
#       to commit it.  I (ler) don't have access to all the ARCH's
PORTNAME=	lsof
DISTVERSION=	4.99.4
PORTREVISION=	2
PORTEPOCH=	8
CATEGORIES=	sysutils

MAINTAINER=	ler@FreeBSD.org
COMMENT=	Lists information about open files (similar to fstat(1))
WWW=		https://github.com/lsof-org/lsof/

LICENSE=	lsof
LICENSE_NAME=	lsof
LICENSE_FILE=	${FILESDIR}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		compiler cpe shebangfix
CPE_VENDOR=	lsof_project
USE_GITHUB=	yes
GH_ACCOUNT=	lsof-org

BUILD_DEPENDS=		${LOCALBASE}/bin/bash:shells/bash

SHEBANG_FILES=	scripts/*.pl

HAS_CONFIGURE=	yes

CFLAGS_powerpcspe=	-DBOOKE

OPTIONS_DEFINE_powerpc64=	AIM BOOKE
OPTIONS_DEFAULT_powerpc64=	AIM

AIM_DESC=	Set for AIM hardware
BOOKE_DESC=	Set for BOOKE hardware

AIM_CFLAGS=	-DAIM
BOOKE_CFLAGS=	-DBOOKE

.include <bsd.port.pre.mk>

CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=		-n freebsd
CONFIGURE_ENV=		FREEBSD_SYS="${SRC_BASE}/sys" \
			LSOF_CC="${CC}" \
			LSOF_OPINC="-idirafter ${SRC_BASE}/sys"

# GCC needs -lzfs -lzpool for reasons unknown.  If someone can
# figure out why, I (ler) am all ears.
.if ${CHOSEN_COMPILER_TYPE} == gcc
CONFIGURE_ENV+=	LSOF_CFGL="-lzfs -lzpool"
.endif

.if !exists(${SRC_BASE}/sys/kern/kern_lockf.c)
IGNORE+=	requires kernel sources (or set SRC_BASE)
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lsof ${STAGEDIR}${PREFIX}/sbin
	(cd ${WRKSRC} && ${SOELIM} Lsof.8 > ${WRKSRC}/lsof.8)
	${INSTALL_MAN} ${WRKSRC}/lsof.8 ${STAGEDIR}${MANDIRS}/man8/lsof.8
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/* ${STAGEDIR}${DATADIR}

.include <bsd.port.post.mk>
