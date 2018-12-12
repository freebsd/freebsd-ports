# $FreeBSD$

PORTNAME=	qsudo
DISTVERSION=	201711240000
PORTREVISION=	1
CATEGORIES=	sysutils security

MAINTAINER=	jt@ixsystems.com
COMMENT=	Qt sudo front-end

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

RUN_DEPENDS=	sudo:security/sudo

USES=		compiler:c++11-lang qmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	trueos
GH_TAGNAME=	815e31c
USE_QT=		core gui widgets buildtools_build

WRKSRC_SUBDIR=	src-qt5
LDFLAGS+=	-Wl,--as-needed  # prevents unnecessary USE_GL=gl, see bug#224488

PLIST_FILES=	bin/qsudo

.include <bsd.port.mk>
