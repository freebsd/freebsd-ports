PORTNAME=	libspf2
PORTVERSION=	1.2.11
CATEGORIES=	mail

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Sender Policy Framework 2 C Implementation

LICENSE=	BSD2CLAUSE LGPL21 LGPL3
LICENSE_COMB=	dual

USES=		autoreconf cpe libtool

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	shevek
GH_TAGNAME=	4915c30

post-patch:
	@${REINPLACE_CMD} -e '/__VA_ARGS__/ s|format, ||g' ${WRKSRC}/src/include/spf_log.h

.include <bsd.port.mk>
