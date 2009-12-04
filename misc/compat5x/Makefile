# New ports collection makefile for:	compat5x libraries
# Date created:				19 Aug 2005
# Whom:					hrs, lesi
#
# $FreeBSD$
#

# NOTE: libc.so.5 is built with _PATH_LOCALE defined to
# "/usr/local/share/compat/locale" in src/include/paths.h so data installed by
# misc/localedata works out of the box if installed in default PREFIX.

PORTNAME=	compat5x
PORTVERSION=	5.4.0.8
PORTREVISION=	11
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=lesi/compat5x
PKGNAMESUFFIX=	-${ARCH}
DISTNAME=	${PORTNAME}-${ARCH}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A convenience package to install the compat5x libraries

RUN_DEPENDS=	${LOCALBASE}/share/compat/locale/UTF-8/LC_CTYPE:${PORTSDIR}/misc/localedata

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BZIP2=	yes
NO_BUILD=	yes
ONLY_FOR_ARCHS=	alpha amd64 i386 sparc64
TARGET_DIR=	${PREFIX}/lib/compat
TARGET32_DIR=	${PREFIX}/lib32/compat
USE_LDCONFIG=	${TARGET_DIR}

EXTRACT_PRESERVE_OWNERSHIP=	yes	# Files in archive have scfg-flag set

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not install on sparc64: fails to link lib/compat/libpthread.so.1
.endif

.if ${ARCH} == alpha
PLIST_SUB+=	ALPHA=""
.else
PLIST_SUB+=	ALPHA="@comment "
.endif

.if ${ARCH} == amd64
PLIST_SUB+=	AMD64=""
PLIST_SUB+=	LDCONFIG_LIB32="${LDCONFIG} -32"
USE_LDCONFIG32=	${TARGET32_DIR}
.else
PLIST_SUB+=	AMD64="@comment "
.endif

.if ${ARCH} == i386
PLIST_SUB+=	I386=""
.else
PLIST_SUB+=	I386="@comment "
.endif

.if ${ARCH} == sparc64
PLIST_SUB+=	SPARC64=""
.else
PLIST_SUB+=	SPARC64="@comment "
.endif

post-extract:
	@chflags -R noschg ${WRKSRC} || ${TRUE}

do-install:
	@${MKDIR} ${TARGET_DIR}
.if ${OSVERSION} >= 800105
	${RM} -f ${WRKSRC}/libpthread.so.1
	(cd ${TARGET_DIR} && ${LN} -sf libthr.so.1 libpthread.so.1)
.endif
	(cd ${WRKSRC} && ${INSTALL_DATA} *.so.* ${TARGET_DIR})
.if ${ARCH} == amd64
	@${MKDIR} ${TARGET32_DIR}
. if ${OSVERSION} >= 800105
	${RM} -f ${WRKSRC}/lib32/libpthread.so.1
	(cd ${TARGET32_DIR} && ${LN} -sf libthr.so.1 libpthread.so.1)
. endif
	(cd ${WRKSRC}/lib32 && ${INSTALL_DATA} *.so.* ${TARGET32_DIR})
.endif

.include <bsd.port.post.mk>
