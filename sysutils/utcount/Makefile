PORTNAME=	utcount
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	sysutils net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Users Traffic Count

MAKE_ARGS=	PREFIX="${STAGEDIR}${PREFIX}" \
		INSTALL_PROG="${INSTALL_SCRIPT}" \
		INSTALL_CONF="${INSTALL_DATA}"

post-build:
	${STRIP_CMD} ${WRKSRC}/bin/count_client

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/utcount.conf.default \
		${STAGEDIR}${PREFIX}/etc/utcount.conf.sample

.include <bsd.port.mk>
