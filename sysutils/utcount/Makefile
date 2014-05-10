# Created by: Denis N. Peplin <info@volginfo.ru>
# $FreeBSD$

PORTNAME=	utcount
PORTVERSION=	0.1
CATEGORIES=	sysutils net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Users Traffic Count

MAKE_ARGS=	PREFIX="${STAGEDIR}${PREFIX}" \
		INSTALL_PROG="${INSTALL_SCRIPT}" \
		INSTALL_CONF="${INSTALL_DATA}"

post-build:
	${STRIP_CMD} ${WRKSRC}/bin/count_client

.include <bsd.port.mk>
