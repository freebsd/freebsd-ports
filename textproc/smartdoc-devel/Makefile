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

MAINTAINER=	kunishi@acm.org
COMMENT=	XML utility to create various documents(devel version)

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

SCRIPTS_ENV=	JAVALIBDIR=${JAVALIBDIR}
WRKSRC=		${WRKDIR}/sdoc
NO_BUILD=	yes
USE_ZIP=	yes
USE_JAVA=	1.3+
NO_RUN_DEPENDS_JAVA=	yes
EXTRACT_CMD=	${JAVA}
EXTRACT_BEFORE_ARGS=	-jar ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} \
			-batch -bindir:${WRKSRC}/bin -installbasedir:${WRKSRC}
EXTRACT_AFTER_ARGS=	#

JAVALIBDIR=	${PREFIX}/share/java
XMLDIR=		${PREFIX}/share/xml
EMACSLISPDIR=	${LOCALBASE}/share/emacs/site-lisp
XEMACSLISPDIR=	${LOCALBASE}/lib/xemacs/site-lisp
DTDDIR=		${XMLDIR}/${PORTNAME}
MKCATALOG=	${LOCALBASE}/sbin/mkcatalog
DOCS=		COPYING.txt OroLICENSE.txt README README.sdoc \
		README_en.html README_ja.html \
		XalanLICENSE.txt XercesLICENSE.txt
JARS=		SmartDoc.jar
ELISPS=		sdoc-helper.el sdoc-mode.el

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${CP} ${FILESDIR}/sdoc.in ${WRKSRC}/bin/sdoc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/sdoc ${PREFIX}/bin
	${MKDIR} ${JAVALIBDIR}/classes
.for jar in ${JARS}
	${INSTALL_DATA} ${WRKSRC}/${jar} ${JAVALIBDIR}/classes
.endfor
	${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/etc/* ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for doc in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
	${CP} -R ${WRKSRC}/doc ${DOCSDIR}
.endif
	${MKDIR} ${DTDDIR} ${EMACSLISPDIR} ${XEMACSLISPDIR}
	${INSTALL_DATA} ${FILESDIR}/catalog ${DTDDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/pure/PureSmartDoc.dtd ${DTDDIR}
.for file in ${ELISPS}
	${INSTALL_DATA} ${WRKSRC}/etc/${file} ${EMACSLISPDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/${file} ${XEMACSLISPDIR}
.endfor

.include <bsd.port.mk>
