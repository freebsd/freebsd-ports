# Created by: Joe Horn <joehorn@gmail.com>
# $FreeBSD$

PORTNAME=	CKEditor
PORTVERSION=	4.0
CATEGORIES=	www
MASTER_SITES=	http://download.cksource.com/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}/
DISTNAME=	ckeditor_${PORTVERSION}_full

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WYSIWYG editor to be used inside web page

LICENSE=	MPL

NO_BUILD=	yes
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/ckeditor

do-install:
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
