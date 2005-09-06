# New ports collection makefile for:	viewglob
# Date created:			06 Oct 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	viewglob
PORTVERSION=	2.0.3
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A GTK+ add-on to bash and zsh

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_X_PREFIX=	yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes

MAN1=		vgd.1 vgseer.1 viewglob.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	does not compile on FreeBSD 4.x, it's missing posix_openpt and ptsname functions
.endif

.include <bsd.port.post.mk>
