# Created by: Pieter Danhieux <opr@bsdaemon.be>
# $FreeBSD$

PORTNAME=	autopsy
PORTVERSION=	2.24
PORTREVISION=	1
CATEGORIES=	sysutils security
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web-based (graphical) interface to The Sleuth Kit

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/bin/ifind:${PORTSDIR}/sysutils/sleuthkit
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
IS_INTERACTIVE=	yes
WEB=		pict/*
WEBHELP=	help/*
PERLBITS=	lib/*.pm lib/*.pl conf.pl
MAN1=		autopsy.1

pre-configure:
	@${REINPLACE_CMD} -e 's,lib/,,' ${WRKSRC}/base/autopsy.base

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/autopsy ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib/autopsy
	cd ${WRKSRC} && ${INSTALL_DATA} ${PERLBITS} ${PREFIX}/lib/autopsy
	cd ${WRKSRC}/man/man1 && ${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1
	@${MKDIR} ${PREFIX}/share/autopsy/pict
	@${MKDIR} ${PREFIX}/share/autopsy/help
	cd ${WRKSRC} && ${INSTALL_DATA} ${WEB} ${PREFIX}/share/autopsy/pict
	cd ${WRKSRC} && ${INSTALL_DATA} ${WEBHELP} ${PREFIX}/share/autopsy/help

.include <bsd.port.mk>
