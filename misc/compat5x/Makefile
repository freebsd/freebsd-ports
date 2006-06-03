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
PORTREVISION=	6
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=lesi/compat5x
PKGNAMESUFFIX=	-${ARCH}
DISTNAME=	${PORTNAME}-${ARCH}-${PORTVERSION}

MAINTAINER=	r.c.ladan@gmail.com
COMMENT=	A convenience package to install the compat5x libraries

ONLY_FOR_ARCHS=	alpha amd64 i386 sparc64
USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/compat
TARGET_DIR=	${PREFIX}/lib/compat
TARGET32_DIR=	${PREFIX}/lib32/compat

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
IGNORE=	is for FreeBSD 6.x and newer
.endif

.if ${OSVERSION} > 700011 || (${OSVERSION} < 700000 && ${OSVERSION} >= 600104)
USE_LDCONFIG=	${TARGET_DIR}
PLIST_SUB+=	USE_LDCONFIG=""
.else
NO_MTREE=	yes
USE_RC_SUBR=	000.${PORTNAME}.sh
SUB_LIST+=	LDCONFIG="${LDCONFIG}"
PLIST_SUB+=	USE_LDCONFIG="@comment "
.endif

.if ${OSVERSION} >= 600016
RUN_DEPENDS=	${LOCALBASE}/share/compat/locale/UTF-8/LC_CTYPE:${PORTSDIR}/misc/localedata
.endif

.if ${ARCH} == alpha
PLIST_SUB+=	ALPHA=""
.else
PLIST_SUB+=	ALPHA="@comment "
.endif
.if ${ARCH} == amd64
PLIST_SUB+=	AMD64=""
PLIST_SUB+=	LDCONFIG_LIB32="${LDCONFIG} -32"
.if defined(USE_RC_SUBR)
SUB_LIST+=	AMD64="" TARGET32_DIR="${TARGET32_DIR}"
.endif
.else
PLIST_SUB+=	AMD64="@comment "
.if defined(USE_RC_SUBR)
SUB_LIST+=	AMD64="@comment "
.endif
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
.if defined(USE_RC_SUBR)
	@( ${ECHO} ""; \
	   ${ECHO} "******************************************************"; \
	   ${ECHO} "To enable the ldconfig of these libraries at boot time"; \
	   ${ECHO} "you need to add compat5x_enable=\"yes\" to either"; \
	   ${ECHO} "/etc/rc.conf.local or /etc/rc.conf"; \
	   ${ECHO} "******************************************************"; \
	   ${ECHO} ""; ) > ${WRKDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
.endif

NO_BUILD=	yes

do-install:
	${MKDIR} ${TARGET_DIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} *.so.* ${TARGET_DIR})
.if ${ARCH} == amd64
	${MKDIR} ${TARGET32_DIR}
	(cd ${WRKSRC}/lib32 && ${INSTALL_DATA} *.so.* ${TARGET32_DIR})
	${LDCONFIG} -32 -m ${TARGET32_DIR}
.endif

post-install:
.if defined(USE_LDCONFIG)
	@${ECHO} ${USE_LDCONFIG} > ${PREFIX}/libdata/ldconfig/${UNIQUENAME}
.if ${ARCH} == amd64
	@${ECHO} ${TARGET32_DIR} > ${PREFIX}/libdata/ldconfig32/${UNIQUENAME}
.endif
.else
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
