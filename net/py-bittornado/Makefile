# New ports collection makefile for:	shadow-BitTorrent
# Date created:		23 February 2004
# Whom:			Stefan Walter <sw@gegenunendlich.de>
#
# $FreeBSD$
#

PORTNAME=	BitTornado
PORTVERSION=	0.3.10
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES?=	net python ipv6
MASTER_SITES=	http://www.bittornado.com/download/ \
		http://e.scarywater.net/bt/download/ \
		http://mediahost.inetsalestech.com/shadow/ \
		http://www.hypermax.net.au/~gamr/ \
		http://ftp.acc.umu.se/mirror/bittornado/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT?=	An extended BitTorrent peer-to-peer tool for distributing files

CONFLICTS=	py??-*[Bb]it[Tt]ornado-core-[0-9]* py??-*[Bb]it[Tt]orrent*-[0-9]* btqueue-[0-9]*
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-CVS

DOC_FILES1=	BUILD.windows.txt FAQ.txt IMPORTANT-multitracker-readme.txt \
		INSTALL.unix.txt credits.txt multitracker-spec.txt \
		README-Psyco.txt webseed-spec.txt
DOC_FILES2=	LICENSE.txt README.txt
EXTRA_DOC_FILES=	multitracker/README.txt
MAN1=		bittorrent-downloader.1 bittorrent-multi-downloader.1 \
		btcompletedir.1 btcopyannounce.1 btdownloadcurses.1 \
		btdownloadgui.1 btdownloadheadless.1 btlaunchmany.1 \
		btlaunchmanycurses.1 btmakemetafile.1 btreannounce.1 \
		btrename.1 btsethttpseeds.1 btshowmetainfo.1 bttrack.1

# required for GUI
.ifndef(WITHOUT_GUI)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/wxPython/__init__.py:${PORTSDIR}/x11-toolkits/py-wxPython24
PLIST_SUB+=	GUI=''
EXTRA_PATCHES+=	${FILESDIR}/extra-gui-patch-setup.py
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-nogui-patch-setup.py
PLIST_SUB+=	GUI='@comment '
.endif
.ifdef(WITH_IPV6)
#disable compact announcement that is incompatible with IPv6
#tracker does not patched to honor compact announcements
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-BitTornado_BT1_Rerequester.py
.endif

.ifdef(WITH_PSYCO)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psyco/_psyco.so:${PORTSDIR}/devel/py-psyco
post-patch:
	@${REINPLACE_CMD} -e "s/^psyco = 0/psyco = 1/g" \
		${WRKSRC}/BitTornado/PSYCO.py
.endif

pre-everything::
.ifndef(WITHOUT_GUI)
	@${ECHO_MSG} '===> Define WITHOUT_GUI to disable GUI installation'
.endif
.ifndef(WITH_PSYCO)
	@${ECHO_MSG} '===> Define WITH_PSYCO to enable the optimizing Python compiler'
.endif
.ifndef(WITH_IPV6)
	@${ECHO_MSG} '===> Define WITH_IPV6 to enable IPv6 support properly'
	@${ECHO_MSG} 'with trade-off of more memory usage'
.endif

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES1}
	@${INSTALL_DATA} ${WRKSRC}/docs/${file} ${DOCSDIR}
.endfor
.for file in ${DOC_FILES2}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.for file in ${EXTRA_DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}/`${ECHO} ${file} | ${SED} -e 's|/|_|g'`
.endfor
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${FILESDIR}/bittornado.sh.sample ${EXAMPLESDIR}
.endif
.ifndef(NO_INSTALL_MANPAGES)
.for file in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/docs/man/${file} ${PREFIX}/man/man1
.endfor
.endif

.include <bsd.port.mk>
