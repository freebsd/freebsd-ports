# Created by: lukin
# $FreeBSD$

PORTNAME=	filerunner
PORTVERSION=	13.07.25.13
CATEGORIES=	x11-fm tk
MASTER_SITES=	SF/${PORTNAME}/release-${PORTVERSION:S/.0/./}
DISTNAME=	fr-${PORTVERSION:S/.0/./}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Tcl/Tk-based filemanager with FTP capabilities

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

USES+=		tk:run

post-patch:
	${REINPLACE_CMD} -e 's|%%WISH%%|${WISH}|' ${WRKSRC}/fr

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/doc
.for file in fr frftp tclIndex *.tcl
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DATADIR}
.endfor
.for file in FAQ HISTORY README *.txt
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${STAGEDIR}${DATADIR}/doc
.endfor
.for dir in bitmaps packages
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${STAGEDIR}${DATADIR}
.endfor
.for file in fr frftp frcolor.tcl
	@${CHMOD} ${BINMODE} ${STAGEDIR}${DATADIR}/${file}
.endfor
	@${LN} -sf ${DATADIR}/fr ${STAGEDIR}${PREFIX}/bin/fr

.include <bsd.port.mk>
