PORTNAME=	aircrack-ng
DISTVERSION=	1.5.2
PORTREVISION=	3
CATEGORIES=	net-mgmt security
MASTER_SITES=	http://download.aircrack-ng.org/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	802.11 WEP and WPA-PSK keys cracking program

LICENSE=	GPLv2 BSD3CLAUSE APACHE20
LICENSE_COMB=	dual

BROKEN_aarch64=		fails to configure: _AX_COMPILER_VERSION_GNU unknown gcc major
BROKEN_armv6=		fails to configure: _AX_COMPILER_VERSION_GNU unknown gcc major
BROKEN_armv7=		fails to configure: _AX_COMPILER_VERSION_GNU unknown gcc major
BROKEN_i386=		fails to configure: _AX_COMPILER_VERSION_GNU unknown gcc major

USES=		autoreconf cpe dos2unix gmake libtool pkgconfig
USE_GCC=	yes
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-experimental
CPE_VERSION=	${DISTVERSION:C/-.*//}
CPE_UPDATE=	${DISTVERSION:C/^[^-]*$//:C/.*-//}
DOS2UNIX_FILES=	src/aircrack-osdep/byteorder.h
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	GCRYPT HWLOC PCRE SQLITE
OPTIONS_DEFAULT=	HWLOC PCRE SQLITE
OPTIONS_SUB=	yes

GCRYPT_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
			libgpg-error.so:security/libgpg-error
GCRYPT_CONFIGURE_ON=	--with-gcrypt
GCRYPT_USES_OFF=	ssl
GCRYPT_VARS_OFF=	CFLAGS+=-I${OPENSSLINC} LDFLAGS+=-L${OPENSSLLIB}

HWLOC_DESC=	Use Hardware Locality to improve performance
HWLOC_LIB_DEPENDS=	libhwloc.so:devel/hwloc2
HWLOC_CONFIGURE_OFF=	--disable-hwloc

PCRE_DESC=	Use Perl Compatible Regular Expressions for wesside
PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_CONFIGURE_OFF=	--disable-pcre

SQLITE_DESC=	Use SQLite for storing pre-computed key tables
SQLITE_USES=	sqlite
SQLITE_CONFIGURE_OFF=	--without-sqlite3

.include <bsd.port.pre.mk>

.if ${ARCH:Mpowerpc*}
PLIST_SUB+=	PPC="" \
		X86="@comment "
.elif ${ARCH} == amd64 || ${ARCH} == i386
PLIST_SUB+=	PPC="@comment " \
		X86=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local/etc/aircrack-ng,${ETCDIR},' \
		${WRKSRC}/scripts/airodump-ng-oui-update

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}

.include <bsd.port.post.mk>
