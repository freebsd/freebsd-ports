# Created by: Michael Gmelin <freebsd@grem.de>
# $FreeBSD$

PORTNAME=	bhyve-rc
PORTVERSION=	3
CATEGORIES=	sysutils
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	freebsd@grem.de
COMMENT=	FreeBSD RC script for starting bhyve guests in tmux

RUN_DEPENDS=	tmux:sysutils/tmux

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_INSTALL=	yes

USE_RC_SUBR=	bhyve

.include <bsd.port.mk>
