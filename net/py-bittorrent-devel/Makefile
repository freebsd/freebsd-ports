# New ports collection makefile for:	BitTorrent
# Date created:		Sun Mar 16 06:34:12 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	BitTorrent
PORTVERSION=	3.9.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES?=	net python
MASTER_SITES=	http://www.bittorrent.com/
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
#MASTER_SITE_SUBDIR=	${PORTNAME:L}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX?=	-devel
#DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(.)$/\1/}

MAINTAINER=	lioux@FreeBSD.org
COMMENT?=	A peer-to-peer tool for distributing files written in Python

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/dns/__init__.py:${PORTSDIR}/dns/py-dnspython

BROKEN=		Unfetchable

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_REINPLACE=	yes

CONFLICTS=	py??-*[Bb]it[Tt]orrent* py??-*[Bb]it[Tt]ornado* btqueue*

NO_LATEST_LINK=	yes

PORTDOCS=	\
		LICENSE.txt \
		README.txt \
		credits.txt \
		redirdonate.html

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

# required for GUI
.ifndef(WITHOUT_GUI)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/pygtk.py:${PORTSDIR}/x11-toolkits/py-gtk2

PLIST_FILES+=	\
		bin/btmaketorrentgui.py \
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
		-e 's|/usr/bin/env python|${LOCALBASE}/bin/python|'

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
