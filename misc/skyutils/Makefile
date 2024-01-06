PORTNAME=	skyutils
PORTVERSION=	3.0
CATEGORIES=	misc
MASTER_SITES=	https://BSDforge.com/projects/source/misc/skyutils/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library required by smssend (same author)
WWW=		https://BSDforge.com/projects/misc/skyutils/

BROKEN=		Unfetchable
DEPRECATED=	Library used for deprecated port misc/smssend
EXPIRATION_DATE=2024-02-29

USES=		autoreconf libtool ssl tar:txz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

pre-configure:
	@${REINPLACE_CMD} -e's/[[:cntrl:]]*$$//' ${WRKSRC}/src/skyutils.h

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libskyutils.so

.include <bsd.port.mk>
