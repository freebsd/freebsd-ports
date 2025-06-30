PORTNAME=	lasso
PORTVERSION=	2.8.2
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	https://dev.entrouvert.org/releases/lasso/

PATCH_SITES=	https://git.entrouvert.org/entrouvert/lasso/commit/
PATCHFILES=	46caef81855e58629516f09b101e40bf8778981d.patch:-p1 \
	1ca8e8699ce1ed072f99ed881a7348f9a78b1e1f.patch:-p1 \
	66c9f50f1f6b00d621a9a0ca2f924875f94d14ae.patch:-p1 \
	21c224cfefa1018be9e40fab9a7e36865bf4d0d6.patch:-p1 \
	3768f1bedf1502a54634195dbb88e5a54869d9b9.patch:-p1

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Free Liberty Alliance Implementation
WWW=		https://lasso.entrouvert.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}
LIB_DEPENDS=	libltdl.so:devel/libltdl \
		libxmlsec1-openssl.so:security/xmlsec1
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		cpe gmake gnome libtool pathfix pkgconfig python ssl
CPE_VENDOR=	entrouvert
USE_GNOME=	glib20 libxml2 libxslt
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-java \
		--disable-php5 \
		--with-zlib

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS PERL PYTHON
OPTIONS_SUB=	yes

PERL_USES=			perl5
PERL_CONFIGURE_ENABLE=		perl
PYTHON_CONFIGURE_ENABLE=	python

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion -Wno-error=incompatible-function-pointer-types
.endif

post-patch:
	@${REINPLACE_CMD} -E 's,(xmlsec1-openssl >= 1\.2\.6) openssl,\1,' \
		${CONFIGURE_WRKSRC}/configure
# Fix build with new xmlsec1 as this function was deprecated
	@${REINPLACE_CMD} -e 's|BAD_CAST XMLSEC_CRYPTO|BAD_CAST xmlSecGetDefaultCrypto()|g' \
		${WRKSRC}/lasso/lasso.c

.include <bsd.port.mk>
