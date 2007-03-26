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
PORTREVISION=	7
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=lesi/compat5x
PKGNAMESUFFIX=	-${ARCH}
DISTNAME=	${PORTNAME}-${ARCH}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A convenience package to install the compat5x libraries

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BZIP2=	yes
NO_BUILD=	yes
ONLY_FOR_ARCHS=	alpha amd64 i386 sparc64
USE_LDCONFIG=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/compat
TARGET_DIR=	${PREFIX}/lib/compat
TARGET32_DIR=	${PREFIX}/lib32/compat
USE_LDCONFIG=	${TARGET_DIR}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
IGNORE=		is for FreeBSD 6.x and newer
.endif

.if ${OSVERSION} >= 600016
RUN_DEPENDS+=	${LOCALBASE}/share/compat/locale/UTF-8/LC_CTYPE:${PORTSDIR}/misc/localedata
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

do-install:
	@${MKDIR} ${TARGET_DIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} *.so.* ${TARGET_DIR})
.if ${ARCH} == amd64
	@${MKDIR} ${TARGET32_DIR}
	(cd ${WRKSRC}/lib32 && ${INSTALL_DATA} *.so.* ${TARGET32_DIR})
.endif

# Include to automatic install file in libdata/ldconfig{,32}
.include "${PORTSDIR}/misc/ldconfig_compat/bsd.ldconfig.mk"

post-install:	install-ldconfig-file
.if ${ARCH} == amd64
	@${LDCONFIG} -32 -m ${TARGET32_DIR}
.endif
	@${CAT} ${PKGMESSAGE}

pre-clean:
	@[ -w ${WRKSRC} ] && chflags -R noschg ${WRKSRC} || ${TRUE}

.include <bsd.port.post.mk>
