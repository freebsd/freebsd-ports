# $FreeBSD$

PORTNAME=	gurl
DISTVERSION=	0.2.1
CATEGORIES=	www

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Terminal cURL-like HTTP tool with delightful JSON & header support

LICENSE=	APACHE20

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	skunkwerks

PLIST_FILES=	bin/gurl

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gurl
	# find ${WRKDIR}/target -name "bat.1" -exec cp {} ${WRKSRC}/doc/bat.1 \;
	# ${INSTALL_MAN} ${WRKSRC}/doc/bat.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
