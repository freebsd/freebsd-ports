# New ports collection makefile for:	lmmon
# Version required:			0.52
# Date created:				24 September 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

DISTNAME=	lmmon-0.52
CATEGORIES=	sysutils
MASTER_SITES=	http://www.fxp.org/~jedgar/

MAINTAINER=	jedgar@fxp.org

MAN8=		lmmon.8
MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400000
FORBIDDEN=	"This port uses the intpm controller which is only available in FreeBSD 4.0+"
.endif

.include <bsd.port.post.mk>
