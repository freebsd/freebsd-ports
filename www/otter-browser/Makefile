PORTNAME=	otter-browser
DISTVERSIONPREFIX=	v
# Occasionally otter-browser is updated to intermediate commits;
# releases are rather infrequent. To update to an intermediate:
# - Make up a PORTVERSION that resembles the DISTVERSION, add a
#   .tweak number to it, comment-out DISTVERSION
# - Set a GH_TAG to the intermediate commit (below)
# - Add a comment here to indicate that the intermediate is
#   intentional
#
# PORTVERSION=	1.0.01.1
DISTVERSION=	1.0.03
PORTREVISION=	2
CATEGORIES=	www

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Browser based on Qt 5
WWW=		https://otter-browser.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell

USES=		cmake compiler:c++11-lib desktop-file-utils qt:5
USE_QT=		concurrent core dbus declarative gui location multimedia \
		network printsupport script sql sql-sqlite3 svg \
		webchannel webengine widgets xmlpatterns \
		buildtools:build qmake:build

USE_GITHUB=	yes
GH_ACCOUNT=	OtterBrowser
# GH_TAGNAME=	22de58d  # For intermediate versions only

CMAKE_ON=	ENABLE_QTWEBENGINE

.include <bsd.port.mk>
