# Created by: Jov <amutu@amutu.com>
# $FreeBSD$

PORTNAME=	radcli
PORTVERSION=	1.2.7
CATEGORIES=	net

MAINTAINER=	amutu@amutu.com
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
	@cd ${WRKSRC} && ./autogen.sh

post-patch:
	@${REINPLACE_CMD} -e 's|1000000000.0d|1000000000.0|g' \
		${WRKSRC}/lib/util.c

post-install:
.for f in radiusclient.conf radiusclient-tls.conf servers servers-tls
	${INSTALL_DATA} ${WRKSRC}/etc/${f} \
		${STAGEDIR}${PREFIX}/etc/radcli/${f}.sample
.endfor

.include <bsd.port.mk>
