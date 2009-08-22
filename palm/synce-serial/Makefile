# New ports collection makefile for:   synce-serial
# Date created:                14 June 2003
# Whom:                        Sam Lawrance <boris@brooknet.com.au>
#
# $FreeBSD$

PORTNAME=	synce-serial
PORTVERSION=	0.11
CATEGORIES=	palm
MASTER_SITES=	SF/synce/SynCE/${PORTVERSION}

MAINTAINER=	avl@FreeBSD.org
COMMENT=	Wrapper for pppd to initiate communications with Windows Mobile devices

RUN_DEPENDS=	vdccm:${PORTSDIR}/palm/synce-vdccm

CONFLICTS=	synce-hal-[0-9]*

MAN8=		${PORTNAME}-config.8 ${PORTNAME}-start.8 \
		${PORTNAME}-abort.8 ${PORTNAME}-chat.8

GNU_CONFIGURE=	yes
USE_GNOME=	gnometarget

.include <bsd.port.mk>
