# Created by: Max Khon
# $FreeBSD$

PORTNAME=	golded+
PORTVERSION=	1.1.5.a${SNAPDATE}
PORTREVISION=	1
CATEGORIES=	news mail
MASTER_SITES=	SF/golded-plus/Golded%2B%201.1.5%20snapshots/2016.03.22
DISTNAME=	gpsrc-115-${SNAPDATE}
EXTRACT_SUFX=	.tgz
SNAPDATE=	20160322

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	GoldEd+ (FTN message editor)

USES=		gmake ncurses

WRKSRC=		${WRKDIR}/golded-plus/${PORTNAME}

MAN1=		golded.1 goldnode.1 rddt.1
DOCS=		copying copying.lib license.txt notework.txt rusfaq.txt\
		tips.txt notework.rus
PORTDOCS=	${DOCS} gold_ref.txt gold_usr.txt
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS EXAMPLES

DOCS_SUB_LIST=	NOTEWORK="Please read the ${DOCSDIR}/notework.txt before using ${PORTNAME}"
DOCS_SUB_LIST_OFF=	NOTEWORK=""

post-patch:
	@${SED}\
		-e 's,^\(#define __GVER_VENDOR_NAME__\).*,\1 "",'\
		-e 's,\(#define __GVER_VENDOR_FIDO__\).*,\1 "",'\
		-e 's,\(#define __GVER_VENDOR_EMAIL__\).*,\1 "${MAINTAINER}",'\
		-e 's,\(#define __GVER_RELEASENAME__\).*,\1 "Golded+ FreeBSD port",'\
		-e 's,\(#define __GVER_POSTVERSION__\).*,\1 "-b${SNAPDATE}",'\
		<${WRKSRC}/golded3/mygolded.__h >${WRKSRC}/golded3/mygolded.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/gedlnx ${STAGEDIR}${PREFIX}/bin/golded
	${INSTALL_PROGRAM} ${WRKSRC}/bin/gnlnx ${STAGEDIR}${PREFIX}/bin/goldnode
	${INSTALL_PROGRAM} ${WRKSRC}/bin/rddtlnx ${STAGEDIR}${PREFIX}/bin/rddt
	${INSTALL_MAN} ${WRKSRC}/docs/*.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for i in charset colorset config template
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/$i;
	${FIND} ${WRKSRC}/cfgs/$i -maxdepth 1 -type f |\
		${XARGS} -n 1 -J @ ${INSTALL_DATA} @ ${STAGEDIR}${EXAMPLESDIR}/$i
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manuals/gold_ref.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manuals/gold_usr.txt ${STAGEDIR}${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/$i ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
