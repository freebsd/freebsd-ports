# New ports collection makefile for:   autopsy
# Date created:         2003-08-12
# Whom:                 Pieter Danhieux <opr@bsdaemon.be>
#
# $FreeBSD$
#

PORTNAME=	autopsy
PORTVERSION=	1.73
CATEGORIES=	sysutils security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	opr@bsdaemon.be
COMMENT=	The Autopsy Forensic Browser is a GUI for Sleuthkit

#
# It should have a BUILD_DEPENDS on something in sysutils/sleuthkit,
# but I'm not sure which what to do it on.
#
BUILD_DEPENDS=	${LOCALBASE}/bin/ifind:${PORTSDIR}/sysutils/sleuthkit

USE_PERL5=	yes
IS_INTERACTIVE=	yes
WEB=		pict/*
WEBHELP=	help/*
MAN1=		autopsy.1

do-configure:
	@echo "Note: use ${LOCALBASE}/ as your Sleuth Kit install directory!"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/autopsy ${PREFIX}/bin
	cd ${WRKSRC}/man/man1 && ${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/autopsy
	${MKDIR} ${PREFIX}/share/autopsy/pict
	${MKDIR} ${PREFIX}/share/autopsy/help
	cd ${WRKSRC} && ${INSTALL_DATA} ${WEB} ${PREFIX}/share/autopsy/pict
	cd ${WRKSRC} && ${INSTALL_DATA} ${WEBHELP} ${PREFIX}/share/autopsy/help
.include <bsd.port.mk>
