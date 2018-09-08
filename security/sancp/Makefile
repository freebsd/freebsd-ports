# Created by: Paul Schmehl <pauls@utdallas.edu>
# $FreeBSD$

PORTNAME=	sancp
PORTVERSION=	1.6.1
DISTVERSIONSUFFIX=	-stable
PORTREVISION=	6
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}-stable

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Network connection profiler

LICENSE=	QPLv1
LICENSE_NAME=	Q PUBLIC LICENSE v1.0
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		compiler
ALL_TARGET=	bsd
USE_RC_SUBR=	sancp

USERS=		sancp
GROUPS=		sancp

OPTIONS_DEFINE=	DOCS

PORTDOCS=	CHANGES INSTALL ISSUES \
		README SETUP fields.LIST

CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-c++11-narrowing
MAKE_ARGS=	CFLAGS="${CXXFLAGS}" \
		LFLAGS="${LDFLAGS}"
SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|$${CC}|g ; s|g++|$${CXX}|g' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sancp \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/etc/sancp/sancp.conf \
		${STAGEDIR}${PREFIX}/etc/sancp.conf.sample
	${MKDIR} ${STAGEDIR}/var/log/sancp

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/docs/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
