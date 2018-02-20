# $FreeBSD$

PORTNAME=	yapet
DISTVERSION=	1.1
CATEGORIES=	security
MASTER_SITES=	https://yapet.guengel.ch/downloads/

MAINTAINER=	rafi@guengel.ch
COMMENT=	Curses based password manager

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake ncurses ssl
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=		CONVERTERS DOCS NLS
OPTIONS_DEFAULT=	CONVERTERS
OPTIONS_SUB=		yes

CONVERTERS_DESC=	Utilities for importing/exporting CSV files
CONVERTERS_CONFIGURE_ENABLE=	converters

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
