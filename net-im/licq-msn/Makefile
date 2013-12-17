# $FreeBSD$

PORTNAME=	msn
PORTVERSION=	1.8.0
CATEGORIES=	net-im

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	MSN plugin for Licq

LICENSE=	GPLv2

LIB_DEPENDS=	libboost_regex.so:${PORTSDIR}/devel/boost-libs

USES=		cmake
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

DOCFILES=	README
PLIST_FILES=	lib/licq/protocol_msn.so \
		%%PORTDOCS%%%%DOCSDIR%%/README
PLIST_DIRS=	%%PORTDOCS%%%%DOCSDIR%%

LICQ_PORT?=	net-im/licq

.include <bsd.port.options.mk>

.include "${PORTSDIR}/${LICQ_PORT}/Makefile.inc"

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
