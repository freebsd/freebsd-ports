# New ports collection makefile for:	byobu
# Date created:		2011-04-09
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	byobu
PORTVERSION=	3.29
CATEGORIES=	sysutils
MASTER_SITES=	http://launchpadlibrarian.net/65243016/
DISTFILES=	${PORTNAME}_${PORTVERSION}.orig${EXTRACT_SUFX}

MAINTAINER=	gslin@gslin.org
COMMENT=	Profile and configuration utilities for GNU Screen

RUN_DEPENDS=	${LOCALBASE}/bin/screen:${PORTSDIR}/sysutils/screen

GNU_CONFIGURE=	yes

MAN1=		byobu-config.1 \
		byobu-disable.1 \
		byobu-enable.1 \
		byobu-export.1 \
		byobu-janitor.1 \
		byobu-launch.1 \
		byobu-launcher-install.1 \
		byobu-launcher-uninstall.1 \
		byobu-launcher.1 \
		byobu-reconnect-sockets.1 \
		byobu-select-profile.1 \
		byobu-select-session.1 \
		byobu-status-detail.1 \
		byobu-status.1 \
		byobu.1 \
		shell.1

.include <bsd.port.mk>
