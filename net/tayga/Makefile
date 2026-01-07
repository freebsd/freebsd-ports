PORTNAME=	tayga
DISTVERSION=	0.9.6
CATEGORIES=	net

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Userland stateless NAT64 daemon
WWW=		https://github.com/apalrd/tayga/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	apalrd

TEST_TARGET=	test

CFLAGS+=	-DTAYGA_CONF_PATH='\"${PREFIX}/etc/tayga.conf\"'

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/tayga
	${INSTALL_DATA} ${WRKSRC}/tayga.conf.example ${STAGEDIR}${PREFIX}/etc

post-install-DOCS-on:
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
