# New ports collection makefile for:   pastebinit
# Date created:        Thu Feb 21 00:21:23 EST 2008
# Whom:                comperr <comperr.extra@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pastebinit
PORTVERSION=	1.3
CATEGORIES=	misc python
MASTER_SITES=	https://launchpadlibrarian.net/93013084/

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	A command line utility for pastebing

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}configobj>=4.3.2:${PORTSDIR}/devel/py-configobj

USE_PYTHON=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/pastebinit

OPTIONS_DEFINE=	PASTEBINS
PASTEBINS_DESC=	Install default pastebins
OPTIONS_DEFAULT=	PASTEBINS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPASTEBINS}
PORTDATA=	pastebin.d
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
.if ${PORT_OPTIONS:MPASTEBINS}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} pastebin.d ${DATADIR})
.endif

.include <bsd.port.mk>
