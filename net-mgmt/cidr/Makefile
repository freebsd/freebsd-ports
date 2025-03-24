PORTNAME=	cidr
DISTVERSION=	2.3.2
PORTREVISION=	3
CATEGORIES=	net-mgmt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	RFC 1878 subnet calculator / helper
WWW=		https://github.com/404NotGone/cidr

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/gpl.txt

USE_GITHUB=	yes
GH_ACCOUNT=	404NotGone

PLIST_FILES=	bin/cidr \
		share/man/man1/cidr.1.gz

do-build:
	${CC} ${CFLAGS} ${WRKSRC}/${PORTNAME}.c -o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
