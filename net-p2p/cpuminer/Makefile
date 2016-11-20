# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cpuminer
PORTVERSION=	2.4
PORTREVISION=	3
CATEGORIES=	net-p2p math
MASTER_SITES=	SF/cpuminer
DISTNAME=	pooler-${PORTNAME}-${PORTVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	CPU miner for Litecoin and Bitcoin

LICENSE=	GPLv2

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libjansson.so:devel/jansson

USES=		autoreconf cpe
GNU_CONFIGURE=	yes
CPE_VENDOR=	cpuminer_project
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
# gcc 4.6 yields higher hashrates on newer CPUs, gcc 4.8 even better
USE_GCC?=	yes

PLIST_FILES=	bin/minerd man/man1/minerd.1.gz
PORTDOCS=	NEWS README

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
