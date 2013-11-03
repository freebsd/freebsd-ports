# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cpuminer
PORTVERSION=	2.3.2
CATEGORIES=	net-p2p math

MAINTAINER=	mm@FreeBSD.org
COMMENT=	CPU miner for Litecoin and Bitcoin

LICENSE=	GPLv2

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		jansson:${PORTSDIR}/devel/jansson

USE_GITHUB=	yes
GH_ACCOUNT=	pooler
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	8b30b7b

USE_AUTOTOOLS=	aclocal autoheader automake autoconf
AUTOMAKE_ARGS=	--gnu --add-missing --copy
GNU_CONFIGURE=	yes

.include <bsd.port.options.mk>

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 1000000
USE_GCC=        yes
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
.for FILE in NEWS README
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}/
.endfor
.endif

.include <bsd.port.post.mk>
