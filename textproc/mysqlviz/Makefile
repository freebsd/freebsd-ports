# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mysqlviz
PORTVERSION=	0.3
CATEGORIES=	textproc
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	tota@FreeBSD.org
COMMENT=	MySQL and SQLite Database Visualisation Tool

NO_BUILD=	yes
USE_BZIP2=	yes
USE_PHP=	yes
WANT_PHP_CLI=	yes

PLIST_FILES=	bin/${PORTNAME}

PORTEXAMPLES=	eg.png eg.sql sqlite-eg.sql

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} \
		-e 's|/usr/bin/php|${LOCALBASE}/bin/php|' \
		${WRKSRC}/${PORTNAME}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
