# New ports collection makefile for:	Cocoon
# Date created:		27 June 1999
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cocoon
PORTVERSION=	1.8.2
PORTREVISION=	2
CATEGORIES=	textproc www java
MASTER_SITES=	http://xml.apache.org/cocoon/dist/cocoon1/ \
		http://www.metaverse.nl/~ernst/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	znerd
DISTNAME=	Cocoon-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

USE_JAVA=	1.1+
MAKE_ENV=	JAVA_HOME=${JAVA_HOME} CLASSPATH=${CLASSPATH}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

CLASSPATH=	${JAVA_CLASSES}
LIBS=		fop_0_15_0.jar xalan_1_2_D02.jar xerces_1_2.jar
JDIR=		${PREFIX}/share/java/classes
CDIR=		${PREFIX}/etc/apache/cocoon
SDIR=		${PREFIX}/share/java/cocoon

pre-build:
	${CHMOD} a+rx ${WRKSRC}/build.sh

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./build.sh

pre-install:
	@${MKDIR} ${JDIR} ${CDIR} ${SDIR}

do-install:
	@(cd ${WRKSRC}/build && \
	  ${INSTALL_DATA} cocoon.jar ${JDIR})
	@(cd ${WRKSRC}/lib; \
	  for i in ${LIBS}; do \
		${INSTALL_DATA} $${i} ${JDIR} ; \
	  done)
	@(cd ${WRKSRC}/conf; \
	  ${INSTALL_DATA} cocoon.properties \
		${CDIR}/cocoon.properties.default)
	@if [ ! -f ${CDIR}/cocoon.properties ]; then \
		${CP} ${CDIR}/cocoon.properties.default \
			${CDIR}/cocoon.properties; \
	 fi
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC} ; \
	  ${INSTALL_DATA} LICENSE ${SDIR} ;\
	  ${INSTALL_DATA} README ${SDIR} ;\
	  ${CP} -r docs ${SDIR} ;\
	  ${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${SDIR} ;\
	)
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
