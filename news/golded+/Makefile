# New ports collection makefile for:    golded+
# Date created:                         20 October 2003
# Whom:                                 Max Khon
#
# $FreeBSD$
#

PORTNAME=	golded+
PORTVERSION=	1.1.5.a${SNAPDATE}
CATEGORIES=	news mail
MASTER_SITES=	SF/golded-plus/golded-plus-src/Snapshot%20of%20the%201.1.5
DISTNAME=	gps${SNAPDATE:S,^200,,}
SNAPDATE=	20070503
EXTRACT_SUFX=	.tb2

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	GoldEd+ (FTN message editor)

USE_BZIP2=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1=		golded.1 goldnode.1 rddt.1
DOCS=		copying copying.lib license.txt notework.txt rusfaq.txt\
		tips.txt notework.rus tokencfg.txt tokentpl.txt goldnode.txt
PORTDOCS=	${DOCS} gold_ref.txt gold_usr.txt
SUB_FILES=	pkg-message
.if !defined(NOPORTDOCS)
SUB_LIST=	NOTEWORK="Please read the ${DOCSDIR}/notework.txt before using ${PORTNAME}"
.else
SUB_LIST=	NOTEWORK=""
.endif

post-patch:
	@${SED}\
		-e 's,^\(#define __GVER_VENDOR_NAME__\).*,\1 "",'\
		-e 's,\(#define __GVER_VENDOR_FIDO__\).*,\1 "",'\
		-e 's,\(#define __GVER_VENDOR_EMAIL__\).*,\1 "",'\
		-e 's,\(#define __GVER_RELEASENAME__\).*,\1 "Golded+ FreeBSD port",'\
		-e 's,\(#define __GVER_POSTVERSION__\).*,\1 "-b${SNAPDATE}",'\
		<${WRKSRC}/golded3/mygolded.__h >${WRKSRC}/golded3/mygolded.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/gedlnx ${PREFIX}/bin/golded
	${INSTALL_PROGRAM} ${WRKSRC}/bin/gnlnx ${PREFIX}/bin/goldnode
	${INSTALL_PROGRAM} ${WRKSRC}/bin/rddtlnx ${PREFIX}/bin/rddt
.for i in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/docs/$i ${PREFIX}/man/man1
.endfor
	@${MKDIR} ${EXAMPLESDIR}
.for i in charset colorset config template
	${MKDIR} ${EXAMPLESDIR}/$i;
	${FIND} ${WRKSRC}/cfgs/$i -maxdepth 1 -type f |\
		${XARGS} -n 1 -J @ ${INSTALL_DATA} @ ${EXAMPLESDIR}/$i
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manuals/gold_ref.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manuals/gold_usr.txt ${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/$i ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
