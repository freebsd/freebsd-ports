# $FreeBSD$

PORTNAME=	yapet
PORTVERSION=	1.0
CATEGORIES=	security
MASTER_SITES=	http://www.guengel.ch/myapps/yapet/downloads/

MAINTAINER=	rafi@guengel.ch
COMMENT=	Curses based password manager

LICENSE=	GPLv3

USES=		gmake
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--enable-silent-rules

OPTIONS_DEFINE=		CONVERTERS DOCS NLS
OPTIONS_DEFAULT=	CONVERTERS
OPTIONS_SUB=		yes

CONVERTERS_DESC=	Utilities for importing/exporting CSV files
CONVERTERS_CONFIGURE_ENABLE=	converters

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
NLS_CPPFLAGS=		-I${LOCALBASE}/include
NLS_LDFLAGS=		-L${LOCALBASE}/lib

.include <bsd.port.mk>
