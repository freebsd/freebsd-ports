# $FreeBSD$

PORTNAME=	AtomicParsley
PORTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME:L}/${PORTNAME}%20v${PORTVERSION}
DISTNAME=	${PORTNAME}-source-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command line program for reading parsing and setting MP4/M4A metadata

LICENSE=	GPLv2

USES=		zip

PLIST_FILES=	bin/AtomicParsley

post-patch:
	@${REINPLACE_CMD} -e 's,g++,${CXX},g' -e 's,-g -O2 -Wall,${CXXFLAGS},g' ${WRKSRC}/build

do-build:
	cd ${WRKSRC} && ./build

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/AtomicParsley ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
