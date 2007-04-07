# New ports collection makefile for:	secpanel
# Date created:				11 June 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	secpanel
PORTVERSION=	0.5.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	security tcl84 tk84
MASTER_SITES=	CENKES
# Now officially available from:
# http://secpanel.mymediahost.de/files/u1/secpanel-0_5_1.tgz

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	GUI for managing and running ssh and related utilities

RUN_DEPENDS=	ssh-askpass:${PORTSDIR}/security/openssh-askpass

USE_TK_RUN=	84
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e 's!^exec wish!exec ${WISH}!' \
		-e 's!\[file dirname \[info script\]\]/../lib/secpanel!${DATADIR}!' \
		-e 's!askpassbin askpass!askpassbin ssh-askpass!' \
		${WRKSRC}/src/bin/secpanel

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/bin/secpanel ${PREFIX}/bin/
	@${INSTALL} -d ${DATADIR}/
	@${CP} -Rp ${WRKSRC}/src/lib/secpanel/ ${DATADIR}/
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}/
	@${CHMOD} -R ${SHAREMODE} ${DATADIR}/

.include <bsd.port.mk>
