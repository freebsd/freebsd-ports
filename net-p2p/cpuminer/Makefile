# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cpuminer
PORTVERSION=	2.3.2
PORTREVISION=	2
CATEGORIES=	net-p2p math
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	cpuminer
DISTNAME=	pooler-${PORTNAME}-${PORTVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	CPU miner for Litecoin and Bitcoin

LICENSE=	GPLv2

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libjansson.so:${PORTSDIR}/devel/jansson

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_AUTOTOOLS=	aclocal autoheader automake autoconf
AUTOMAKE_ARGS=	--gnu --add-missing --copy
# gcc 4.6 yields higher hashrates on newer CPUs, gcc 4.8 even better
USE_GCC?=	yes

PLIST_FILES=	bin/minerd

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
.for FILE in NEWS README
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
