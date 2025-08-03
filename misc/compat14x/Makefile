PORTNAME=	compat14x
PORTVERSION=	14.2.1402000.20250803
CATEGORIES=	misc
MASTER_SITES=	LOCAL/arrowd
PKGNAMESUFFIX=	-${ARCH}
DISTNAME=	${PORTNAME}-${ARCH}-${PORTVERSION}

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Convenience package to install the compat14x libraries

LICENSE=	BSD2CLAUSE

USES=		tar:xz
NO_BUILD=	yes
ONLY_FOR_ARCHS=	aarch64 amd64 i386
PLIST=		${PKGDIR}/pkg-plist.${ARCH}
TARGET_DIR=	${PREFIX}/lib/compat
TARGET32_DIR=	${PREFIX}/lib32/compat
USE_LDCONFIG=	${TARGET_DIR}

COMPAT_LIBS=	libasn1.so.11 \
		libcom_err.so.5 \
		libgssapi_krb5.so.10 \
		libgssapi_ntlm.so.10 \
		libgssapi_spnego.so.10 \
		libhdb.so.11 \
		libheimbase.so.11 \
		libheimntlm.so.11 \
		libhx509.so.11 \
		libkadm5clnt.so.11 \
		libkadm5srv.so.11 \
		libkafs5.so.11 \
		libkdc.so.11 \
		libkrb5.so.11 \
		libmd.so.6 \
		libprivateheimipcc.so.11 \
		libprivateheimipcs.so.11 \
		libroken.so.11 \
		libutil.so.9 \
		libwind.so.11

OPTIONS_DEFINE=	COMPAT32
OPTIONS_DEFAULT=COMPAT32
OPTIONS_EXCLUDE_aarch64=COMPAT32
OPTIONS_EXCLUDE_i386=COMPAT32
COMPAT32_DESC=	Install 32-bit compat libraries
OPTIONS_SUB=	yes

.include "${.CURDIR}/../compat4x/Makefile.makedist"

.include <bsd.port.pre.mk>

.if ${OSREL:R} < 14
IGNORE=		is for FreeBSD 14.x and newer
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCOMPAT32}
USE_LDCONFIG32=	${TARGET32_DIR}
.endif

do-install:
	@${MKDIR} -m 0755 ${STAGEDIR}${TARGET_DIR}
	(cd ${WRKSRC}/lib && ${INSTALL_LIB} *.so.* ${STAGEDIR}${TARGET_DIR})

do-install-COMPAT32-on:
	@${MKDIR} ${STAGEDIR}${TARGET32_DIR}
	(cd ${WRKSRC}/lib32 && ${INSTALL_LIB} *.so.* ${STAGEDIR}${TARGET32_DIR})

.include <bsd.port.post.mk>
