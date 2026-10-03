PORTNAME=	cni-epair
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.1
CATEGORIES=	sysutils

MAINTAINER=	michaeljohnson@ahze.net
COMMENT=	CNI plugin giving containers a LAN address via epair and bridge
WWW=		https://github.com/daemonless/cni-epair

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/libexec/cni/host-local:net/containernetworking-plugins

USE_GITHUB=	yes
GH_ACCOUNT=	daemonless

# A POSIX shell script: nothing to compile, nothing architecture specific.
NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_DEFAULT=	DOCS EXAMPLES

PLIST_FILES=	libexec/cni/epair
PORTDOCS=	README.md
PORTEXAMPLES=	*

post-patch:
	${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|g" ${WRKSRC}/epair

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/cni
	${INSTALL_SCRIPT} ${WRKSRC}/epair ${STAGEDIR}${PREFIX}/libexec/cni

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
