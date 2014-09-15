# Created by: Andy Kosela <akosela@andykosela.com>
# $FreeBSD$

PORTNAME=	go-cs
PORTVERSION=	0.1
CATEGORIES=	net

MAINTAINER=	akosela@andykosela.com
COMMENT=	Concurrent ssh client

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${GO_CMD}:${PORTSDIR}/lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	akosela
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	6ae59df

PLIST_FILES=	bin/cs man/man1/cs.1.gz

GO_CMD=		${LOCALBASE}/bin/go
GO_ARGS=	build -ldflags "${STRIP}"

do-build:
	(cd ${WRKSRC} && ${GO_CMD} ${GO_ARGS} cs.go)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cs ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cs.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
