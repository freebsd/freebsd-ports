PORTNAME=	omping
PORTVERSION=	0.0.4
CATEGORIES=	net-mgmt

MAINTAINER=	fw@moov.de
COMMENT=	Tool to test IP multicast functionality

LICENSE=	MIT

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	jfriesse

PLIST_FILES=	bin/${PORTNAME} \
		man/man8/omping.8.gz

post-patch:
		@${REINPLACE_CMD} -e 's|/share/man|/man|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
