PORTNAME=	sectok
DISTVERSION=	20030825
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	http://www.citi.umich.edu/projects/smartcard/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ISO 7816 Smartcard Utility
WWW=		http://www.citi.umich.edu/projects/smartcard/sectok.html

LICENSE=	LicenseRef-UMich
LICENSE_NAME=	University of Michigan License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

DEPRECATED=	Last upstream release in 2003 and no longer maintained
EXPIRATION_DATE=	2025-06-30

LIB_DEPENDS=	libsectok.so:security/libsectok

USES=		ssl localbase tar:tgz
USE_LDCONFIG=	yes

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz

post-patch:
	@${REINPLACE_CMD} \
		-e '/^INCLUDES=/s|$$| ${CPPFLAGS}|' \
		-e '/^LIBS=/s|=|=${LDFLAGS} |' \
		-e '/^LIBS=/s|$$| ${LIBS}|' \
		${WRKSRC}/Makefile

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} ${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1)

.include <bsd.port.mk>
