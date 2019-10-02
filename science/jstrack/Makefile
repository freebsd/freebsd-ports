# Created by: Chris Rees <utisoft@gmail.com>
# $FreeBSD$

PORTNAME=	jstrack
PORTVERSION=	3.4.0
CATEGORIES=	science
MASTER_SITES=	http://www.jstrack.org/${PORTNAME}/downloads/ \
		http://www.bayofrum.net/dist/${PORTNAME}/
DISTNAME=	JStrack-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Freeware hurricane tracking program

LICENSE=	JStrack
LICENSE_NAME=	JStrack
LICENSE_TEXT=	It is and always will be free, and [Jim Graham] wrote it...\
		so don't charge money for it, and don't claim that you wrote it
LICENSE_PERMS=	dist-sell pkg-sell auto-accept

RUN_DEPENDS=	dtplite:devel/tcllib tcltls>0:devel/tcltls

WRKSRC=		${WRKDIR}/${PORTNAME}
USES=		tk
NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	${PORTNAME}.sh
SUB_LIST=	WISH=${WISH}

PORTDOCS=	HISTORY JStrack-${PORTVERSION}-Documentation.pdf README

OPTIONS_DEFINE=	DOCS

post-extract:
	@${MKDIR} ${WRKSRC}/tracker/storms/old/2012
	@cd ${WRKSRC}/tracker/storms/old/2012 && ${TAR} xf ../2012.tar.gz
	@${RM} ${WRKSRC}/tracker/storms/old/20*z*
	@${RM} -r ${WRKSRC}/tracker/lib/Img1.4.2
	@${RMDIR} ${WRKSRC}/filt/tmp

post-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/paths.tcl

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "filt tracker" \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/*.tcl ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
