# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	byobu
PORTVERSION=	3.29
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://launchpadlibrarian.net/65243016/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	gslin@gslin.org
COMMENT=	Profile and configuration utilities for GNU Screen

RUN_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash \
		${LOCALBASE}/bin/screen:${PORTSDIR}/sysutils/screen

GNU_CONFIGURE=	yes
USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

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

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} \
		-e "s@/bin/bash@${LOCALBASE}/bin/bash@" \
		-e "s@/usr/bin/python@${PYTHON_CMD}@" \
		${WRKSRC}/usr/bin/*
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} \
		-e "s@^install:.*@install:@" \
		${WRKSRC}/usr/share/doc/byobu/Makefile.in
.endif

.include <bsd.port.mk>
