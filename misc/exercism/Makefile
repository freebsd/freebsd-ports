# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	exercism
PORTVERSION=	1.7.1
DISTVERSIONPREFIX=	v
CATEGORIES=	misc
MASTER_SITES=	\
		https://codeload.github.com/codegangsta/cli/legacy.tar.gz/f7ebb76?dummy=/:group2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		codegansta-cli-f7ebb76${EXTRACT_SUFX}:group2

MAINTAINER=	swills@FreeBSD.org
COMMENT=	CLI client for exercism.io

BUILD_DEPENDS=	${LOCALBASE}/bin/go:${PORTSDIR}/lang/go

WRKSRC=		${WRKDIR}/cli-${PORTVERSION}
USE_GITHUB=	yes
GH_PROJECT=	cli

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
