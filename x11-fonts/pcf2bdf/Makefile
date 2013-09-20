# Created by: nork@FreeBSD.org
# $FreeBSD$

PORTNAME=	pcf2bdf
PORTVERSION=	1.04
CATEGORIES=	x11-fonts
MASTER_SITES=	http://cloud.github.com/downloads/ganaware/pcf2bdf/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert X font from PCF to BDF

LICENSE=	MIT

NO_WRKSUBDIR=	yes

MAN1=		pcf2bdf.1
PLIST_FILES=	bin/pcf2bdf

NO_STAGE=	yes
do-build:
	${CXX} ${CXXFLAGS} -o ${WRKSRC}/pcf2bdf ${WRKSRC}/pcf2bdf.cc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pcf2bdf ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pcf2bdf.man ${MANPREFIX}/man/man1/pcf2bdf.1

.include <bsd.port.mk>
