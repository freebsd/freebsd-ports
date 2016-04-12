# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=		hitch
PORTVERSION=		1.1.1
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=		security

MAINTAINER=		zi@FreeBSD.org
COMMENT=		TLS proxy to forward connections to an unencrypted backend

LICENSE=		BSD2CLAUSE

BUILD_DEPENDS=		rst2man:textproc/py-docutils
LIB_DEPENDS=		libev.so:devel/libev

USERS=			nobody
GROUPS=			nobody

USES=			autoreconf
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--localstatedir=/var/run
USE_OPENSSL=		yes
USE_RC_SUBR=		${PORTNAME}
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib
USE_GITHUB=		yes
GH_ACCOUNT=		varnish

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.conf.sample ${STAGEDIR}${PREFIX}/etc/

.include <bsd.port.mk>
