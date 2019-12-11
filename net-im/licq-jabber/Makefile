# $FreeBSD$

PORTNAME=	jabber
PORTVERSION=	1.9.0
PORTREVISION=	4
CATEGORIES=	net-im
PKGNAMEPREFIX=	licq-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Jabber (XMPP) plugin for Licq

LICENSE=	GPLv2

BUILD_DEPENDS=	licq:${LICQ_PORT}
LIB_DEPENDS=	libgloox.so:net-im/gloox \
		libboost_regex.so:devel/boost-libs \
		libidn.so:dns/libidn \
		libgnutls.so:security/gnutls
RUN_DEPENDS=	licq:${LICQ_PORT}

USES=		cmake pkgconfig
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

DOCFILES=	README
PLIST_FILES=	lib/licq/protocol_jabber.so \
		%%PORTDOCS%%%%DOCSDIR%%/README
USE_GITHUB=	yes
GH_ACCOUNT=	licq-im
GH_PROJECT=	licq
GH_TAGNAME=	f271d55
WRKSRC_SUBDIR=	${PORTNAME}

LICQ_PORT?=	net-im/licq

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
