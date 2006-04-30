# New ports collection makefile for:	secpanel
# Date created:				11 June 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	secpanel
PORTVERSION=	0.5.1
PORTEPOCH=	1
CATEGORIES=	security tcl84 tk84
MASTER_SITES=	http://www.pingx.net/secpanel/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI for managing and running ssh and related utilities

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84 \
		ssh-askpass:${PORTSDIR}/security/openssh-askpass

USE_X_PREFIX=	yes

NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e 's!^exec wish!exec wish8.4!' \
		-e 's!\[file dirname \[info script\]\]/../lib/secpanel!${DATADIR}!' \
		-e 's!askpassbin askpass!askpassbin ssh-askpass!' ${WRKSRC}/src/bin/secpanel

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/bin/secpanel ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
.for file in convert_history.tcl default.config default.profile \
	gui.tcl listserver.tcl secpanel.dist secpanel.wait
	${INSTALL_SCRIPT} ${WRKSRC}/src/lib/secpanel/${file} ${DATADIR}
.endfor
	@${MKDIR} ${DATADIR}/images
	${INSTALL_DATA} ${WRKSRC}/src/lib/secpanel/images/*.gif \
		${DATADIR}/images

.include <bsd.port.mk>
