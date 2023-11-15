PORTNAME=	swtpm
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	meka@tilda.center
COMMENT=	Libtpms-based TPM emulator
WWW=		https://github.com/stefanberger/swtpm

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	base64>=0:converters/base64 \
		bash>=0:shells/bash \
		expect>=0:lang/expect \
		gawk>=0:lang/gawk \
		socat>=0:net/socat
LIB_DEPENDS=	libfuse.so:sysutils/fusefs-libs \
		libgnutls.so:security/gnutls \
		libjson-glib-1.0.so:devel/json-glib \
		libtasn1.so:security/libtasn1 \
		libtpms.so:sysutils/libtpms

USES=		autoreconf gettext-runtime gmake gnome libtool pathfix \
		pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	stefanberger
USE_GNOME+=	glib20
USE_RC_SUBR=	swtpm

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
