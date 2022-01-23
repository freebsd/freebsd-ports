PORTNAME=	gron.awk
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
CATEGORIES=	textproc

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	AWK implementation of gron, a JSON-to-greppable-text transformer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	xonixx

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}/${PREFIX}/bin/

.include <bsd.port.mk>
