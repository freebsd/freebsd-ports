# New ports collection makefile for:	BitTorrent
# Date created:		Sun Mar 16 06:34:12 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	BitTorrent
PORTVERSION=	3.4.2
PORTREVISION=	4
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

CONFLICTS=	py??-*[Bb]it[Tt]orrent* py??-*[Bb]it[Tt]ornado* btqueue*

PORTDOCS=	BUILD.windows.txt INSTALL.unix.txt LICENSE.txt \
		README.txt credits.txt

# required for GUI
.ifndef(WITHOUT_GUI)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/wxPython/__init__.py:${PORTSDIR}/x11-toolkits/py-wxPython

PLIST_FILES+=	\
		bin/btcompletedirgui.py \
		bin/btdownloadgui.py
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-nogui-patch-setup.py
.endif
# required for PSYCO
.ifndef(WITHOUT_PSYCO)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psyco/_psyco.so:${PORTSDIR}/devel/py-psyco

EXTRA_PATCHES+= \
		${FILESDIR}/extra-psyco-patch-btcompletedir.py \
		${FILESDIR}/extra-psyco-patch-btcompletedirgui.py \
		${FILESDIR}/extra-psyco-patch-btdownloadcurses.py \
		${FILESDIR}/extra-psyco-patch-btdownloadgui.py \
		${FILESDIR}/extra-psyco-patch-btdownloadheadless.py \
		${FILESDIR}/extra-psyco-patch-btlaunchmany.py \
		${FILESDIR}/extra-psyco-patch-btlaunchmanycurses.py \
		${FILESDIR}/extra-psyco-patch-btmakemetafile.py \
		${FILESDIR}/extra-psyco-patch-bttrack.py

PLIST_FILES+=	\
		${PYTHON_SITELIBDIR:S|^${PYTHONBASE}/||}/BitTorrent/PSYCO.py \
		${PYTHON_SITELIBDIR:S|^${PYTHONBASE}/||}/BitTorrent/PSYCO.pyc \
		${PYTHON_SITELIBDIR:S|^${PYTHONBASE}/||}/BitTorrent/PSYCO.pyo
.endif

pre-everything::
.ifndef(WITHOUT_GUI)
	@${ECHO_MSG} '===> Define WITHOUT_GUI to disable GUI installation'
.endif
.ifndef(WITHOUT_PSYCO)
	@${ECHO_MSG} '===> Define WITHOUT_PSYCO to disable devel/py-psyco optimization'
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
.ifndef(WITHOUT_PSYCO)
# activate psyco optimization
	@${ECHO_CMD} 'psyco = 1' > ${WRKSRC}/BitTorrent/PSYCO.py
.endif

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
# set proper permissions
	@${CHMOD} -R ${SHAREMODE} \
		${PREFIX}/${PYTHON_SITELIBDIR:S|^${PYTHONBASE}/||}/BitTorrent
	@${CHMOD} ${SHAREMODE} ${PREFIX}/${PYTHON_SITELIBDIR:S|^${PYTHONBASE}/||}/BitTorrent
	@${CHMOD} a+x ${PREFIX}/${PYTHON_SITELIBDIR:S|^${PYTHONBASE}/||}/BitTorrent

.include <bsd.port.mk>
