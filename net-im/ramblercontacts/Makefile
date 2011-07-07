# New ports collection makefile for:	Rambler Contacts
# Date created:				6 July 2011
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ramblercontacts
PORTVERSION=	0.3.2.1030
CATEGORIES=	net-im
MASTER_SITES=	http://developers.rambler.ru/upload/contacts/
DISTNAME=	${PORTNAME}_v${PORTVERSION}_beta_src

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A free multi-service communication client from Rambler

LICENSE=	GPLv3

USE_DOS2UNIX=	config.inc
USE_XORG=	xscrnsaver
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build designer_build \
		webkit
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

post-patch:
# Remove bogus Byte Order Mark (BOM) from some source files
	@${REINPLACE_CMD} -e '1s/^[^#]*//' ${WRKSRC}/src/utils/balloontip.*
# Apparently, these are results of development on Windoze
	@${REINPLACE_CMD} -e 's/info>/Info>/ ; s/metrics>/Metrics>/' \
		${WRKSRC}/src/plugins/stylesheeteditor/private/qcssparser.cpp
# Fix namespace syntax (curly braces seem to be required in this case)
# Allow the program to find its resources from arbitrary directory (use
# absolute paths)
	@${REINPLACE_CMD} -e '/unix:!macx/s/INSTALL_.*/{ & }/ ; \
		51,53s/\.\./$$$${INSTALL_PREFIX}/' ${WRKSRC}/src/config.inc
# Do not install yet another copy of GPL, we define LICENSE for this
	@${REINPLACE_CMD} -e 's| ../../COPYING||' \
		${WRKSRC}/src/loader/loader.pro

pre-build:
	@cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKEFLAGS}

.include <bsd.port.mk>
