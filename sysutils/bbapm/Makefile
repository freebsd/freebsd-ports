# New ports collection makefile for:	bbapm
# Date created:				3 August 2001
# Whom:				Adam Weinberger <monkey@crackula.com>
#
# $FreeBSD$
#

PORTNAME=	bbapm
PORTVERSION=	0.0.1
CATEGORIES=	x11-wm
MASTER_SITES=	http://bbtools.windsofstorm.net/sources/

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	bbapm-0.0.1-freebsd-patch-2.diff
PATCH_DIST_STRIP=	-p1

MAINTAINER=	monkey@crackula.com

RUN_DEPENDS=	blackbox:${PORTSDIR}/x11-wm/blackbox

USE_X_PREFIX=	yes
USE_GTK=	yes
GNU_CONFIGURE=	yes

do-install:
	@${INSTALL} ${COPY} ${STRIP} -o ${BINOWN} -g operator \
		-m 2555 ${WRKSRC}/bbapm ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/bbtools
.for a in README.bbapm bbapm.conf bbapm.nobb bbapm.style bbtoolsrc.in
	@${INSTALL_DATA} ${WRKSRC}/data/${a} ${PREFIX}/share/bbtools
.endfor

.include <bsd.port.mk>
