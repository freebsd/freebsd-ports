PORTNAME=	gtamsanalyzer
PORTVERSION=	0.42
PORTREVISION=	12
CATEGORIES=	science gnustep
MASTER_SITES=	SF/tamsys/gnustep%20tams/GTAMSAnalyzer%2${PORTVERSION}
DISTNAME=	GTAMSAnalyzer.src.${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Qualitative Research Software for the Free World for GNUstep
WWW=		http://tamsys.sourceforge.net/gtams/

LICENSE=	GPLv2

USES=		gnustep
USE_GNUSTEP=	back build

WRKSRC=		${WRKDIR}/${DISTNAME}/Source

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400091
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-patch:
	${RM} "${WRKSRC}/obj"
	@${REINPLACE_CMD} '/^GNUSTEP_INSTALLATION_DIR/ s|=|=$$(DESTDIR)|' \
		${WRKSRC}/GNUmakefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/GTAMSAnalyzer.app/GTAMSAnalyzer

.include <bsd.port.mk>
