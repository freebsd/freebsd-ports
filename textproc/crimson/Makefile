# New ports collection makefile for:    crimson
# Date created:		2000-03-21
# Whom:			Palle Girgensohn
#
# $FreeBSD$
#

PORTNAME=	crimson
PORTVERSION=	1.1
CATEGORIES=	textproc java
MASTER_SITES=	http://xml.apache.org/dist/crimson/

MAINTAINER=	girgen@partitur.se

RUN_DEPENDS=	${JAVAVM}:${PORTSDIR}/java/javavmwrapper

USE_ZIP=	YES
NO_BUILD=	yes
RESTRICTED=	"uncertain about the license of jaxp.jar"

JAVAVM?=	${LOCALBASE}/bin/javavm

FIND?=		/usr/bin/find

JARS=		jaxp.jar crimson.jar
READMES=	README.txt
CRIMSON_SUBDIR=	${DISTNAME}
PORTDESTDIR=	${PREFIX}/share/java/${CRIMSON_SUBDIR}
PLIST_SUB=	CRIMSON_SUBDIR=${CRIMSON_SUBDIR}

post-extract:
	cd ${WRKDIR}; \
		${FIND} ${DISTNAME} -type d -exec ${CHMOD} +x \{} \;

do-install:
	${MKDIR} ${PREFIX}/share/java/classes
	cd ${INSTALL_WRKSRC}; \
		${INSTALL_DATA} ${JARS} ${PREFIX}/share/java/classes
.if !defined(NOPORTDOCS)
	${MKDIR} ${PORTDESTDIR}
	cd ${INSTALL_WRKSRC}; \
		${INSTALL_DATA} ${READMES} ${PORTDESTDIR}; \
		pax -rw docs examples ${PORTDESTDIR}
.endif

post-install:
.if defined(NOPORTDOCS)
	cd ${INSTALL_WRKSRC}; \
		${CP} ${TMPPLIST} ${TMPPLIST}.nodoc ; \
	${GREP} -v share/java/${CRIMSON_SUBDIR} ${TMPPLIST}.nodoc > ${TMPPLIST}; \
	${RM} ${TMPPLIST}.nodoc
.endif
	@ ${SED} "s|%%PREFIX%%|${PREFIX}|g" ${PKGMESSAGE}

.include <bsd.port.mk>
