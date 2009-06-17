# New ports collection makefile for:	BitTorrent
# Date created:		Sun Mar 16 06:34:12 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	BitTorrent
PORTVERSION=	5.2.0
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES?=	net-p2p python
MASTER_SITES=	http://download.bittorrent.com/dl/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bhaga@absoludicrous.com
COMMENT?=	A peer-to-peer tool for distributing files written in Python

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/dns/__init__.py:${PORTSDIR}/dns/py-dnspython \
		${PYTHON_SITELIBDIR}/Crypto/__init__.py:${PORTSDIR}/security/py-pycrypto

USE_GETTEXT=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_TWISTED=	web

CONFLICTS=	py??-*[Bb]it[Tt]orrent* py??-*[Bb]it[Tt]ornado* btqueue*

.ifndef(NOPORTDOCS)
PORTDOCS=	\
		INSTALL.unix.txt \
		LICENSE.txt \
		README.txt \
		TRACKERLESS.txt \
		credits.txt \
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
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/wx-2.6-gtk2-unicode/wxPython/__init__.py:${PORTSDIR}/x11-toolkits/py-wxPython26-unicode

PLIST_FILES+=	\
		bin/bittorrent \
		bin/maketorrent \
		share/pixmaps/BitTorrent/bittorrent.ico \
		share/pixmaps/BitTorrent/flags/AE.png \
		share/pixmaps/BitTorrent/flags/AR.png \
		share/pixmaps/BitTorrent/flags/AT.png \
		share/pixmaps/BitTorrent/flags/AU.png \
		share/pixmaps/BitTorrent/flags/BE.png \
		share/pixmaps/BitTorrent/flags/BG.png \
		share/pixmaps/BitTorrent/flags/BR.png \
		share/pixmaps/BitTorrent/flags/CA.png \
		share/pixmaps/BitTorrent/flags/CH.png \
		share/pixmaps/BitTorrent/flags/CL.png \
		share/pixmaps/BitTorrent/flags/CN.png \
		share/pixmaps/BitTorrent/flags/CO.png \
		share/pixmaps/BitTorrent/flags/CY.png \
		share/pixmaps/BitTorrent/flags/CZ.png \
		share/pixmaps/BitTorrent/flags/DE.png \
		share/pixmaps/BitTorrent/flags/DK.png \
		share/pixmaps/BitTorrent/flags/ES.png \
		share/pixmaps/BitTorrent/flags/EU.png \
		share/pixmaps/BitTorrent/flags/FI.png \
		share/pixmaps/BitTorrent/flags/FR.png \
		share/pixmaps/BitTorrent/flags/GB.png \
		share/pixmaps/BitTorrent/flags/GR.png \
		share/pixmaps/BitTorrent/flags/GT.png \
		share/pixmaps/BitTorrent/flags/HK.png \
		share/pixmaps/BitTorrent/flags/HU.png \
		share/pixmaps/BitTorrent/flags/IT.png \
		share/pixmaps/BitTorrent/flags/JP.png \
		share/pixmaps/BitTorrent/flags/KR.png \
		share/pixmaps/BitTorrent/flags/KW.png \
		share/pixmaps/BitTorrent/flags/LT.png \
		share/pixmaps/BitTorrent/flags/LV.png \
		share/pixmaps/BitTorrent/flags/MX.png \
		share/pixmaps/BitTorrent/flags/NA.png \
		share/pixmaps/BitTorrent/flags/NL.png \
		share/pixmaps/BitTorrent/flags/NO.png \
		share/pixmaps/BitTorrent/flags/PR.png \
		share/pixmaps/BitTorrent/flags/PT.png \
		share/pixmaps/BitTorrent/flags/RU.png \
		share/pixmaps/BitTorrent/flags/SE.png \
		share/pixmaps/BitTorrent/flags/SG.png \
		share/pixmaps/BitTorrent/flags/SI.png \
		share/pixmaps/BitTorrent/flags/TW.png \
		share/pixmaps/BitTorrent/flags/US.png \
		share/pixmaps/BitTorrent/flags/YU.png \
		share/pixmaps/BitTorrent/flags/ZA.png \
		share/pixmaps/BitTorrent/flags/noimage.png \
		share/pixmaps/BitTorrent/flags/unknown.png \
		share/pixmaps/BitTorrent/logo/banner.png \
		share/pixmaps/BitTorrent/logo/bittorrent_icon.png \
		share/pixmaps/BitTorrent/logo/bittorrent_icon_16.png \
		share/pixmaps/BitTorrent/logo/bittorrent_icon_24.png \
		share/pixmaps/BitTorrent/logo/bittorrent_icon_32.png \
		share/pixmaps/BitTorrent/logo/bittorrent_icon_48.png \
		share/pixmaps/BitTorrent/themes/default/add_16.png \
		share/pixmaps/BitTorrent/themes/default/add_24.png \
		share/pixmaps/BitTorrent/themes/default/add_32.png \
		share/pixmaps/BitTorrent/themes/default/fileops/first_16.png \
		share/pixmaps/BitTorrent/themes/default/fileops/first_24.png \
		share/pixmaps/BitTorrent/themes/default/fileops/first_32.png \
		share/pixmaps/BitTorrent/themes/default/fileops/never_16.png \
		share/pixmaps/BitTorrent/themes/default/fileops/never_24.png \
		share/pixmaps/BitTorrent/themes/default/fileops/never_32.png \
		share/pixmaps/BitTorrent/themes/default/fileops/normal_16.png \
		share/pixmaps/BitTorrent/themes/default/fileops/normal_24.png \
		share/pixmaps/BitTorrent/themes/default/fileops/normal_32.png \
		share/pixmaps/BitTorrent/themes/default/progressbar.png \
		share/pixmaps/BitTorrent/themes/default/search_16.png \
		share/pixmaps/BitTorrent/themes/default/search_24.png \
		share/pixmaps/BitTorrent/themes/default/search_32.png \
		share/pixmaps/BitTorrent/themes/default/settings_16.png \
		share/pixmaps/BitTorrent/themes/default/settings_24.png \
		share/pixmaps/BitTorrent/themes/default/settings_32.png \
		share/pixmaps/BitTorrent/themes/default/statuslight/broken.png \
		share/pixmaps/BitTorrent/themes/default/statuslight/natted.png \
		share/pixmaps/BitTorrent/themes/default/statuslight/pre-natted.png \
		share/pixmaps/BitTorrent/themes/default/statuslight/running.png \
		share/pixmaps/BitTorrent/themes/default/statuslight/starting.png \
		share/pixmaps/BitTorrent/themes/default/statuslight/stopped.png \
		share/pixmaps/BitTorrent/themes/default/torrentops/info_16.png \
		share/pixmaps/BitTorrent/themes/default/torrentops/info_24.png \
		share/pixmaps/BitTorrent/themes/default/torrentops/info_32.png \
		share/pixmaps/BitTorrent/themes/default/torrentops/launch_16.png \
		share/pixmaps/BitTorrent/themes/default/torrentops/launch_24.png \
		share/pixmaps/BitTorrent/themes/default/torrentops/launch_32.png \
		share/pixmaps/BitTorrent/themes/default/torrentops/remove_16.png \
		share/pixmaps/BitTorrent/themes/default/torrentops/remove_24.png \
		share/pixmaps/BitTorrent/themes/default/torrentops/remove_32.png \
		share/pixmaps/BitTorrent/themes/default/torrentops/resume_16.png \
		share/pixmaps/BitTorrent/themes/default/torrentops/resume_24.png \
		share/pixmaps/BitTorrent/themes/default/torrentops/resume_32.png \
		share/pixmaps/BitTorrent/themes/default/torrentops/stop_16.png \
		share/pixmaps/BitTorrent/themes/default/torrentops/stop_24.png \
		share/pixmaps/BitTorrent/themes/default/torrentops/stop_32.png \
		share/pixmaps/BitTorrent/themes/default/torrentstate/complete.png \
		share/pixmaps/BitTorrent/themes/default/torrentstate/created.png \
		share/pixmaps/BitTorrent/themes/default/torrentstate/downloading.png \
		share/pixmaps/BitTorrent/themes/default/torrentstate/error.png \
		share/pixmaps/BitTorrent/themes/default/torrentstate/finishing.png \
		share/pixmaps/BitTorrent/themes/default/torrentstate/force-seed.png \
		share/pixmaps/BitTorrent/themes/default/torrentstate/paused.png \
		share/pixmaps/BitTorrent/themes/default/torrentstate/seeding.png \
		share/pixmaps/BitTorrent/themes/default/torrentstate/starting.png \
		share/pixmaps/BitTorrent/themes/default/torrentstate/stopped.png \
		share/pixmaps/BitTorrent/themes/default/torrentstate/unknown.png

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

# public.key
PLIST_DIRS+=	\
		%%DATADIR%%
PLIST_FILES+=	\
		%%DATADIR%%/public.key

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
		-e "s|'public.key',||" \
		${WRKSRC}/setup.py

post-patch:
# public.key will be located under ${DATADIR} not ${DOCSDIR}
	@${REINPLACE_CMD} -E \
		-e "s|%%DATADIR%%|'${DATADIR}/'|" \
		${WRKSRC}/BitTorrent/AutoUpdateButler.py

post-install:
# set proper permissions
	@${CHMOD} -R ${SHAREMODE} \
		${PYTHONPREFIX_SITELIBDIR}/BitTorrent
	@${CHMOD} ${SHAREMODE} ${PYTHONPREFIX_SITELIBDIR}/BitTorrent
	@${CHMOD} -R a+X ${PYTHONPREFIX_SITELIBDIR}/BitTorrent
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
# install missing doc
	@${INSTALL_DATA} ${WRKSRC}/TRACKERLESS.txt ${DOCSDIR}
.endif
# public.key
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/public.key ${DATADIR}

.include <bsd.port.post.mk>
