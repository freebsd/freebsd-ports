# New ports collection makefile for:	wmlmmon
# Version required:			0.50
# Date created:				24 September 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

DISTNAME=	wmlmmon-0.50
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://www.fxp.org/~jedgar/

MAINTAINER=	jedgar@fxp.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes

MAN8=		wmlmmon.8
MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400000
pre-fetch:
	@${ECHO}
	@${ECHO} "This port uses the intpm controller which"
	@${ECHO} "is only available in FreeBSD 4.0-CURRENT."
	@${ECHO}
.endif

.include <bsd.port.mk>
