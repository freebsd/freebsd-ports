# New ports collection makefile for:	TheSHAD0W's BitTorrent client
# Date created:		Mon Mar  1 02:04:13 UTC 2004
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	shadowclient
PORTVERSION=	5.8.10
CATEGORIES?=	net python
MASTER_SITES=	http://home.elp.rr.com/tur/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	BitTorrent-experimental-S-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT?=	TheSHAD0W's experimental BitTorrent client

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_REINPLACE=	yes
USE_SIZE=	yes
WRKSRC=		${WRKDIR}/bittorrent-CVS-shadowsclient

CONFLICTS=	py-bittorrent-*

DOC_FILES=	BUILD.windows.txt INSTALL.unix.txt LICENSE.txt \
		FAQ.txt IMPORTANT-multitracker-readme.txt \
		README-Psyco.txt README-experimental.txt \
		ipranges.portugal.txt multitracker-spec.txt \
		multitracker/README.txt todo.txt webseed-spec.txt \
		README.txt credits.txt

# required for GUI
.ifndef(WITHOUT_GUI)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/wxPython/__init__.py:${PORTSDIR}/x11-toolkits/py-wxPython

PLIST_SUB+=	GUI=''
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-nogui-patch-setup.py
PLIST_SUB+=	GUI='@comment '
.endif

pre-everything::
.ifndef(WITHOUT_GUI)
	@${ECHO_MSG} '===> Define WITHOUT_GUI to disable GUI installation'
.endif

post-patch:
	@${FIND} ${WRKSRC} -type f | \
		${XARGS} -x -n 10 \
		${REINPLACE_CMD} -E \
		-e 's|/usr/bin/env python2|${LOCALBASE}/bin/python|'
.ifdef(WITHOUT_GUI)
	@${REINPLACE_CMD} -E \
		-e 's|btdownloadgui.py|btdownloadcurses.py|' \
		${WRKSRC}/INSTALL.unix.txt
.endif

post-install:
.ifndef(PORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
