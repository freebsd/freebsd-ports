# Created by: Axel Gonzalez <loox@e-shell.net>
# $FreeBSD$

PORTNAME=	cutycapt
PORTVERSION=	20100608
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://bsd.e-shell.net/local/

MAINTAINER=	loox@e-shell.net
COMMENT=	Command-line utility to capture WebKit's rendering of a web page

LICENSE=	GPLv2

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

WRKSRC=		${WRKDIR}/CutyCapt

USES=		qmake qt:4
USE_QT=		moc_build imageformats_run webkit

PLIST_FILES=	bin/CutyCapt

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/CutyCapt ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
