# Created by: bf <bf2006a@yahoo.com>
# $FreeBSD$

PORTNAME=	gsview
PORTVERSION=	4.9
PORTREVISION=	4
CATEGORIES=	print
MASTER_SITES=	LOCAL/bf

MAINTAINER=	bf@FreeBSD.org
COMMENT=	GUI to view, search, print, and convert PostScript and PDF documents

USE_GNOME=		gtk12
USE_GHOSTSCRIPT=	yes

RUN_DEPENDS+=		epstool:${PORTSDIR}/graphics/epstool \
			pstotext:${PORTSDIR}/print/pstotext

NO_CDROM=	Can only be distributed for free

MAKE_ENV+=	PTHREAD_LIBS=${PTHREAD_LIBS} PTHREAD_CFLAGS=${PTHREAD_CFLAGS}

MAKE_JOBS_UNSAFE=	yes

MAN1=		gsview.1
PLIST_FILES=	bin/gsview \
		bin/gsview-help \
		etc/gsview/printer.ini
PLIST_DIRS=	etc/gsview
PORTDOCS=	gsview.css cdorder.txt regorder.txt Readme.htm LICENCE \
		gvxct.htm gvxde.htm gvxen.htm gvxes.htm gvxfr.htm gvxgr.htm \
		gvxit.htm gvxnl.htm gvxru.htm gvxse.htm gvxsk.htm
SUB_FILES=	pkg-message

NO_STAGE=	yes
post-patch:
	${CP} ${WRKSRC}/srcunx/unx.mak ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's;malloc\.h;stdlib\.h;g' \
	${WRKSRC}/src/doc2html.c ${WRKSRC}/src/doc2ipf.c \
	${WRKSRC}/src/doc2xml.c
	${REINPLACE_CMD} -e 's;mozilla;firefox3;g' \
	${WRKSRC}/srcunx/gvxhelp.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/gsview ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/srcunx/gvxhelp.txt ${PREFIX}/bin/gsview-help
	${INSTALL_MAN} ${WRKSRC}/srcunx/gsview.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/etc/gsview/
	${INSTALL_DATA} ${WRKSRC}/src/printer.ini ${PREFIX}/etc/gsview/
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_MAN} gsview.css cdorder.txt regorder.txt \
	Readme.htm LICENCE ${DOCSDIR} )
	${INSTALL_MAN} ${WRKSRC}/bin/*.htm ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
