# New ports collection makefile for:	shadow-BitTorrent
# Date created:		23 February 2004
# Whom:			Stefan Walter <sw@gegenunendlich.de>
#
# $FreeBSD$
#

PORTNAME=	BitTornado
PORTVERSION=	0.3.1
PORTEPOCH=	1
CATEGORIES?=	net python ipv6
MASTER_SITES=	http://e.scarywater.net/bt/download/ \
		http://mediahost.inetsalestech.com/shadow/ \
		http://www.hypermax.net.au/~gamr/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT?=	An extended BitTorrent peer-to-peer tool for distributing files

CONFLICTS=	py??-*[Bb]it[Tt]ornado* py??-*[Bb]it[Tt]orrent* btqueue*
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-CVS

DOC_FILES=	BUILD.windows.txt FAQ.txt IMPORTANT-multitracker-readme.txt \
		INSTALL.unix.txt LICENSE.txt README.txt \
		README-experimental.txt credits.txt multitracker-spec.txt \
		README-Psyco.txt todo.txt webseed-spec.txt
EXTRA_DOC_FILES=	multitracker/README.txt

# required for GUI
.ifndef(WITHOUT_GUI)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/wxPython/__init__.py:${PORTSDIR}/x11-toolkits/py-wxPython
PLIST_SUB+=	GUI=''
EXTRA_PATCHES+=	${FILESDIR}/extra-gui-patch-setup.py
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-nogui-patch-setup.py
PLIST_SUB+=	GUI='@comment '
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

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.for file in ${EXTRA_DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}/`${ECHO} ${file} | ${SED} -e 's|/|_|g'`
.endfor
.endif

.include <bsd.port.mk>
