# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	ump
PORTVERSION=	0.8.6
PORTREVISION=	9
CATEGORIES=	math
MASTER_SITES=	SF/u-m-p/u-m-p/${PORTVERSION}
PKGNAMESUFFIX=	-math

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical, easy to use math program

CONFLICTS=	ump-1.[0-9]*

USES=		gmake pkgconfig tar:bzip2
USE_GNOME=	gtk20
USE_GL=		glu

ALL_TARGET=	${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAKE_ENV+=	DATADIR="${DATADIR}"

FIND_DIRS=	-type d
FIND_DATA=	-type f

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/src/main.cpp

post-install:
	${INSTALL_DATA} ${WRKSRC}/ump.conf ${STAGEDIR}${PREFIX}/etc/ump.conf.sample

.include <bsd.port.mk>
