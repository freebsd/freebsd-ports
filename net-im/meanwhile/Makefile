PORTNAME=	meanwhile
PORTVERSION=	1.1.1
CATEGORIES=	net-im

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open Source implementation of the Lotus Sametime protocol
WWW=		https://github.com/obriencj/meanwhile

USES=		autoreconf gmake gnome libtool pathfix pkgconfig
USE_GITHUB=     yes

GH_ACCOUNT=     obriencj
GH_PROJECT=     ${PORTNAME}
GH_TAGNAME=     v${PORTVERSION}

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
