# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kops
PORTVERSION=	1.10.0
CATEGORIES=	sysutils

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Kubernetes Operations

LICENSE=	APACHE20

USES=		gmake go

USE_GITHUB=	yes
GH_ACCOUNT=	kubernetes

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	${MKDIR} ${WRKDIR}/src/k8s.io/
	${LN} -s ${WRKSRC} ${WRKDIR}/src/k8s.io/${PORTNAME}
	${REINPLACE_CMD} -e 's/^GITSHA/#GITSHA/' -e 's/sha1sum/sha1/' \
		${WRKSRC}/Makefile

do-build:
	cd ${WRKSRC} && \
		GOPATH=${WRKDIR} ${GMAKE} VERSION=${PORTVERSION}

do-install:
	${INSTALL_PROGRAM} \
		${WRKDIR}/bin/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
