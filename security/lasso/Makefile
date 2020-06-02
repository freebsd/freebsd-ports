# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	lasso
PORTVERSION=	2.6.1
CATEGORIES=	security
MASTER_SITES=	https://dev.entrouvert.org/releases/lasso/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Free Liberty Alliance Implementation

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libltdl.so:devel/libltdl \
		libxmlsec1-openssl.so:security/xmlsec1
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		cpe gnome libtool pkgconfig python ssl
USE_GNOME=	glib20 libxml2 libxslt
USE_LDCONFIG=	yes

CPE_VENDOR=	entrouvert
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-java --disable-php5 --with-zlib

OPTIONS_DEFINE=	PERL PYTHON DOCS
OPTIONS_SUB=	yes
PERL_CONFIGURE_ENABLE=	perl
PERL_USES=	perl5
PYTHON_CONFIGURE_ENABLE=python
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -E 's,(xmlsec1-openssl >= 1\.2\.6) openssl,\1,' \
		${CONFIGURE_WRKSRC}/configure

.include <bsd.port.mk>
