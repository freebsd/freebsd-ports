# New ports collection makefile for:	shadow-BitTorrent
# Date created:		23 February 2004
# Whom:			Stefan Walter <sw@gegenunendlich.de>
#
# $FreeBSD$
#

PORTNAME=	shadow-BitTorrent
PORTVERSION=	5.8.11
CATEGORIES?=	net python
MASTER_SITES=	http://mediahost.inetsalestech.com/shadow/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	BitTorrent-experimental-S-${PORTVERSION}

MAINTAINER=	sw@gegenunendlich.de
COMMENT?=	Experimental BitTorrent client with enhanced features

CONFLICTS=	py??-BitTorrent-*
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/bittorrent-CVS-shadowsclient

DOC_FILES=	BUILD.windows.txt FAQ.txt IMPORTANT-multitracker-readme.txt \
		INSTALL.unix.txt LICENSE.txt README.txt \
		README-experimental.txt credits.txt multitracker-spec.txt \
		webseed-spec.txt

# required for GUI
.ifndef(WITHOUT_GUI)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/wxPython/__init__.py:${PORTSDIR}/x11-toolkits/py-wxPython
PLIST_SUB+=	GUI=''
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-nogui-patch-setup.py
PLIST_SUB+=	GUI='@comment '
.endif

.ifdef(WITH_PSYCO)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psyco/_psyco.so:${PORTSDIR}/devel/py-psyco
post-patch:
	@${REINPLACE_CMD} -e "s/^psyco = 0/psyco = 1/g" \
		${WRKSRC}/BitTorrent/PSYCO.py
.endif

pre-everything::
.ifndef(WITHOUT_GUI)
	@${ECHO_MSG} '===> Define WITHOUT_GUI to disable GUI installation'
.endif
.ifndef(WITH_PSYCO)
	@${ECHO_MSG} '===> Define WITH_PSYCO to enable the optimizing Python compiler'
.endif

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
