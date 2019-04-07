# $FreeBSD$

PORTNAME=	openafs
DISTVERSION=	${AFS_DISTVERSION}.${DBVERSION:S/-//g}
CATEGORIES=	net
MASTER_SITES=	http://dl.central.org/dl/openafs/${AFS_DISTVERSION}/:openafs \
		http://dl.openafs.org/dl/openafs/${AFS_DISTVERSION}/:openafs \
		http://dl.central.org/dl/cellservdb/:gco \
		http://grand.central.org/dl/cellservdb/:gco
DISTFILES=	${PORTNAME}-${AFS_DISTVERSION}-src.tar.bz2:openafs \
		${PORTNAME}-${AFS_DISTVERSION}-doc.tar.bz2:openafs \
		CellServDB.${DBVERSION}:gco
EXTRACT_ONLY=	${PORTNAME}-${AFS_DISTVERSION}-src.tar.bz2 \
		${PORTNAME}-${AFS_DISTVERSION}-doc.tar.bz2

MAINTAINER=	bjk@FreeBSD.org
COMMENT=	AFS implementation from openafs.org

LICENSE=	IPLv1
LICENSE_NAME=	IBM Public License Version 1.0
LICENSE_FILE=	${WRKSRC}/doc/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN=		fails to build
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2019-05-08
ONLY_FOR_ARCHS=	i386 amd64

AFS_DISTVERSION=	1.6.22
DBVERSION=	2016-01-01

USES=		cpe kmod tar:bzip2
USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	_XCFLAGS="${CFLAGS} -fPIC" \
		_PAM_CFLAGS="${CFLAGS} -fPIC" \
		_MT_LIBS="-lpthread"
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--localstatedir=/var \
		--mandir=${MANPREFIX}/man \
		--with-bsd-kernel-headers=${SRC_BASE}/sys \
		--with-bsd-kernel-build=${WRKDIR}/conf \
		--enable-debug \
		--enable-debug-kernel \
		--enable-debug-lwp \
		--includedir=${PREFIX}/include/openafs \
		${CONFIGURE_TARGET}
WRKSRC=		${WRKDIR}/${PORTNAME}-${AFS_DISTVERSION}
MAKE_ENV=	COMPILER_TYPE=${COMPILER_TYPE}
USE_RC_SUBR=	afsserver

CPE_VERSION=	${AFS_DISTVERSION}

CONFLICTS=	coda-server-6.[0-9]* heimdal-[0-9]*

MAKE_JOBS_UNSAFE=	yes

AFSMNTDIR?=	/afs
AFSSTATEDIR?=	/var/${PORTNAME}
AFSCACHEDIR?=	${AFSSTATEDIR}/cache
PLIST_SUB+=	AFSMNTDIR=${AFSMNTDIR:C,^/,,} \
		AFSSTATEDIR=${AFSSTATEDIR:C,^/,,} \
		AFSCACHEDIR=${AFSCACHEDIR:C,^/,,}

# clang (the base system compiler in __FreeBSD_version 1000024 and later)
# is pickier about stack alignment than gcc; OpenAFS uses its own
# lightweight process "threading" library which will produce a misaligned
# stack under clang; we need to pass -mstackrealign to avoid SIGBUS at
# runtime.  gcc does not understand this flag, so we use compiler.mk to
# figure out what type of compiler is in use.
USES+=		compiler

OPTIONS_DEFINE=	FUSE
FUSE_USES=	fuse
OPTIONS_SUB=	yes
FUSE_CONFIGURE_OFF=	--disable-fuse-client

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
CFLAGS+=	-mstackrealign
.endif

# Upstream does not support the client on 11 and newer
CONFIGURE_ARGS += --disable-kernel-module

post-install:
	@${RMDIR} ${STAGEDIR}${PREFIX}/lib/openafs

.include <bsd.port.post.mk>
