# New ports collection makefile for:    crimson
# Date created:		2000-03-21
# Whom:			Palle Girgensohn
#
# $FreeBSD$
#

PORTNAME=	crimson
PORTVERSION=	1.1.3
PORTREVISION=	1
CATEGORIES=	textproc java
MASTER_SITES=	http://xml.apache.org/dist/crimson/
DISTNAME=	${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	girgen@partitur.se
COMMENT=	Implements the Java API for XML Processing (JAXP)

RUN_DEPENDS=	${JAVAVM}:${PORTSDIR}/java/javavmwrapper

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

NO_BUILD=	yes

JAVAVM?=	${LOCALBASE}/bin/javavm

DOCSDIR=	${PREFIX}/share/doc/java/${PORTNAME}
READMES=	README.html ChangeLog

do-install:
	@ ${MKDIR} ${PREFIX}/share/java/classes; \
	  cd ${INSTALL_WRKSRC}; \
	  ${INSTALL_DATA} crimson.jar ${PREFIX}/share/java/classes
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}; \
	  cd ${INSTALL_WRKSRC}; \
	  ${INSTALL_DATA} ${READMES} ${DOCSDIR}; \
	  ${PAX} -rw docs examples ${DOCSDIR}
.endif

post-install:
	@ ${SED} "s|/usr/local|${PREFIX}|g" ${PKGMESSAGE}

.include <bsd.port.mk>
