# $FreeBSD$

PORTNAME=	bstack
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Debug tool that shows the stack trace of a running process

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${LOCALBASE}/bin/gdb:devel/gdb

USE_GITHUB=	yes
GH_ACCOUNT=	pizzamig
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/bstack \
		%%DATADIR%%/gdb_bstack

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|;' ${WRKSRC}/bstack

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bstack \
		${STAGEDIR}${PREFIX}/bin/bstack
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/gdb_bstack \
		${STAGEDIR}${DATADIR}/gdb_bstack

.include <bsd.port.mk>
