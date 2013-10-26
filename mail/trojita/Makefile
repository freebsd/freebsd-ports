# Created by: Marco Broeder <marco.broeder@gmx.eu>
# $FreeBSD$

PORTNAME=	trojita
PORTVERSION=	0.3.96
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/src/

MAINTAINER=	marco.broeder@gmx.eu
COMMENT=	Fast cross-platform Qt IMAP e-mail client

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USE_BZIP2=	yes
USE_LDCONFIG=	yes

USES=		cmake compiler:c++11-lib desktop-file-utils
CMAKE_ARGS+=	-DCMAKE_MAKE_PROGRAM:FILEPATH=/usr/bin/make \
		-DWITH_QT5:STRING=OFF -DWITH_TESTS:STRING=OFF

USE_QT4=	linguist_build moc_build qmake_build rcc_build uic_build \
		sql-sqlite3 webkit

HAS_CONFIGURE=	yes
INSTALLS_ICONS=	yes

post-install:

.include <bsd.port.mk>
