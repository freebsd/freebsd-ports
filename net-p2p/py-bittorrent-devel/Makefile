# New ports collection makefile for:	BitTorrent
# Date created:		Sun Mar 16 06:34:12 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	BitTorrent
PORTVERSION=	3.3
PORTREVISION=	1
CATEGORIES?=	net python
MASTER_SITES=	http://bitconjurer.org/BitTorrent/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
#DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(.)$/\1/}

MAINTAINER=	lioux@FreeBSD.org
COMMENT?=	A peer-to-peer tool for distributing files written in Python

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_REINPLACE=	yes
USE_SIZE=	yes

DOC_FILES=	BUILD.windows.txt INSTALL.unix.txt LICENSE.txt \
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
