# Created by: John Marino <draco@marino.st>
# $FreeBSD$

PORTNAME=	adabrowse
PORTVERSION=	4.0.3
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://home.datacomm.ch/t_wolf/tw/ada95/adabrowse/
DISTNAME=	${PORTNAME}_${PORTVERSION}_src

MAINTAINER=	marino@FreeBSD.org
COMMENT=	HTML generator for Ada 95 library unit specifications

LICENSE=	GPLv2

BUILD_DEPENDS=	asis>=2011:${PORTSDIR}/lang/asis \
		gnat_util>=2013:${PORTSDIR}/lang/gnat_util

USES=		ada
WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}
PORTDOCS=	*.html *.css

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

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
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${WRKSRC}/doc/*.css \
		${STAGEDIR}/${DOCSDIR}/
.endif

.include <bsd.port.mk>
