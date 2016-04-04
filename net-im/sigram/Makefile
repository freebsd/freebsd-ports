# Created by: Kris Moore <kmoore@freebsd.org>
# $FreeBSD$

PORTNAME=	sigram
PORTVERSION=	0.11182014
PORTREVISION=	2
CATEGORIES=	net-im

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	Qt5 based telegram client

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	sialan-labs
GH_TAGNAME=	ce3fb15

USE_OPENSSL=	yes
USE_QT5=	core gui network opengl xml widgets buildtools_build graphicaleffects \
		multimedia printsupport qml quick quickcontrols widgets \
		sql sql-sqlite3
USES=		compiler:c++11-lib openal:soft qmake
QMAKE_ARGS+=	target.path=${LOCALBASE}/bin

BROKEN=		No longer connects to Telegram network, appears abandonded
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-04-15

.include <bsd.port.pre.mk>

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/sigram
	${CP} -r ${WRKSRC}/build/* ${STAGEDIR}${PREFIX}/share/sigram/
	${RM} ${STAGEDIR}/${PREFIX}/share/sigram/Sigram

.include <bsd.port.post.mk>
