PORTNAME=	mdns-repeater
PORTVERSION=	1.11
CATEGORIES=	net dns

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Multicast DNS repeater to re-broadcast mDNS packets across interfaces

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	kennylevinsen

USE_RC_SUBR=	mdns-repeater

CFLAGS+=	-DHGVERSION="\"${PORTVERSION}\""

PLIST_FILES=	bin/mdns-repeater

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.c

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
