# Created by: Chris Rees <utisoft@gmail.com>
# $FreeBSD$

PORTNAME=	jstrack
PORTVERSION=	3.3.4
CATEGORIES=	science
MASTER_SITES=	http://www.jstrack.org/${PORTNAME}/downloads/ \
		http://www.bayofrum.net/dist/${PORTNAME}/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Freeware hurricane tracking program

LICENSE=	JStrack
LICENSE_NAME=	JStrack
LICENSE_TEXT=	It is and always will be free, and [Jim Graham] wrote it...\
		so don't charge money for it, and don't claim that you wrote it
LICENSE_PERMS=	dist-sell pkg-sell auto-accept

LIB_DEPENDS=	libnetpbm.so:graphics/netpbm
RUN_DEPENDS=	dtplite:devel/tcllib

WRKSRC=		${WRKDIR}/${PORTNAME}
USES=		tk:85
NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	${PORTNAME}.sh
SUB_LIST=	WISH=${WISH}

PORTDOCS=	00-README_FIRST.txt HISTORY install.txt jstrackdoc-v2.pdf

post-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/paths.tcl

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
.for f in filt httpfilt tracker
	@(cd ${WRKSRC}/ && ${COPYTREE_SHARE} ${f} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/ \
		'! -path *windows_bin*')
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/*.tcl ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.for d in filt httpfilt tracker tracker/lib tracker/storms/old/2007 tracker/storms/old/2008 tracker/storms/old/2009 tracker/storms/old/2010
	@${CHMOD} ugo+rx ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${d}/*.t*
.endfor

.include <bsd.port.mk>
