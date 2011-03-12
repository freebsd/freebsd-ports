# New ports collection makefile for:	SmartDoc
# Date created:		19 December 2000
# Whom:			KIRIYAMA Kazuhiko <kiri@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	smartdoc
PORTVERSION=	1.0.0
PORTREVISION=	2
CATEGORIES=	textproc java
MASTER_SITES=	http://www.asahi-net.or.jp/~dp8t-asm/java/tools/SmartDoc/
DISTNAME=	setup${PORTVERSION:S/.//g}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML utility to create various documents

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

BUILD_DEPENDS=	${MKCATALOG}:${PORTSDIR}/textproc/mkcatalog
RUN_DEPENDS=	${MKCATALOG}:${PORTSDIR}/textproc/mkcatalog \
		java:${PORTSDIR}/java/javavmwrapper

WRKSRC=		${WRKDIR}/sdoc
NO_BUILD=	yes
USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.2+
JAVA_EXTRACT=	jre
JAVA_RUN=	jre
EXTRACT_CMD=	${JAVA}
EXTRACT_BEFORE_ARGS=	-jar ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} \
			-batch -bindir:${WRKSRC}/bin -installbasedir:${WRKSRC}
EXTRACT_AFTER_ARGS=	#

XMLDIR=		${PREFIX}/share/xml
EMACSLISPDIR=	${LOCALBASE}/share/emacs/site-lisp
XEMACSLISPDIR=	${LOCALBASE}/lib/xemacs/site-lisp
DTDDIR=		${XMLDIR}/${PORTNAME}
MKCATALOG=	${LOCALBASE}/sbin/mkcatalog
.if !defined(NOPORTDOCS)
PORTDOCS=	COPYING.txt OroLICENSE.txt README README.sdoc \
		README_en.html README_ja.html \
		XalanLICENSE.txt XercesLICENSE.txt doc
.endif
JARS=		SmartDoc.jar
ELISPS=		sdoc-helper.el sdoc-mode.el

SUB_FILES=	sdoc.sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/sdoc.sh ${PREFIX}/bin/sdoc
	${MKDIR} ${JAVAJARDIR}
.for jar in ${JARS}
	${INSTALL_DATA} ${WRKSRC}/${jar} ${JAVAJARDIR}
.endfor
	cd ${WRKSRC}/etc \
	  && ${FIND} . -type d -exec ${MKDIR} ${EXAMPLESDIR}/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${EXAMPLESDIR}/{} \;
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} \
	  && ${FIND} ${PORTDOCS} -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
	  && ${FIND} ${PORTDOCS} -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
.endif
	${MKDIR} ${DTDDIR} ${EMACSLISPDIR} ${XEMACSLISPDIR}
	${INSTALL_DATA} ${FILESDIR}/catalog ${DTDDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/pure/PureSmartDoc.dtd ${DTDDIR}
	${MKCATALOG} -c ${LOCALBASE}/share/xml/catalog -q install ${PORTNAME}
.for file in ${ELISPS}
	${INSTALL_DATA} ${WRKSRC}/etc/${file} ${EMACSLISPDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/${file} ${XEMACSLISPDIR}
.endfor

.include <bsd.port.mk>
