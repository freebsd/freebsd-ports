# New ports collection makefile for:	Arkpandora TrueType fonts
# Date created:				17 Aug 2004
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	arkpandora
PORTVERSION=	2.04
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.users.bigpond.net.au/gavindi/
DISTNAME=	ttf-${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Arkpandora TrueType fonts

BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig \
		ttmkfdir:${PORTSDIR}/x11-fonts/ttmkfdir
RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USE_X_PREFIX=	yes

PLIST_SUB=	FONTSDIR="${FONTSDIR:S|${PREFIX}/||}"

MSG_FILE=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

#
# Local variables
#

FONTNAME=	${PORTNAME}
FONTSDIR?=	${PREFIX}/lib/X11/fonts/${FONTNAME}
TTMKFDIR_CMD?=	${X11BASE}/bin/ttmkfdir

.SILENT:

post-patch:
	${SED} 's|%%FONTSDIR%%|${FONTSDIR}|g' ${MSG_FILE} > ${PKGMESSAGE}

#
# Build
#

do-build: make-fonts.dir

make-fonts.dir:
	${TTMKFDIR_CMD} -c -d ${WRKSRC} -f Arkpandora | ${CAT} -n | ${SED} -e ' \
		s,^     1,100000,' | ${SORT} -r | ${CUT} -c 8- > ${WRKSRC}/fonts.dir

#
# Install
#

do-install: install-fonts install-fonts.dir install-conf

install-fonts:
	${MKDIR} ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT.TXT ${FONTSDIR}

install-fonts.dir:
	${INSTALL_DATA} ${WRKSRC}/fonts.dir ${FONTSDIR}
	${LN} -fs fonts.dir ${FONTSDIR}/fonts.scale

install-conf:
	${MKDIR} ${PREFIX}/etc/fonts
	if [ ! -f ${PREFIX}/etc/fonts/local.conf ]; then \
	    ${INSTALL_DATA} ${WRKSRC}/local.conf.arkpandora \
		${PREFIX}/etc/fonts/local.conf ; \
	fi
	${INSTALL_DATA} ${WRKSRC}/local.conf.arkpandora ${PREFIX}/etc/fonts

post-install:
	${ECHO_MSG} "===> Running fc-cache"
	-${X11BASE}/bin/fc-cache -f -v ${FONTSDIR}
	${ECHO_MSG}
	${CAT} ${PKGMESSAGE}
	${ECHO_MSG}

.include <bsd.port.mk>
