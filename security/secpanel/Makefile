# New ports collection makefile for:	secpanel
# Date created:		11 June 2001
# Whom:			Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	secpanel
PORTVERSION=	0.5.4
PORTEPOCH=	1
CATEGORIES=	security tcl tk
MASTER_SITES=	http://themediahost.de/secpanel/data/ CENKES
EXTRACT_SUFX=	.tgz

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	GUI for managing and running ssh and related utilities

RUN_DEPENDS=	ssh-askpass:${PORTSDIR}/security/openssh-askpass

USE_TK_RUN=	84
NO_BUILD=	yes

post-extract:
	@${MV} ${WRKDIR}/usr ${WRKSRC}
	@${CHMOD} -R a+rX ${WRKSRC}/
	@${RM} -rf ${WRKSRC}/local/lib/secpanel/out/

post-patch:
	@${REINPLACE_CMD} -e 's!^exec wish!exec ${WISH}!' \
		-e 's!\[file dirname \[info script\]\]/../lib/secpanel!${DATADIR}!' \
		-e 's!askpassbin askpass!askpassbin ssh-askpass!' \
			${WRKSRC}/local/bin/secpanel

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/local/bin/secpanel ${PREFIX}/bin/
	@cd ${WRKSRC}/local/lib/secpanel/&&${COPYTREE_SHARE} . ${DATADIR}/

.include <bsd.port.mk>
