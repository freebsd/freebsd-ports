# New ports collection makefile for:	BitTorrent
# Date created:		Sun Mar 16 06:34:12 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	BitTorrent
PORTVERSION=	3.4.2
PORTEPOCH=	1
CATEGORIES?=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME:L}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
#DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(.)$/\1/}

MAINTAINER=	lioux@FreeBSD.org
COMMENT?=	A peer-to-peer tool for distributing files written in Python

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_REINPLACE=	yes

CONFLICTS=	py??-*[Bb]it[Tt]orrent*

PORTDOCS=	BUILD.windows.txt INSTALL.unix.txt LICENSE.txt \
		README.txt credits.txt

# required for GUI
.ifndef(WITHOUT_GUI)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/wxPython/__init__.py:${PORTSDIR}/x11-toolkits/py-wxPython

PLIST_SUB+=	GUI=''
PLIST_FILES+=	\
		bin/btcompletedirgui.py \
		bin/btdownloadgui.py
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-nogui-patch-setup.py
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
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
