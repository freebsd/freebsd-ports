# New ports collection makefile for:    Xerces
# Date created:		2000/08/12
# Whom:			Marcin Cieslak
#
# $FreeBSD$
#

PORTNAME=	xerces
PORTVERSION=	1.3.1
CATEGORIES=	textproc
MASTER_SITES=	http://xml.apache.org/dist/xerces-j/
DISTNAME=	Xerces-J-bin.${PORTVERSION}

MAINTAINER=	kevlo@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/jdk${JDK_VERSION}/bin/java:${PORTSDIR}/java/jdk

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/./_/g}
JDK_VERSION=	1.1.8
NO_BUILD=	yes

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

.include <bsd.port.pre.mk>

do-install:
	@cd ${WRKSRC}; \
		${MKDIR} ${PREFIX}/share/java/classes/; \
		${INSTALL_DATA} ${WRKSRC}/xerces.jar ${WRKSRC}/xercesSamples.jar ${PREFIX}/share/java/classes/; \
		${MKDIR} ${PREFIX}/share/java/${PKGNAME}/; \
		${CP} LICENSE ${PREFIX}/share/java/${PKGNAME}/; \
		${CP} -R docs ${PREFIX}/share/java/${PKGNAME}/; \
		${CP} -R data ${PREFIX}/share/java/${PKGNAME}/; \
		${CP} -R samples ${PREFIX}/share/java/${PKGNAME}/

.include <bsd.port.post.mk>
