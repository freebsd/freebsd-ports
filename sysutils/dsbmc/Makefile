# Created by: Marcel Kaiser <mk@nic-nac-project.org>
# $FreeBSD$

PORTNAME=	dsbmc
DISTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://freeshell.de/~mk/download/

MAINTAINER=	mk@nic-nac-project.org
COMMENT=	Qt client for DSBMD that lets you mount media, and more

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	dsbmd>=0.3:sysutils/dsbmd

USES=		compiler:c++11-lang desktop-file-utils gl qmake qt:5 tar:tgz

USE_GL=		gl
USE_QT=		buildtools_build core gui linguisttools_build widgets

.include <bsd.port.mk>
