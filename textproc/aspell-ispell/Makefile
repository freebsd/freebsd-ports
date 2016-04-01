# $FreeBSD$

PORTNAME=	aspell
PORTVERSION=	0.60.6.1
CATEGORIES=	textproc
MASTER_SITES=	GNU/aspell
PKGNAMESUFFIX=	-ispell

MAINTAINER=	office@FreeBSD.org
COMMENT=	Ispell compatibility script for aspell

LICENSE=	LGPL21

CONFLICTS+=	ispell* ??-ispell*

RUN_DEPENDS=	aspell:textproc/aspell

NO_BUILD=	yes
PLIST_FILES=	bin/ispell \
		bin/spell

post-patch:
	@${REINPLACE_CMD} -e "s/^#CHECK/CHECK/g" ${WRKSRC}/scripts/ispell

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/ispell ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/spell ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
