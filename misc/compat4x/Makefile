# Created by: Scot W. Hetzel
# $FreeBSD$

PORTNAME=	compat4x
PORTVERSION=	${COMPAT4X_PORTVERSION}
PORTREVISION=	11
CATEGORIES=	misc
MASTER_SITES=	${COMPAT4X_MASTER_SITES}
PKGNAMESUFFIX=	-${COMPAT4X_ARCH}
DISTFILES=	${COMPAT4X_DISTFILES}
DIST_SUBDIR=	${COMPAT4X_ARCH}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convenience package to install the compat4x libraries

RUN_DEPENDS=	${LOCALBASE}/share/compat/locale/UTF-8/LC_CTYPE:misc/localedata

WRKSRC=		${WRKDIR}/usr/lib/compat

NO_BUILD=	yes
TARGET_DIR=	${PREFIX}/lib/compat
TARGET32_DIR=	${PREFIX}/lib32/compat

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON= FreeBSD 4.x did not support this architecture

COMPAT4X_ARCH=	${ARCH}
COMPAT4X_OSVERSION=	5.3
PLIST=			${.CURDIR}/pkg-plist.freebsd5
.if ${ARCH} == i386
PLIST_SUB+=		LIBDIR="lib"
COMPAT4X_DISTFILES=	${PORTNAME}.aa \
			${PORTNAME}.ab
.elif ${ARCH} == amd64
COMPAT4X_ARCH=		i386
TARGET_DIR=		${TARGET32_DIR}
PLIST_SUB+=		LIBDIR="lib32"
COMPAT4X_DISTFILES=	${PORTNAME}.aa \
			${PORTNAME}.ab
.endif

.if ${COMPAT4X_ARCH} == i386
PLIST_SUB+=		I386_ONLY=""
.else
PLIST_SUB+=		I386_ONLY="@comment "
.endif

.if ${ARCH} == amd64
PLIST_SUB+=		AMD64_ONLY="" AMD64NA="@comment "
USE_LDCONFIG32=		${TARGET32_DIR}
.else
USE_LDCONFIG=		${TARGET_DIR}
PLIST_SUB+=		AMD64_ONLY="@comment " AMD64NA=""
.endif

OPENSSL_LIBS=		libcrypto.so.1 libcrypto.so.2 libssl.so.1 libssl.so.2
.if defined(FORCE_VULNERABLE_OPENSSL)
FORBIDDEN=		FreeBSD-SA-02:33.openssl, FreeBSD-SA-03:02.openssl, FreeBSD-SA-03:18.openssl  - OpenSSL contains multiple vulnerabilities

PLIST_SUB+=		FORBIDDEN:=""
.else
PLIST_SUB+=		FORBIDDEN:="@comment "
.endif

.if defined(COMPAT4X_OSRELDATE) && !empty(COMPAT4X_OSRELDATE)
COMPAT4X_PORTVERSION=	${COMPAT4X_OSVERSION}.${COMPAT4X_OSRELDATE}
COMPAT4X_MASTER_SITES=	ftp://current.FreeBSD.org/pub/FreeBSD/snapshots/${COMPAT4X_ARCH}/${COMPAT4X_OSVERSION}-${COMPAT4X_OSBRANCH}-${COMPAT4X_OSRELDATE}-JPSNAP/${PORTNAME}/
.else
COMPAT4X_PORTVERSION=	${COMPAT4X_OSVERSION}
COMPAT4X_MASTER_SITES=	LOCAL/kris/${COMPAT4X_ARCH}
.endif

do-extract:
	@${MKDIR} ${WRKDIR}
	@(cd ${DISTDIR}/${DIST_SUBDIR} && ${CAT} ${DISTFILES} | ${TAR} -xzf - -C ${WRKDIR} usr/lib/compat )
.if !defined(FORCE_VULNERABLE_OPENSSL)
.for lib in ${OPENSSL_LIBS}
	@${RM} ${WRKSRC}/${lib}
.endfor
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${TARGET_DIR}
	${INSTALL_DATA} ${WRKSRC}/* ${STAGEDIR}${TARGET_DIR}/

pre-clean:
	@[ -w ${WRKDIR}/var ] && chflags -R noschg ${WRKDIR}/var || ${TRUE}

.include <bsd.port.post.mk>
