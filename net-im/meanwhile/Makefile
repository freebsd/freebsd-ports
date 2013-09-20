# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	meanwhile
PORTVERSION=	1.0.2
PORTREVISION=	3
CATEGORIES=	net-im
MASTER_SITES=	SF

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Open Source implementation of the Lotus Sametime protocol

USE_AUTOTOOLS=	libtool
USES=		pkgconfig
USE_GMAKE=	yes
USE_GNOME=	gnomehack glib20
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-doxygen=no \
		--with-gmp-prefix=${LOCALBASE}
CPPFLAGS+=	-I${LOCALBASE}/include -DGLIB_COMPILATION
LDFLAGS+=	-L${LOCALBASE}/lib

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-doc-${PORTVERSION}

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/samples/*.c ${WRKSRC}/src/*.[ch]

.include <bsd.port.mk>
