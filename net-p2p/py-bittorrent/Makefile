# New ports collection makefile for:	BitTorrent
# Date created:		Sun Mar 16 06:34:12 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	BitTorrent
PORTVERSION=	4.0.0
PORTEPOCH=	1
CATEGORIES?=	net python
MASTER_SITES=	http://www.bittorrent.com/dl/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lioux@FreeBSD.org
COMMENT?=	A peer-to-peer tool for distributing files written in Python

BROKEN=		Incomplete pkg-plist

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_REINPLACE=	yes

CONFLICTS=	py??-*[Bb]it[Tt]orrent* py??-*[Bb]it[Tt]ornado* btqueue*

PORTDOCS=	LICENSE.txt \
		redirdonate.html \
		README.txt credits.txt

.ifdef(NOPORTDOCS)
EXTRA_PATCHES+=	${FILESDIR}/extra-noportdocs-setup.py
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
WITHOUT_PSYCO=	yes
.endif

# required for GUI
.ifndef(WITHOUT_GUI)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/pygtk.py:${PORTSDIR}/x11-toolkits/py-gtk2

PLIST_FILES+=	\
		bin/btmaketorrentgui.py \
		bin/btdownloadgui.py \
		share/pixmaps/BitTorrent/bittorrent.ico \
		share/pixmaps/BitTorrent/broken.png \
		share/pixmaps/BitTorrent/finished.png \
		share/pixmaps/BitTorrent/info.png \
		share/pixmaps/BitTorrent/logo/bittorrent_32.png \
		share/pixmaps/BitTorrent/logo/bittorrent_96.png \
		share/pixmaps/BitTorrent/pause.png \
		share/pixmaps/BitTorrent/paused.png \
		share/pixmaps/BitTorrent/play.png \
		share/pixmaps/BitTorrent/queued.png \
		share/pixmaps/BitTorrent/remove.png \
		share/pixmaps/BitTorrent/running.png

PLIST_DIRS+=	share/pixmaps/BitTorrent/logo \
		share/pixmaps/BitTorrent

.else
EXTRA_PATCHES+=	${FILESDIR}/extra-nogui-patch-setup.py
.endif
# required for PSYCO
.ifndef(WITHOUT_PSYCO)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psyco/_psyco.so:${PORTSDIR}/devel/py-psyco

EXTRA_PATCHES+= \
		${FILESDIR}/extra-psyco-patch-btdownloadcurses.py \
		${FILESDIR}/extra-psyco-patch-btdownloadheadless.py \
		${FILESDIR}/extra-psyco-patch-btlaunchmany.py \
		${FILESDIR}/extra-psyco-patch-btlaunchmanycurses.py \
		${FILESDIR}/extra-psyco-patch-btmaketorrent.py \
		${FILESDIR}/extra-psyco-patch-btreannouce.py \
		${FILESDIR}/extra-psyco-patch-btrename.py \
		${FILESDIR}/extra-psyco-patch-btshowmetainfo.py \
		${FILESDIR}/extra-psyco-patch-bttest.py \
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
		-e 's|/usr/bin/env python.*|${LOCALBASE}/bin/python|'
.ifndef(WITHOUT_PSYCO)
# activate psyco optimization
	@${ECHO_CMD} 'psyco = 1' > ${WRKSRC}/BitTorrent/PSYCO.py
.endif

post-install:
# set proper permissions
	@${CHMOD} -R ${SHAREMODE} \
		${PREFIX}/${PYTHON_SITELIBDIR:S|^${PYTHONBASE}/||}/BitTorrent
	@${CHMOD} ${SHAREMODE} ${PREFIX}/${PYTHON_SITELIBDIR:S|^${PYTHONBASE}/||}/BitTorrent
	@${CHMOD} a+x ${PREFIX}/${PYTHON_SITELIBDIR:S|^${PYTHONBASE}/||}/BitTorrent
.ifndef(WITHOUT_GUI)
# pixmaps
	@${CHMOD} -R ${SHAREMODE} \
		${PREFIX}/share/pixmaps/${PORTNAME}/*
	@${CHMOD} a+x \
		${PREFIX}/share/pixmaps/${PORTNAME}/logo
.endif
.ifndef(NOPORTDOCS)
# docs
	@${CHMOD} -R ${SHAREMODE} \
		${DOCSDIR}/*
.endif

.include <bsd.port.post.mk>
