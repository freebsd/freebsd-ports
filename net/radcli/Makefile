# Created by: Jov <amutu@amutu.com>
# $FreeBSD$

PORTNAME=	radcli
PORTVERSION=	1.2.11
CATEGORIES=	net

MAINTAINER=	neel@neelc.org
COMMENT=	Simple RADIUS client library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libnettle.so:security/nettle

USES=		autoreconf libtool localbase pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

USE_GITHUB=	yes

pre-configure:
	@${TOUCH} ${WRKSRC}/config.rpath

post-install:
.for f in radiusclient.conf radiusclient-tls.conf servers servers-tls
	${INSTALL_DATA} ${WRKSRC}/etc/${f} \
		${STAGEDIR}${PREFIX}/etc/radcli/${f}.sample
.endfor

.include <bsd.port.mk>
