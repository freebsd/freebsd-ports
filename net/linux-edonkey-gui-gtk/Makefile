# New ports collection makefile for:	eDonkey2000 GTK GUI for 'core' client
# Date created:				Fri Jan 4 22:44:56 BRST 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	edonkey
PORTVERSION=	0.1.0
CATEGORIES=	net linux
MASTER_SITES=	http://www.edonkey2000.com/files/
DISTNAME=	ed2k_linux_gui_0.1alpha
PKGNAMESUFFIX=	-gui-gtk

MAINTAINER=	lioux@FreeBSD.org

RUN_DEPENDS=	donkey:${PORTSDIR}/net/edonkey-core \
		${LINUXBASE}/usr/lib/libgtk-1.2.so.0:${PORTSDIR}/x11-toolkits/linux-gtk

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
WRKSRC=		${WRKDIR}/linux_gui_alpha
NO_BUILD=	yes
STRIP=

STRIP_CMD=	${LINUXBASE}/usr/bin/strip

DATA_FILES=	gui_lookuplist gui_options

.if exists(/usr/bin/brandelf)
BRANDELF?=	/usr/bin/brandelf
.else
BRANDELF?=	brandelf
.endif

BINARY_NAME=	ed2k_gui

post-patch:
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|;s|%%DATADIR%%|${DATADIR}|; \
		s|%%DATAFILES%%|${DATA_FILES}|" \
		${FILESDIR}/wrapper.sh > ${WRKDIR}/wrapper.sh

pre-install:
.if exists(${STRIP_CMD})
	@${STRIP_CMD} ${WRKSRC}/${BINARY_NAME}
.endif
	@${BRANDELF} -t Linux ${WRKSRC}/${BINARY_NAME}

do-install:
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/todo.txt ${DOCSDIR}
.endif
	${MKDIR} ${DATADIR}
.for file in ${DATA_FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DATADIR}
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/${BINARY_NAME} ${PREFIX}/bin/${BINARY_NAME}-real
	${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${PREFIX}/bin/${BINARY_NAME}

.include <bsd.port.mk>
