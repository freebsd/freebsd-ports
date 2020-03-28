# Created by: Joe Horn <joehorn@gmail.com>
# $FreeBSD$

PORTNAME=	ckeditor
PORTVERSION=	4.14.0
CATEGORIES=	www
MASTER_SITES=	https://download.cksource.com/CKEditor/CKEditor/CKEditor%20${PORTVERSION}/
DISTNAME=	${PORTNAME}_${PORTVERSION}_full

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	WYSIWYG editor to be used inside web page

LICENSE=	GPLv2+ LGPL21+ MPL11 MPL20
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		zip

NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
