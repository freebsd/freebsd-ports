# Created by: carl@servicefactory.com
# $FreeBSD$

PORTNAME=	toshctl
PORTVERSION=	0.0.0p3
CATEGORIES=	sysutils
MASTER_SITES=	http://freebie.miraclenet.co.th/notebook/toshctl/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A command-line tool to access parts of the Toshiba hardware interface

ONLY_FOR_ARCHS=	i386
PLIST_FILES=	bin/toshctl

WRKSRC=		${WRKDIR}/toshctl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
