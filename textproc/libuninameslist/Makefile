# Created by: KANOU Hiroki <kanou@khdd.net>
# $FreeBSD$

PORTNAME=	libuninameslist
PORTVERSION=	20200413
CATEGORIES=	textproc

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Library of Unicode annotation data

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf gmake libtool

USE_GITHUB=	yes
GH_ACCOUNT=	fontforge
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

MAKE_JOBS_UNSAFE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	FRENCH
OPTIONS_DEFAULT=FRENCH
OPTIONS_SUB=yes

FRENCH_DESC=	Build French library
FRENCH_CONFIGURE_ENABLE=	frenchlib

.include <bsd.port.mk>
