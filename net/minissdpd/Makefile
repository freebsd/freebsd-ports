# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	minissdpd
PORTVERSION=	1.5.20180203
CATEGORIES=	net
MASTER_SITES=	http://miniupnp.free.fr/files/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	UPnP IGD discovery speed enhancer

LICENSE=	BSD3CLAUSE

USES=		gmake
USE_RC_SUBR=	minissdpd

CFLAGS+=	-D_GNU_SOURCE

PLIST_FILES=	sbin/minissdpd man/man8/minissdpd.8.gz

post-extract:
	@${MV} ${WRKSRC}/${PORTNAME}.1 ${WRKSRC}/${PORTNAME}.8

post-patch:
	@${REINPLACE_CMD} -e 's|^\(\.TH.*\)1|\18|' ${WRKSRC}/${PORTNAME}.8
	@${REINPLACE_CMD} -E '/^(CC|CFLAGS)/d' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
