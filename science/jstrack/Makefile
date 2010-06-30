# New ports collection Makefile for:	JStrack
# Date created:				2010-06-28
# Whom:					Chris Rees <utisoft@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	jstrack
PORTVERSION=	3.0.2
CATEGORIES=	science
MASTER_SITES=	http://www.jstrack.org/jstrack/downloads/ \
		http://www.bayofrum.net/dist/${PORTNAME}/

MAINTAINER=	utisoft@gmail.com
COMMENT=	A freeware hurricane tracking program

LIB_DEPENDS=	netpbm.1:${PORTSDIR}/graphics/netpbm \
		img.1:${PORTSDIR}/graphics/libimg
RUN_DEPENDS=	dtplite:${PORTSDIR}/devel/tcllib

LICENSE=	JStrack
LICENSE_NAME=	JStrack
LICENSE_PERMS=	no-dist-sell pkg-mirror no-pkg-sell auto-accept
LICENSE_TEXT=	It is and always will be free, and [Jim Graham] wrote it...\
		so don't charge money for it, and don't claim that you wrote it

WRKSRC=	${WRKDIR}/${PORTNAME}
USE_TCL_RUN=	84
USE_TK=		84
NO_BUILD=	yes

SUB_FILES=	${PORTNAME}.sh
SUB_LIST=	WISH=${WISH}

PORTDOCS=	00-README_FIRST.txt HISTORY install.txt jstrackdoc.pdf

do-install:
	@${MKDIR} ${PREFIX}/lib/${PORTNAME}
.for f in filt ftpfilt tracker
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
.for d in filt ftpfilt ftpfilt/support tracker tracker/lib tracker/storms
	@${CHMOD} ugo+rx ${PREFIX}/lib/${PORTNAME}/${d}/*.t*
.endfor
	@(cd ${PREFIX}/lib/${PORTNAME} && ${TCLSH} autoconfig.tcl && ${RM} paths.tcl.old)
.for f in filt/filt.tcl ftpfilt/autoftp.override.tcl ftpfilt/autoftp.tcl ftpfilt/ftp.tcl ftpfilt/ftplib.tcl ftpfilt/old_ftplib.tcl tracker/jstrack-text_only.tcl tracker/jstrack.tcl
	@${REINPLACE_CMD} 's#\.\./paths.tcl#${PREFIX}/lib/jstrack/paths.tcl#g' \
		${PREFIX}/lib/${PORTNAME}/${f}
.endfor

.include <bsd.port.mk>
