# $FreeBSD$

PORTNAME=	jabber
PORTVERSION=	1.7.1
CATEGORIES=	net-im

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Jabber (XMPP) plugin for Licq

LIB_DEPENDS=	gloox:${PORTSDIR}/net-im/gloox \
		boost_regex:${PORTSDIR}/devel/boost-libs

LICENSE=	GPLv2

USE_CMAKE=	yes
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

DOCFILES=	README
PLIST_FILES=	lib/licq/protocol_jabber.so \
		%%PORTDOCS%%%%DOCSDIR%%/README
PLIST_DIRS=	%%PORTDOCS%%%%DOCSDIR%%

LICQ_PORT?=	net-im/licq

.include <bsd.port.pre.mk>

.include "${PORTSDIR}/${LICQ_PORT}/Makefile.inc"

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
