PORTNAME=	tcc
PKGNAMESUFFIX=	816
DISTVERSION=	0.9.25
CATEGORIES=	lang

MAINTAINER=	freebsd@darkain.com
COMMENT=	WDC 65816 fork of the Tiny C Compiler (TCC)
WWW=		https://github.com/alekmaul/tcc

LICENSE=		MIT
LICENSE_FILE_MIT=	${WRKSRC}/RELICENSING

# BUILD_DEPENDS=	as:devel/binutils

USES=			gmake
HAS_CONFIGURE=  yes
CONFIGURE_ARGS= --prefix="${PREFIX}" --cc="${CC}"

USE_GITHUB=	yes
GH_ACCOUNT= alekmaul
GH_TAGNAME= 10810db6

PLIST_FILES=	bin/816-tcc

.include <bsd.port.pre.mk>


do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/816-tcc ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.post.mk>
