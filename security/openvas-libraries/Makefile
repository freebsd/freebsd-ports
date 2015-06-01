# Created by: Tomoyuki Sakurai <cherry@trombik.org>
# $FreeBSD$

PORTNAME=	openvas-libraries
PORTVERSION=	2.0.3
PORTREVISION=	8
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/600/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libraries for OpenVAS

LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt

GNU_CONFIGURE=	yes
USES=		libtool pkgconfig
USE_LDCONFIG=	yes
USE_GNOME=	glib20
MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ARGS=	--localstatedir=/var
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libopenvas*.so

.include <bsd.port.mk>
