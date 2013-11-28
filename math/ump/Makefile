# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	ump
PORTVERSION=	0.8.6
PORTREVISION=	7
CATEGORIES=	math
MASTER_SITES=	SF/u-m-p/u-m-p/${PORTVERSION}
PKGNAMESUFFIX=	-math

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A graphical, easy to use math program

CONFLICTS=	ump-1.[0-9]*

USES=		gmake pkgconfig
USE_BZIP2=	yes
USE_GNOME=	gtk20
USE_GL=		glu

ALL_TARGET=	${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAKE_ENV+=	DATADIR="${DATADIR}"

FIND_DIRS=	-type d
FIND_DATA=	-type f

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/src/main.cpp

post-install:
	${INSTALL_DATA} ${WRKSRC}/ump.conf ${PREFIX}/etc/ump.conf.dist
.if !exists(${PREFIX}/etc/ump.conf)
	${INSTALL_DATA} ${WRKSRC}/ump.conf ${PREFIX}/etc
.endif

.include <bsd.port.mk>
