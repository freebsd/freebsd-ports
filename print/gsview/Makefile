# Created by: bf <bf2006a@yahoo.com>
# $FreeBSD$

PORTNAME=	gsview
PORTVERSION=	4.9
PORTREVISION=	7
CATEGORIES=	print
MASTER_SITES=	LOCAL/bf

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	GUI to view, search, print, and convert PostScript and PDF documents

LICENSE=	AFPL
LICENSE_NAME=	Aladdin Free Public Licence
LICENSE_FILE=	${WRKSRC}/LICENCE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

RUN_DEPENDS+=	epstool:graphics/epstool \
		pstotext:print/pstotext

USES=		cpe ghostscript
USE_GNOME=	gtk12
MAKE_JOBS_UNSAFE=	yes
PLIST_FILES=	bin/gsview \
		bin/gsview-help \
		etc/gsview/printer.ini \
		man/man1/gsview.1.gz
PORTDOCS=	gsview.css cdorder.txt regorder.txt Readme.htm LICENCE \
		gvxct.htm gvxde.htm gvxen.htm gvxes.htm gvxfr.htm gvxgr.htm \
		gvxit.htm gvxnl.htm gvxru.htm gvxse.htm gvxsk.htm
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

post-patch:
	${CP} ${WRKSRC}/srcunx/unx.mak ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's;malloc\.h;stdlib\.h;g' \
	    ${WRKSRC}/src/doc2html.c ${WRKSRC}/src/doc2ipf.c \
	    ${WRKSRC}/src/doc2xml.c
	${REINPLACE_CMD} -e 's;mozilla;firefox3;g' \
	    ${WRKSRC}/srcunx/gvxhelp.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/gsview ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/srcunx/gvxhelp.txt \
	    ${STAGEDIR}${PREFIX}/bin/gsview-help
	${INSTALL_MAN} ${WRKSRC}/srcunx/gsview.1 ${STAGEDIR}${PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/gsview/
	${INSTALL_DATA} ${WRKSRC}/src/printer.ini \
	    ${STAGEDIR}${PREFIX}/etc/gsview/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_MAN} gsview.css cdorder.txt regorder.txt \
	    Readme.htm LICENCE ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/bin/*.htm ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
