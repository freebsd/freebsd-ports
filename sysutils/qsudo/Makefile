# $FreeBSD$

PORTNAME=	qsudo
PORTVERSION=	201706210948
CATEGORIES=	sysutils

MAINTAINER=	kris@ixsystems.com
COMMENT=	Qt sudo front-end

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${LOCALBASE}/bin/sudo:security/sudo

WRKSRC_SUBDIR=  src-qt5
MAKE_ARGS=      PREFIX=${STAGEDIR}${PREFIX}
MAKE_JOBS_UNSAFE=yes
ONLY_FOR_ARCHS= amd64
USE_LDCONFIG=   yes
USE_QT5=        core gui network svg linguist \
		buildtools x11extras widgets
USES=           qmake shebangfix tar:xz
USE_GL+=	gl

QMAKE_ARGS=     CONFIG+="configure"

USE_GITHUB=	yes
GH_ACCOUNT=	trueos
GH_PROJECT=	qsudo
GH_TAGNAME=	56208c3d670d45d8bbed02cd4bb794ac2050abfa

PLIST_FILES=	bin/qsudo

.include <bsd.port.mk>
