# New ports collection makefile for:	BitTorrent
# Date created:		Sun Mar 16 06:34:12 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	BitTorrent
PORTVERSION=	4.4.0
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES?=	net-p2p python
MASTER_SITES=	http://download.bittorrent.com/dl/
MASTER_SITE_SUBDIR=	${PORTNAME:L}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX?=	-devel

MAINTAINER=	lioux@FreeBSD.org
COMMENT?=	A peer-to-peer tool for distributing files written in Python

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/dns/__init__.py:${PORTSDIR}/dns/py-dnspython \
		${PYTHON_SITELIBDIR}/Crypto/__init__.py:${PORTSDIR}/security/py-pycrypto

USE_GETTEXT=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_TWISTED_RUN=	yes

CONFLICTS=	py??-*[Bb]it[Tt]orrent* py??-*[Bb]it[Tt]ornado* btqueue*

NO_LATEST_LINK=	yes

.ifndef(NOPORTDOCS)
PORTDOCS=	\
		LICENSE.txt \
		README.txt \
		TRACKERLESS.txt \
		credits.txt \
		credits-l10n.txt \
		redirdonate.html
.else
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
		bin/bittorrent \
		bin/maketorrent \
		share/pixmaps/BitTorrent/bittorrent.ico \
		share/pixmaps/BitTorrent/icons/default/abort.png \
		share/pixmaps/BitTorrent/icons/default/broken.png \
		share/pixmaps/BitTorrent/icons/default/finished.png \
		share/pixmaps/BitTorrent/icons/default/info.png \
		share/pixmaps/BitTorrent/icons/default/pause.png \
		share/pixmaps/BitTorrent/icons/default/paused.png \
		share/pixmaps/BitTorrent/icons/default/play.png \
		share/pixmaps/BitTorrent/icons/default/queued.png \
		share/pixmaps/BitTorrent/icons/default/remove.png \
		share/pixmaps/BitTorrent/icons/default/running.png \
		share/pixmaps/BitTorrent/icons/default/status-broken.png \
		share/pixmaps/BitTorrent/icons/default/status-natted.png \
		share/pixmaps/BitTorrent/icons/default/status-pre-natted.png \
		share/pixmaps/BitTorrent/icons/default/status-running.png \
		share/pixmaps/BitTorrent/icons/default/status-starting.png \
		share/pixmaps/BitTorrent/icons/default/status-stopped.png \
		share/pixmaps/BitTorrent/icons/default/trashcan.png \
		share/pixmaps/BitTorrent/icons/old/broken.png \
		share/pixmaps/BitTorrent/icons/old/finished.png \
		share/pixmaps/BitTorrent/icons/old/info.png \
		share/pixmaps/BitTorrent/icons/old/pause.png \
		share/pixmaps/BitTorrent/icons/old/paused.png \
		share/pixmaps/BitTorrent/icons/old/play.png \
		share/pixmaps/BitTorrent/icons/old/queued.png \
		share/pixmaps/BitTorrent/icons/old/remove.png \
		share/pixmaps/BitTorrent/icons/old/running.png \
		share/pixmaps/BitTorrent/icons/old/status-broken.png \
		share/pixmaps/BitTorrent/icons/old/status-natted.png \
		share/pixmaps/BitTorrent/icons/old/status-pre-natted.png \
		share/pixmaps/BitTorrent/icons/old/status-running.png \
		share/pixmaps/BitTorrent/icons/old/status-starting.png \
		share/pixmaps/BitTorrent/icons/old/status-stopped.png \
		share/pixmaps/BitTorrent/logo/bittorrent_32.png \
		share/pixmaps/BitTorrent/logo/bittorrent_96.png

PLIST_SUB+=	\
		GUI=""
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-nogui-patch-setup.py

PLIST_SUB+=	\
		GUI="@comment "
.endif
# required for PSYCO
.ifndef(WITHOUT_PSYCO)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psyco/_psyco.so:${PORTSDIR}/devel/py-psyco

EXTRA_PATCHES+=	\
		${FILESDIR}/extra-psyco-patch-bittorrent-console.py \
		${FILESDIR}/extra-psyco-patch-bittorrent-curses.py \
		${FILESDIR}/extra-psyco-patch-bittorrent-tracker.py \
		${FILESDIR}/extra-psyco-patch-bittorrent.py \
		${FILESDIR}/extra-psyco-patch-changetracker-console.py \
		${FILESDIR}/extra-psyco-patch-launchmany-console.py \
		${FILESDIR}/extra-psyco-patch-launchmany-curses.py \
		${FILESDIR}/extra-psyco-patch-maketorrent-console.py \
		${FILESDIR}/extra-psyco-patch-maketorrent.py \
		${FILESDIR}/extra-psyco-patch-torrentinfo-console.py
.endif

pre-everything::
.ifndef(WITHOUT_GUI)
	@${ECHO_MSG} '===> Define WITHOUT_GUI to disable GUI installation'
.endif
.ifndef(WITHOUT_PSYCO)
	@${ECHO_MSG} '===> Define WITHOUT_PSYCO to disable devel/py-psyco optimization'
.endif

pre-patch:
# do not install public.key, we will do it ourselves
	@${REINPLACE_CMD} -E \
		-e "s|^.*'public.key'.*$$||" \
		${WRKSRC}/setup.py

post-patch:
# public.key will be located under ${DATADIR} not ${DOCSDIR}
	@${REINPLACE_CMD} -E \
		-e "s|%%DATADIR%%|'${DATADIR}/'|" \
		${WRKSRC}/BitTorrent/NewVersion.py

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
	@${CHMOD} -R a+X \
		${PREFIX}/share/pixmaps/${PORTNAME}
.endif
.ifndef(NOPORTDOCS)
# docs
	@${CHMOD} -R ${SHAREMODE} \
		${DOCSDIR}/*
.endif
# public.key
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/public.key ${DATADIR}

.include <bsd.port.post.mk>
