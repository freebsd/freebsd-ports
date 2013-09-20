# Created by: Axel Gonzalez <loox@e-shell.net>
# $FreeBSD$

PORTNAME=	cutycapt
PORTVERSION=	20100608
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://bsd.e-shell.net/local/

MAINTAINER=	loox@e-shell.net
COMMENT=	A command-line utility to capture WebKit's rendering of a web page

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/CutyCapt

USE_QT4=	qmake_build moc_build imageformats webkit

PLIST_FILES=	bin/CutyCapt

NO_STAGE=	yes
do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE}

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/CutyCapt ${PREFIX}/bin

.include <bsd.port.mk>
