# Created by: Josef El-Rayes <j.el-rayes@daemon.li>
# $FreeBSD$

PORTNAME=	swiggle
PORTVERSION=	0.4
PORTREVISION=	9
CATEGORIES=	www
MASTER_SITES=	http://homepage.univie.ac.at/l.ertl/swiggle/files/ \
		http://bsd-geek.de/FreeBSD/distfiles/

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Swiggle is a commandline web image gallery generator

LICENSE=	BSD4CLAUSE

LIB_DEPENDS=	libexif.so:graphics/libexif

USES=		jpeg

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/swiggle ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
