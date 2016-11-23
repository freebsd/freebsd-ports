# $FreeBSD$

PORTNAME=	icq
PORTVERSION=	1.8.2
PORTREVISION=	1
CATEGORIES=	net-im

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	ICQ plugin for Licq

LICENSE=	GPLv2

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs

USES=		cmake
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

DOCFILES=	README
PLIST_FILES=	lib/licq/protocol_icq.so \
		%%PORTDOCS%%%%DOCSDIR%%/README

LICQ_PORT?=	net-im/licq

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.include "${PORTSDIR}/${LICQ_PORT}/Makefile.inc"

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
