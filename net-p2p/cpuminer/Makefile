PORTNAME=	cpuminer
PORTVERSION=	2.5.1
PORTREVISION=	2
CATEGORIES=	net-p2p math
MASTER_SITES=	SF/cpuminer
DISTNAME=	pooler-${PORTNAME}-${PORTVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	CPU miner for Litecoin and Bitcoin
WWW=		https://sourceforge.net/projects/cpuminer/

LICENSE=	GPLv2

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libjansson.so:devel/jansson

OPTIONS_DEFINE=	GCC DOCS
OPTIONS_DEFAULT=GCC

USES=		autoreconf cpe
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CPE_VENDOR=	cpuminer_project
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/minerd share/man/man1/minerd.1.gz
PORTDOCS=	NEWS README

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGCC}
# gcc yields higher hashrates on newer CPUs
USE_GCC?=	yes
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
