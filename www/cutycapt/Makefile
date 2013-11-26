# Created by: Axel Gonzalez <loox@e-shell.net>
# $FreeBSD$

PORTNAME=	cutycapt
PORTVERSION=	20100608
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://bsd.e-shell.net/local/

MAINTAINER=	loox@e-shell.net
COMMENT=	Command-line utility to capture WebKit's rendering of a web page

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/CutyCapt

USES=		qmake
USE_QT4=	moc_build imageformats_run webkit

PLIST_FILES=	bin/CutyCapt

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/CutyCapt ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
