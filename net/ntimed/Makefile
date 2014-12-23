# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ntimed
PORTVERSION=	0.0.2014.12.21
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Network time synchronization client

LICENSE=	BSD2CLAUSE

USE_RC_SUBR=	ntimed

USE_GITHUB=	yes
GH_ACCOUNT=	bsdphk
GH_PROJECT=	Ntimed
GH_COMMIT=	f3810d7
GH_TAGNAME=	${GH_COMMIT}

PLIST_FILES=	sbin/ntimed-client

do-configure:
	cd ${WRKSRC} && ${SH} configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ntimed-client ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
