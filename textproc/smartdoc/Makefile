# New ports collection makefile for:	SmartDoc
# Date created:		19 December 2000
# Whom:			KIRIYAMA Kazuhiko <kiri@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	smartdoc
PORTVERSION=	0.7
CATEGORIES=	textproc java
MASTER_SITES=	http://www.asahi-net.or.jp/~dp8t-asm/java/tools/SmartDoc/
DISTNAME=	setup${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	kunishi@acm.org

BUILD_DEPENDS=	${JDKDIR}/bin/java:${PORTSDIR}/java/jdk12-beta \
		${MKCATALOG}:${PORTSDIR}/textproc/mkcatalog \
		nkf:${PORTSDIR}/japanese/nkf
RUN_DEPENDS=	${JDKDIR}/bin/java:${PORTSDIR}/java/jdk12-beta \
		${MKCATALOG}:${PORTSDIR}/textproc/mkcatalog

SCRIPTS_ENV=	JDKDIR=${JDKDIR} JAVADIR=${JAVADIR}
PLIST_SUB=	PORTVERSION=${PORTVERSION} MKCATALOG=${MKCATALOG}

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/sdoc
USE_ZIP=	yes

JAVADIR=	${PREFIX}/share/java
JDKVERSION?=	1.2.2
JDKDIR=		${LOCALBASE}/jdk${JDKVERSION}
XMLDIR=		${PREFIX}/share/xml
DTDNAME=	smartdoc
DTDDIR=		${XMLDIR}/${DTDNAME}
MKCATALOG=	${LOCALBASE}/sbin/mkcatalog
SJIS2EUC=	quick/Dl.sdoc \
		quick/HelloWorld_ja.sdoc \
		quick/NaturalP.sdoc \
		quick/Ol.sdoc \
		quick/P.sdoc \
		quick/TableBasic.sdoc \
		quick/TableCSV.sdoc \
		quick/TreeTable.sdoc \
		quick/Ul.sdoc \
		quick/quick.sdoc \
		refman/refman.sdoc \
		sample/html.html \
		sample/latex.tex \
		sample/sample.sdoc \
		sampleI18N/data.csv \
		sampleI18N/html.html \
		sampleI18N/latex.tex \
		sampleI18N/sample.sdoc

do-extract:
	${MKDIR} ${WRKSRC}/bin
	${JDKDIR}/bin/java -jar ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} -batch \
		-bindir:${WRKSRC}/bin -installbasedir:${WRKSRC}

post-extract:
	${CP} ${FILESDIR}/sdoc.in ${WRKSRC}/bin/sdoc

pre-patch:
	cd ${WRKSRC}/doc; \
	for f in ${SJIS2EUC}; do \
		${MV} $${f} $${f}.tmp; \
		nkf -xde $${f}.tmp > $${f}; \
		${RM} -f $${f}.tmp; \
	done

pre-install:
	${MKDIR} ${JAVADIR}/sdoc-${PORTVERSION}/bin ${JAVADIR}/classes ${DTDDIR}
	find ${WRKSRC} \( -name \*.orig -o -name \*~ \) -exec ${RM} -f \{} \;

do-install:
	${CP} -R ${WRKSRC}/* ${JAVADIR}/sdoc-${PORTVERSION}
	cd ${WRKSRC}; \
	${INSTALL_SCRIPT} bin/sdoc ${JAVADIR}/sdoc-${PORTVERSION}/bin; \
	${INSTALL_DATA} SmartDoc.jar ${JAVADIR}/classes
	${LN} -sf ${JAVADIR}/sdoc-${PORTVERSION}/bin/sdoc ${PREFIX}/bin/sdoc
	${INSTALL_DATA} ${FILESDIR}/catalog ${DTDDIR}
	cd ${WRKSRC}/etc/pure; \
	${INSTALL_DATA} PureSmartDoc.dtd PureSmartDoc.rlx article.css ${DTDDIR}

post-install:
	${MKCATALOG} -c ${PREFIX}/share/xml/catalog -q install ${DTDNAME}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
