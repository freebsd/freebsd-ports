# New ports collection makefile for:	Kenosis enabled BitTorrent
# Date created:		Thu Jan 13 01:15:19 UTC 2005
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kenosis
PORTVERSION=	${KENOSIS_VERSION}.0.3.4.2
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES?=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:L}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-BitTorrent
DISTNAME=	${KENOSIS_DISTNAME}

MAINTAINER=	lioux@FreeBSD.org
COMMENT?=	A Kenosis enabled, distributed BitTorrent

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/kenosis/__init__.py:${PORTSDIR}/net/py-kenosis

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/bt

DOC_FILES=	\
		BUILD.windows.txt INSTALL.unix.txt LICENSE.txt \
		README_KENOSIS.txt \
		README.txt credits.txt
PORTDOCS=	\
		README-FreeBSD.txt \
		${DOC_FILES}

.include <bsd.port.pre.mk>

#KENOSIS_PORTDIR=	../py-kenosis
KENOSIS_PORTDIR=	${PORTSDIR}/net/py-kenosis
KENOSIS_DISTNAME!=	cd ${KENOSIS_PORTDIR} && make -V DISTNAME
KENOSIS_VERSION!=	cd ${KENOSIS_PORTDIR} && make -V PORTVERSION

.if ${ARCH} != "i386"
WITHOUT_PSYCO=	yes
.endif

# required for GUI
.ifndef(WITHOUT_GUI)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/wxPython/__init__.py:${PORTSDIR}/x11-toolkits/py-wxPython24

EXTRA_PATCHES+=	${FILESDIR}/extra-gui-patch-setup.py

PLIST_FILES+=	\
		libexec/${PORTNAME}${PKGNAMESUFFIX}/btcompletedirgui.py \
		libexec/${PORTNAME}${PKGNAMESUFFIX}/btdownloadgui.py
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
		%%PYTHON_SITELIBDIR%%/${PORTNAME}${PKGNAMESUFFIX:S/^-/_/}/PSYCO.py \
		%%PYTHON_SITELIBDIR%%/${PORTNAME}${PKGNAMESUFFIX:S/^-/_/}/PSYCO.pyc \
		%%PYTHON_SITELIBDIR%%/${PORTNAME}${PKGNAMESUFFIX:S/^-/_/}/PSYCO.pyo
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
		-e 's|from[[:space:]]+BitTorrent|from ${PORTNAME}${PKGNAMESUFFIX:S/^-/_/}|' \
		-e 's|import[[:space:]]+BitTorrent|import ${PORTNAME}${PKGNAMESUFFIX:S/^-/_/}|' \
		-e 's|from[[:space:]]+ds|from ${PORTNAME}.ds|' \
		-e 's|/usr/bin/env python|${LOCALBASE}/bin/python|'
	@${REINPLACE_CMD} -E \
		-e 's|%%KENOSIS-BITTORRENT%%|${PORTNAME}${PKGNAMESUFFIX:S/^-/_/}|' \
		${WRKSRC}/${PYSETUP}
	@${REINPLACE_CMD} -E \
		-e 's|bt.BitTorrent|${PORTNAME}${PKGNAMESUFFIX:S/^-/_/}|' \
		-e 's|from[[:space:]]+bt[[:space:]]+||' \
		${WRKSRC}/btunittest.py
.ifdef(WITHOUT_GUI)
	@${REINPLACE_CMD} -E \
		-e 's|btdownloadgui.py|btdownloadcurses.py|' \
		${WRKSRC}/INSTALL.unix.txt
.endif
.ifndef(WITHOUT_PSYCO)
# activate psyco optimization
	@${ECHO_CMD} 'psyco = 1' > ${WRKSRC}/BitTorrent/PSYCO.py
.endif

pre-configure:
	@${MV} ${WRKSRC}/BitTorrent ${WRKSRC}/${PORTNAME}${PKGNAMESUFFIX:S/^-/_/}

post-install:
	@${CAT} ${PKGMESSAGE}
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	@${INSTALL_DATA} ${PKGMESSAGE} ${DOCSDIR}/README-FreeBSD.txt
.endif
# set proper permissions
	@${CHMOD} -R ${SHAREMODE} \
		${PREFIX}/${PYTHON_SITELIBDIR:S|^${PYTHONBASE}/||}/${PORTNAME}${PKGNAMESUFFIX:S/^-/_/}
	@${CHMOD} ${SHAREMODE} \
		${PREFIX}/${PYTHON_SITELIBDIR:S|^${PYTHONBASE}/||}/${PORTNAME}${PKGNAMESUFFIX:S/^-/_/}
	@${CHMOD} a+x \
		${PREFIX}/${PYTHON_SITELIBDIR:S|^${PYTHONBASE}/||}/${PORTNAME}${PKGNAMESUFFIX:S/^-/_/}

.include <bsd.port.post.mk>

DOCSDIR:=	${DOCSDIR:S!${PORTNAME}$!${PORTNAME}${PKGNAMESUFFIX}!}
PYDISTUTILS_INSTALLARGS:=	${PYDISTUTILS_INSTALLARGS} --install-scripts=${PREFIX}/libexec/${PORTNAME}${PKGNAMESUFFIX}
