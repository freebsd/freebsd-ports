# New ports collection makefile for:	wmlmmon
# Version required:			0.52
# Date created:				24 September 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

DISTNAME=	wmlmmon-0.52
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://www.fxp.org/~jedgar/

MAINTAINER=	jedgar@fxp.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes

MAN8=		wmlmmon.8
MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400000
BROKEN="This port uses the intpm controller which is only available in FreeBSD 4.0+"
.endif

.include <bsd.port.post.mk>
