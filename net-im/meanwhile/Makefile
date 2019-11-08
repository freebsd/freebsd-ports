# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	meanwhile
PORTVERSION=	1.0.2
PORTREVISION=	6
CATEGORIES=	net-im
MASTER_SITES=	SF

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Open Source implementation of the Lotus Sametime protocol

USES=		gmake gnome libtool pathfix pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-doxygen=no \
		--with-gmp-prefix=${LOCALBASE}
CPPFLAGS+=	-I${LOCALBASE}/include -DGLIB_COMPILATION
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-doc-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/samples/*.c ${WRKSRC}/src/*.[ch]

.include <bsd.port.mk>
