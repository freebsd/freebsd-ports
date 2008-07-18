# New ports collection makefile for:	dojo-shrinksafe
# Date created:		2008-05-01
# Whom:			Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		shrinksafe
PORTVERSION=		1.1.1
PORTREVISION=	1
CATEGORIES=		www java
MASTER_SITES=		http://download.dojotoolkit.org/release-${PORTVERSION}/ \
			LOCAL/beech
PKGNAMEPREFIX=		dojo-
DISTNAME=		${PKGNAMEPREFIX}release-${PORTVERSION}-${PORTNAME}

MAINTAINER=		glarkin@FreeBSD.org
COMMENT=		A Javascript code compressor

USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes

PLIST_FILES=	bin/${PKGNAMEPREFIX}${PORTNAME} %%DATADIR%%/custom_rhino.jar
PLIST_DIRS=	%%DATADIR%%
SUB_FILES=	${PKGNAMEPREFIX}${PORTNAME}

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/custom_rhino.jar ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME} ${PREFIX}/bin
	@${CAT} pkg-message

.include <bsd.port.post.mk>
