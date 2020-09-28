# $FreeBSD$

PORTNAME=	evhz
DISTVERSION=	g20170201
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Tool for measuring evdev event rate (mouse polling rate)

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto

USES=		compiler localbase
USE_GITLAB=	yes

GL_ACCOUNT=	iankelling
GL_COMMIT=	3b656489b70838afaeb33359cb0086e2a184c81f

PLIST_FILES=	bin/${PORTNAME}

do-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${CC} ${CFLAGS} -o ${PORTNAME} ${PORTNAME}.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
