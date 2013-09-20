# Created by: Chris Rees <utisoft@gmail.com>
# $FreeBSD$

PORTNAME=	jstrack
PORTVERSION=	3.3.4
CATEGORIES=	science
MASTER_SITES=	http://www.jstrack.org/${PORTNAME}/downloads/ \
		http://www.bayofrum.net/dist/${PORTNAME}/

MAINTAINER=	5u623l20@gmail.com
COMMENT=	A freeware hurricane tracking program

LICENSE=	JStrack
LICENSE_NAME=	JStrack
LICENSE_TEXT=	It is and always will be free, and [Jim Graham] wrote it...\
		so don't charge money for it, and don't claim that you wrote it
LICENSE_PERMS=	dist-sell pkg-sell auto-accept

LIB_DEPENDS=	netpbm.1:${PORTSDIR}/graphics/netpbm \
		img.1:${PORTSDIR}/graphics/libimg
RUN_DEPENDS=	dtplite:${PORTSDIR}/devel/tcllib

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_TCL_RUN=	85
USE_TK=		85
NO_BUILD=	yes

SUB_FILES=	${PORTNAME}.sh
SUB_LIST=	WISH=${WISH}

PORTDOCS=	00-README_FIRST.txt HISTORY install.txt jstrackdoc-v2.pdf

NO_STAGE=	yes
do-install:
	@${MKDIR} ${PREFIX}/lib/${PORTNAME}
.for f in filt httpfilt tracker
	@(cd ${WRKSRC}/ && ${COPYTREE_SHARE} ${f} ${PREFIX}/lib/${PORTNAME}/ \
		'! -path *windows_bin*')
.endfor
	@${INSTALL_SCRIPT} ${WRKSRC}/*.tcl ${PREFIX}/lib/${PORTNAME}
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.	for f in ${PORTDOCS}
		@${INSTALL_MAN} ${WRKSRC}/${f} ${DOCSDIR}
.	endfor
.endif
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/${PORTNAME}
.for d in filt httpfilt tracker tracker/lib tracker/storms/old/2007 tracker/storms/old/2008 tracker/storms/old/2009 tracker/storms/old/2010
	@${CHMOD} ugo+rx ${PREFIX}/lib/${PORTNAME}/${d}/*.t*
.endfor
	@(cd ${PREFIX}/lib/${PORTNAME} && ${TCLSH} autoconfig.tcl && ${RM} paths.tcl.old)

.include <bsd.port.mk>
