# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	exercism
PORTVERSION=	1.7.1
CATEGORIES=	misc
MASTER_SITES=	https://github.com/${PORTNAME}/cli/archive/v${PORTVERSION}.tar.gz?dummy=/:group1 \
		https://codeload.github.com/codegangsta/cli/legacy.tar.gz/f7ebb76?dummy=/:group2
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:group1 \
		codegansta-cli-f7ebb76${EXTRACT_SUFX}:group2

MAINTAINER=	swills@FreeBSD.org
COMMENT=	CLI client for exercism.io

BUILD_DEPENDS=	${LOCALBASE}/bin/go:${PORTSDIR}/lang/go

WRKSRC=		${WRKDIR}/cli-${PORTVERSION}

PLIST_FILES=	bin/exercism

post-patch:
	cd ${WRKSRC} ; ${MKDIR} src/github.com/codegangsta \
				src/github.com/exercism/cli ; \
	${MV} ${WRKDIR}/codegangsta-cli-f7ebb76 ${WRKSRC}/src/github.com/codegangsta/cli ; \
	${CP} -r api handlers config src/github.com/exercism/cli

do-build:
	cd ${WRKSRC} ; ${SETENV} GOPATH=${WRKSRC} go build -o exercism

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/exercism ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
