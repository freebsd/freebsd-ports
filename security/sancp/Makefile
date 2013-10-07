# Created by: Paul Schmehl <pauls@utdallas.edu>
# $FreeBSD$

PORTNAME=	sancp
PORTVERSION=	1.6.1
DISTVERSIONSUFFIX=	-stable
PORTREVISION=	5
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}-stable

MAINTAINER=	pauls@utdallas.edu
COMMENT=	Network connection profiler

LICENSE=	QPLv1
LICENSE_NAME=	Q PUBLIC LICENSE v1.0
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	auto-accept

ALL_TARGET=	bsd
USE_RC_SUBR=	sancp
LOG_DIR=	/var/log/sancp
PLIST_SUB+=	LOG_DIR=${LOG_DIR}

USERS=		sancp
GROUPS=		sancp

OPTIONS_DEFINE=	DOCS

PORTDOCS=	CHANGES INSTALL ISSUES \
		README SETUP fields.LIST

MAKE_ARGS=	CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
		LFLAGS="${LDFLAGS}"

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|$${CC}|g ; s|g++|$${CXX}|g' \
		${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/sancp \
		${STAGEDIR}${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/etc/sancp/sancp.conf \
		${STAGEDIR}${PREFIX}/etc/sancp.conf.dist
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/docs/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL} -m 750 -d ${STAGEDIR}${LOG_DIR}

.include <bsd.port.mk>
