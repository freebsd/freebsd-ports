# Created by: Dennis Herrmann <dhn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	smu
PORTVERSION=	1.4
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Simple interpreter for a simplified markdown dialect

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	Gottox
GH_PROJECT=	smu

PLIST_FILES=	bin/smu man/man1/smu.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|cc|${CC}|g' ${WRKSRC}/config.mk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/smu ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/smu.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
