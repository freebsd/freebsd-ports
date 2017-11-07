# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=		hitch
PORTVERSION=		1.4.6
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=		security

MAINTAINER=		zi@FreeBSD.org
COMMENT=		TLS proxy to forward connections to an unencrypted backend

LICENSE=		BSD2CLAUSE

BUILD_DEPENDS=		rst2man:textproc/py-docutils \
			pkg-config:devel/pkgconf
LIB_DEPENDS=		libev.so:devel/libev

USERS=			nobody
GROUPS=			nobody

USES=			autoreconf ssl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--localstatedir=/var/run
CONFIGURE_ENV=		CRYPTO_CFLAGS="-I${OPENSSLINC}" CRYPTO_LIBS="-L${OPENSSLLIB}" \
			SSL_CFLAGS="-I${OPENSSLINC}" SSL_LIBS="-L${OPENSSLLIB}"
USE_RC_SUBR=		${PORTNAME}
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib -lcrypto -lssl
USE_GITHUB=		yes
GH_ACCOUNT=		varnish
PORTSCOUT=		skipv:premerge

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.conf.sample ${STAGEDIR}${PREFIX}/etc/

.include <bsd.port.mk>
