# $FreeBSD$

PORTNAME=	qtkeychain
PORTVERSION=	0.1.0
CATEGORIES=	security

MAINTAINER=	6yearold@gmail.com
COMMENT=	Platform independent Qt API for storing passwords

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	frankosterfeld
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	bb32e45

CONFIGURE_ENV=	HOME=${WRKDIR}/.home

USES=	cmake
USE_QT4=	corelib dbus moc_build qmake_build rcc_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
