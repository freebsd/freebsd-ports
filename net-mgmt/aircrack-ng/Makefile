# Created by: Lars Engels <lars.engels@0x20.net>
# $FreeBSD$

PORTNAME=	aircrack-ng
DISTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	net-mgmt security
MASTER_SITES=	http://download.aircrack-ng.org/

MAINTAINER=	lme@FreeBSD.org
COMMENT=	802.11 WEP and WPA-PSK keys cracking program

LICENSE=	GPLv2 BSD3CLAUSE APACHE20
LICENSE_COMB=	dual

BROKEN_aarch64=		fails to configure: _AX_COMPILER_VERSION_GNU unknown gcc major
BROKEN_armv6=		fails to configure: _AX_COMPILER_VERSION_GNU unknown gcc major
BROKEN_armv7=		fails to configure: _AX_COMPILER_VERSION_GNU unknown gcc major
BROKEN_powerpc64=	fails to compile: sse-intrinsics.c: error: emmintrin.h: No such file or directory

USES=		autoreconf cpe dos2unix gmake libtool ssl
USE_GCC=	yes
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-experimental
CPE_VERSION=	${DISTVERSION:C/-.*//}
CPE_UPDATE=	${DISTVERSION:C/^[^-]*$//:C/.*-//}
DOS2UNIX_FILES=	src/aircrack-osdep/byteorder.h
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
# Don't call 'strip' target with WITH_DEBUG set
#INSTALL_TARGET=	${STRIP:S/-s/strip/} install

OPTIONS_DEFINE=	PCRE SQLITE
OPTIONS_DEFAULT=PCRE SQLITE
OPTIONS_SUB=	yes

PCRE_DESC=	Use Perl Compatible Regular Expressions for wesside
PCRE_MAKE_ARGS=	pcre=true
PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_USES=	pkgconfig

SQLITE_DESC=	Use SQLite for storing pre-computed key tables
SQLITE_USES=	sqlite
SQLITE_MAKE_ARGS=	sqlite=true

post-patch:
	@${REINPLACE_CMD} \
		-e 's|%%ETCDIR%%|${ETCDIR}|' ${WRKSRC}/scripts/airodump-ng-oui-update

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
