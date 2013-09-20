# Created by: lukin
# $FreeBSD$

PORTNAME=	filerunner
PORTVERSION=	12.05.23.16
CATEGORIES=	x11-fm tk
MASTER_SITES=	SF/${PORTNAME}/Release-${PORTVERSION}
DISTNAME=	fr-${PORTVERSION:S/.0/./}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tcl/Tk-based filemanager with FTP capabilities

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

USE_TK_WRAPPER=	yes

PORTDOCS=	FAQ HISTORY README *.txt

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	@${MKDIR} ${DATADIR}
.for file in fr frftp tclIndex *.tcl *.xpm
	${INSTALL_DATA} ${WRKSRC}/${file} ${DATADIR}
.endfor
.for dir in bitmaps packages
	@cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${DATADIR}
.endfor
.for file in fr frftp frcolor.tcl
	@${CHMOD} ${BINMODE} ${DATADIR}/${file}
.endfor
	@${LN} -sf ${DATADIR}/fr ${PREFIX}/bin/fr
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
