# Created by: Michael Gmelin <freebsd@grem.de>
# $FreeBSD$

PORTNAME=	bhyve-rc
PORTVERSION=	1
CATEGORIES=	sysutils
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	freebsd@grem.de
COMMENT=	FreeBSD RC script for starting bhyve guests in tmux

RUN_DEPENDS=	tmux:${PORTSDIR}/sysutils/tmux

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

USE_RC_SUBR=	bhyve

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000
IGNORE=	bhyve first appeared in FreeBSD 10.0
.endif

do-fetch do-install:
	@${DO_NADA}

.include <bsd.port.post.mk>
