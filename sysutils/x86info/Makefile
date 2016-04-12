# Created by: Erik Greenwald <erik@smluc.org>
# $FreeBSD$

PORTNAME=	x86info
PORTVERSION=	1.30
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://codemonkey.org.uk/projects/x86info/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	x86 CPU identification utility

LICENSE=	GPLv2

LIB_DEPENDS=	libpci.so:devel/libpci

ONLY_FOR_ARCHS=	i386 amd64

USES=		gmake pkgconfig python:build tar:tgz
ALL_TARGET=	x86info lsmsr

PLIST_FILES=	bin/lsmsr bin/x86info man/man8/lsmsr.8.gz man/man1/x86info.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/x86info ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/lsmsr ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/x86info.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/lsmsr.8 ${STAGEDIR}${MAN8PREFIX}/man/man8

post-patch:
	@${REINPLACE_CMD} \
		-e 's|python scripts/createheader.py|${PYTHON_CMD} scripts/createheader.py|' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
