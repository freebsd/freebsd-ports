# New ports collection makefile for:	SmartDoc devel
# Date created:		19 December 2000
# Whom:			KIRIYAMA Kazuhiko <kiri@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	smartdoc
PORTVERSION=	1.0.0.20031106
PORTREVISION=	1
CATEGORIES=	textproc java
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kiri/smartdoc
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML utility to create various documents(devel version)

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

WRKSRC=		${WRKDIR}/sdoc
NO_BUILD=	yes
USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.3+
JAVA_EXTRACT=	jre
JAVA_RUN=	jre
EXTRACT_CMD=	${JAVA}
EXTRACT_BEFORE_ARGS=	-jar ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} \
			-batch -bindir:${WRKSRC}/bin -installbasedir:${WRKSRC}
EXTRACT_AFTER_ARGS=	#
NO_LATEST_LINK=	yes

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
.for file in ${ELISPS}
	${INSTALL_DATA} ${WRKSRC}/etc/${file} ${EMACSLISPDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/${file} ${XEMACSLISPDIR}
.endfor

.include <bsd.port.mk>
