# New ports collection makefile for:	syncmal
# Date created:				March 17, 2001
# Whom:	      				fenner
#
# $FreeBSD$
#

PORTNAME=	syncmal
PORTVERSION=	0.71
PORTREVISION=	1
CATEGORIES=	palm
MASTER_SITES=	http://jasonday.home.att.net/code/syncmal/
DISTNAME=	jpilot-${PORTNAME}_${PORTVERSION}${EXTRACTSUFX}

MAINTAINER=	fenner@FreeBSD.Org
COMMENT=	A MAL plugin for jpilot, to synchronize with services like AvantGo

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/palm/jpilot:patch \
		${NONEXISTENT}:${PORTSDIR}/palm/malsync:patch
RUN_DEPENDS=	${PREFIX}/bin/jpilot:${PORTSDIR}/palm/jpilot

USE_GMAKE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ENV=	GTK_CONFIG=${X11BASE}/bin/gtk12-config
CONFIGURE_ARGS=	--with-plugin-prefix=${WRKDIR}/../../jpilot/work/jpilot-0.99.2 \
		--with-mal-source=${WRKDIR}/../../malsync/work/malsync

.include <bsd.port.mk>
