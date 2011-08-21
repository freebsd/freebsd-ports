# New ports collection makefile for:   pastebinit
# Date created:        Thu Feb 21 00:21:23 EST 2008
# Whom:                comperr <comperr.extra@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pastebinit
PORTVERSION=	1.2
CATEGORIES=	misc python
MASTER_SITES=	http://launchpadlibrarian.net/63157878/

MAINTAINER=	eadler@freebsd.org
COMMENT=	A command line utility for pastebing

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}configobj>=4.3.2:${PORTSDIR}/devel/py-configobj

USE_PYTHON=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/pastebinit

OPTIONS=	PASTEBINS	"Install default pastebins" on

.include <bsd.port.pre.mk>

.if defined(WITH_PASTEBINS)
PORTDATA=	pastebin.d
.endif

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/bin/python#${PYTHON_CMD}#' \
	${WRKSRC}/${PORTNAME}
	@${REINPLACE_CMD} -e 's#/etc/#${DATADIR}/#g' \
	${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
.if defined(WITH_PASTEBINS)
	(cd ${WRKSRC} && ${COPYTREE_SHARE} pastebin.d ${DATADIR})
.endif

.include <bsd.port.post.mk>
