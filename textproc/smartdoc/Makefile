# New ports collection makefile for:	SmartDoc
# Date created:		19 December 2000
# Whom:			KIRIYAMA Kazuhiko <kiri@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	smartdoc
PORTVERSION=	0.6.10
CATEGORIES=	textproc java
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://www.asahi-net.or.jp/~dp8t-asm/java/tools/SmartDoc/
MASTER_SITE_SUBDIR=	kiri
DISTNAME=	setup
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	kiri@FreeBSD.org

BUILD_DEPENDS=	${JDKDIR}/bin/java:${PORTSDIR}/java/jdk12-beta \
		nkf:${PORTSDIR}/japanese/nkf
RUN_DEPENDS=	${JDKDIR}/bin/java:${PORTSDIR}/java/jdk12-beta

SCRIPTS_ENV=	JDKDIR=${JDKDIR} JAVADIR=${JAVADIR}
PLIST_SUB=	PORTVERSION=${PORTVERSION}

IS_INTERACTIVE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/sdoc

JAVADIR=	${PREFIX}/share/java
JDKVERSION?=	1.2.2
JDKDIR=		${LOCALBASE}/jdk${JDKVERSION}
XMLDIR=		${PREFIX}/share/xml
DTDDIR=		${XMLDIR}/smartdoc
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
	@${ECHO} "************************************************************************"
	@${ECHO} "* You MUST SET \`Install directory' and \`Command directory':            *"
	@${ECHO} "*        Install directory = .                                         *"
	@${ECHO} "*        Command directory = ./bin                                     *"
	@${ECHO} "* and then enter \"yes\".                                                *"
	@${ECHO} "************************************************************************"
	${MKDIR} ${WRKSRC}/bin
	cd ${WRKSRC}; \
	${LOCALBASE}/jdk${JDKVERSION}/bin/java -cp ${DISTDIR}/${DISTFILES} setup

pre-patch:
	cd ${WRKSRC}/doc; \
	for f in ${SJIS2EUC}; do \
		${MV} $${f} $${f}.tmp; \
		nkf -xde $${f}.tmp > $${f}; \
		${RM} -f $${f}.tmp; \
	done

pre-install:
	${MKDIR} ${JAVADIR}/sdoc-${PORTVERSION} ${JAVADIR}/classes ${DTDDIR}
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
	if [ ! -f ${XMLDIR}/catalog ]; then \
		${ECHO} "CATALOG \"smartdoc/catalog\"" > ${XMLDIR}/catalog; \
	else \
		${SETENV} LANG=C ${PERL} -ni -e 'print if !m|smartdoc/catalog|;print "CATALOG \"smartdoc/catalog\"\n" if eof;' ${XMLDIR}/catalog; \
	fi

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
