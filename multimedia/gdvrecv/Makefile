# New ports collection makefile for:   gdvrecv
# Date created:                        01 Nov 2004
# Whom:                                Henri Michelon <hmichelon at e-cml.org>
#
# $FreeBSD$
#

PORTNAME=	gdvrecv
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=gdvrecv

MAINTAINER=	hmichelon@e-cml.org
COMMENT=	DV Tools for FreeBSD

USE_BZIP2=	yes
USE_GNOME=	pygtk2
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 502000
IGNORE=		does not work on FreeBSD older than 5.2
.endif

.include <bsd.port.post.mk>
