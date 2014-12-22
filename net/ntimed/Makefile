# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ntimed
PORTVERSION=	0.0.2014.12.21
CATEGORIES=	net

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Network time synchronization client

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	bsdphk
GH_PROJECT=	ntimed
GH_COMMIT=	f3810d7
GH_TAGNAME=	${GH_COMMIT}

WRKSRC=	${WRKDIR}/${GH_ACCOUNT}-Ntimed-${GH_COMMIT}

PLIST_FILES=	sbin/ntimed-client

.include <bsd.port.pre.mk>

do-configure:
	cd ${WRKSRC} && ${SH} configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ntimed-client ${STAGEDIR}/${LOCALBASE}/sbin/

.include <bsd.port.post.mk>

