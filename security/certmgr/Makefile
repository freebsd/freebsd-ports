PORTNAME=	certmgr
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.3
PORTREVISION=	28
CATEGORIES=	security net

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Automated certificate management using a CFSSL CA
WWW=		https://github.com/cloudflare/certmgr

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	cloudflare
GH_TUPLE=	golang:sys:v0.5.0:golang_sys/vendor/golang.org/x/sys_

CONFLICTS_INSTALL=	mono mono[0-9]* # bin/certmgr

GO_TARGET=	./certmgr
SUB_FILES=	certmgr.yaml.sample pkg-message

post-extract:
	${RM} -r ${WRKSRC}/vendor/modules.txt
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${MV} ${WRKSRC}/vendor/golang.org/x/sys_ ${WRKSRC}/vendor/golang.org/x/sys

pre-configure:
	${REINPLACE_CMD} -e 's,%%ETCDIR%%,${ETCDIR},' \
	    ${WRKSRC}/certmgr/cmd/genconfig.go \
	    ${WRKSRC}/certmgr/cmd/root.go \
	    ${WRKSRC}/README.md

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${ETCDIR}.d
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${WRKSRC}/SPEC.rst ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKDIR}/certmgr.yaml.sample ${STAGEDIR}${ETCDIR}/

.include <bsd.port.mk>
