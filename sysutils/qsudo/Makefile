# $FreeBSD$

PORTNAME=	qsudo
PORTVERSION=	201710031326
CATEGORIES=	sysutils

MAINTAINER=	jt@ixsystems.com
COMMENT=	Qt sudo front-end

LICENSE=	BSD2CLAUSE

ONLY_FOR_ARCHS=	amd64

RUN_DEPENDS=	${LOCALBASE}/bin/sudo:security/sudo

WRKSRC_SUBDIR=	src-qt5

MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}
MAKE_JOBS_UNSAFE=	yes

USES=		qmake shebangfix tar:xz
USE_LDCONFIG=	yes
USE_QT5=	core gui network svg linguist \
		buildtools x11extras widgets
USE_GL+=	gl

QMAKE_ARGS=	CONFIG+="configure"

USE_GITHUB=	yes
GH_ACCOUNT=	trueos
GH_PROJECT=	qsudo
GH_TAGNAME=	0650d52eab7f643d9b6caab0a1df55c6b1191829

PLIST_FILES=	bin/qsudo

.include <bsd.port.mk>
