# Created by: Pete Fritchman <petef@databits.net>
# $FreeBSD$

PORTNAME=	secpanel
PORTVERSION=	0.6.1
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	security tcl tk
MASTER_SITES=	SF/${PORTNAME} \
		SF/nemysisfreebsdp/security/:icons
DISTFILES=	${DISTNAME}.tgz \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}.tgz

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	GUI for managing and running ssh and related utilities

LICENSE=	GPLv2

RUN_DEPENDS=	ssh-askpass:security/openssh-askpass

WRKSRC=		${WRKDIR}/usr/local
NO_BUILD=	yes

USES=		tk:wrapper

DESKTOP_ENTRIES="SecPanel" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "" "false"

post-patch:
	@${REINPLACE_CMD} \
		-e 's|\[file dirname \[info script\]\]/../lib/secpanel|${DATADIR}|' \
			${WRKSRC}/bin/secpanel

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@(cd ${WRKSRC}/lib/secpanel && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	@${CHMOD} u+rw ${STAGEDIR}${DATADIR}/default.config

	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
