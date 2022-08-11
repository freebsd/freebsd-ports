PORTNAME=	skyutils
PORTVERSION=	3.0
CATEGORIES=	misc
MASTER_SITES=	https://BSDforge.com/projects/source/misc/skyutils/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Library required by smssend (same author)

USES=		autoreconf libtool ssl tar:txz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

pre-configure:
	@${REINPLACE_CMD} -e's/[[:cntrl:]]*$$//' ${WRKSRC}/src/skyutils.h

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libskyutils.so

.include <bsd.port.mk>
