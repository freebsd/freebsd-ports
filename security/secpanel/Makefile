# New ports collection makefile for:	secpanel
# Date created:		11 June 2001
# Whom:			Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	secpanel
PORTVERSION=	0.6.1
PORTEPOCH=	1
CATEGORIES=	security tcl tk
MASTER_SITES=	SF/${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI for managing and running ssh and related utilities

RUN_DEPENDS=	ssh-askpass:${PORTSDIR}/security/openssh-askpass

WRKSRC=		${WRKDIR}/usr/local
NO_BUILD=	yes

USE_TK_WRAPPER=	yes

post-patch:
	@${REINPLACE_CMD} \
		-e 's!\[file dirname \[info script\]\]/../lib/secpanel!${DATADIR}!' \
			${WRKSRC}/bin/secpanel

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/secpanel ${PREFIX}/bin
	@(cd ${WRKSRC}/lib/secpanel && ${COPYTREE_SHARE} . ${DATADIR})
	@${CHMOD} u+rw ${DATADIR}/default.config

.include <bsd.port.mk>
