# Created by: nork@FreeBSD.org
# $FreeBSD$

PORTNAME=	pcf2bdf
PORTVERSION=	1.04
CATEGORIES=	x11-fonts
MASTER_SITES=	GHC
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert X font from PCF to BDF

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	ganaware

WRKSRC=		${WRKDIR}/${DISTNAME}

PLIST_FILES=	bin/pcf2bdf man/man1/pcf2bdf.1.gz

post-extract:
	@${MKDIR} ${WRKSRC}
	@${LN} -sf ../pcf2bdf.cc ${WRKSRC}/pcf2bdf.cc
	@${LN} -sf ../pcf2bdf.man ${WRKSRC}/pcf2bdf.1

do-build:
	(cd ${WRKSRC} && ${CXX} ${CXXFLAGS} pcf2bdf.cc -o pcf2bdf)

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} pcf2bdf \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} pcf2bdf.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)

.include <bsd.port.mk>
