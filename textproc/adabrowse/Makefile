# Created by: John Marino <draco@marino.st>
# $FreeBSD$

PORTNAME=	adabrowse
PORTVERSION=	4.0.3
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://home.datacomm.ch/t_wolf/tw/ada95/adabrowse/
DISTNAME=	${PORTNAME}_${PORTVERSION}_src

MAINTAINER=	marino@FreeBSD.org
COMMENT=	HTML generator for Ada 95 library unit specifications

LICENSE=	GPLv2

BUILD_DEPENDS=	asis>=2011:lang/asis

USES=		ada
WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}
PLIST_FILES=	bin/adabrowse
PORTDOCS=	*.html *.css

OPTIONS_DEFINE=	DOCS

post-extract:
	${CP} ${FILESDIR}/ad-* ${FILESDIR}/build.gpr ${WRKSRC}
	${RM} ${WRKSRC}/sdefault.adb

do-build:
#	Since we only need one C object, just compile it manually rather
#	than bring in GPRBuild as a dependency
	${MKDIR} ${WRKSRC}/obj
	(cd ${WRKSRC}/obj && ${SETENV} ${MAKE_ENV} ada -c -O2 ../util-nl.c)
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gnatmake -Pbuild)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/adabrowse ${STAGEDIR}${PREFIX}/bin/adabrowse

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${WRKSRC}/doc/*.css \
		${STAGEDIR}/${DOCSDIR}/

.include <bsd.port.mk>
