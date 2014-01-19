# Created by: ijliao
# $FreeBSD$

PORTNAME=	netmap
PORTVERSION=	0.1.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/NetMap%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Make a graphical representation of the surrounding network

LICENSE=	GPLv2

RUN_DEPENDS=	dotty:${PORTSDIR}/graphics/graphviz

USES=		gmake

PLIST_FILES=	bin/makelist bin/netmap

do-install:
.for i in makelist netmap
	(cd ${WRKSRC}/${i} && ${INSTALL_PROGRAM} ${i} \
		${STAGEDIR}${PREFIX}/bin)
.endfor

.include <bsd.port.mk>
