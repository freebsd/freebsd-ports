PORTNAME=	pam_u2f
DISTVERSIONPREFIX=${PORTNAME}-
DISTVERSION=	1.3.0
CATEGORIES=	security

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Pluggable Authentication Module for U2F and FIDO2
WWW=		https://developers.yubico.com/pam-u2f/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	a2x:textproc/asciidoc
LIB_DEPENDS=	libfido2.so:security/libfido2

USES=		autoreconf libtool pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	Yubico
GH_PROJECT=	pam-u2f
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pam-dir=${PREFIX}/lib

PLIST_FILES=	bin/pamu2fcfg \
		lib/pam_u2f.so \
		man/man1/pamu2fcfg.1.gz \
		man/man8/pam_u2f.8.gz

.include <bsd.port.mk>
