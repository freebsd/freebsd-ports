PORTNAME=	radcli
PORTVERSION=	1.5.3
MASTER_SITES=	https://github.com/radcli/radcli/releases/download/${PORTVERSION}/
CATEGORIES=	net

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple RADIUS client library
WWW=		https://radcli.github.io/radcli/ \
		https://github.com/radcli/radcli

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libnettle.so:security/nettle
TEST_DEPENDS=	bash:shells/bash

USES=		meson pkgconfig python:test shebangfix tar:xz

MESON_DISABLED=	docs
MESON_ENABLED=	nettle \
		tls
MESON_FALSE=	legacy-compat
MESON_TRUE=	static
USE_LDCONFIG=	yes

SHEBANG_FILES=	tests/radius-server.py \
		tests/*.sh

post-install:
.for file in radiusclient.conf radiusclient-tls.conf servers servers-tls
	${MV} ${STAGEDIR}${PREFIX}/etc/radcli/${file} ${STAGEDIR}${PREFIX}/etc/radcli/${file}.sample
.endfor

.include <bsd.port.mk>
