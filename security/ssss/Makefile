PORTNAME=	ssss
DISTVERSIONPREFIX=	releases/v
DISTVERSION=	0.5.7
CATEGORIES=	security

MAINTAINER=	mauroeldritch@gmail.com
COMMENT=	Shamir's Secret Sharing Scheme
WWW=		http://point-at-infinity.org/ssss/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	MrJoy

PLIST_FILES=	bin/ssss-combine \
		bin/ssss-split \
		share/man/man1/ssss.1.gz

do-build:
	cd ${BUILD_WRKSRC} && \
		${CC} ${CFLAGS} ${LDFLAGS} -Wall -o ssss-split ssss.c -lgmp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ssss-split ${STAGEDIR}${PREFIX}/bin
	${RLN} ${STAGEDIR}${PREFIX}/bin/ssss-split ${STAGEDIR}${PREFIX}/bin/ssss-combine
	${INSTALL_MAN} ${WRKSRC}/ssss.1 ${STAGEDIR}${PREFIX}/share/man/man1

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ssss-split

.include <bsd.port.mk>
