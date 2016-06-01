# Created by: Carlo Strub
# $FreeBSD$

PORTNAME=	wemux
PORTVERSION=	3.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils
MASTER_SITES=	http://www.c-s.li/ports/

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Enhances tmux to make multi-user terminal multiplexing easier

LICENSE=	MIT

RUN_DEPENDS=	tmux:sysutils/tmux \
		bash:shells/bash

NO_BUILD=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	zolrath

post-patch:
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/${PORTNAME}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/wemux ${STAGEDIR}${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/wemux.conf.example ${STAGEDIR}${PREFIX}/etc/wemux.conf.example

.include <bsd.port.mk>
