# New ports collection makefile for:	su2
# Date created:		12 Sep 1996
# Whom:			gurney_j@efn.org
#
# $FreeBSD$
#

PORTNAME=	su2
PORTVERSION=	1.3
CATEGORIES=	sysutils security
MASTER_SITES=	ftp://ftp.ccs.neu.edu/pub/sysadmin/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An enhanced su, allows users to su with own password + more

NO_CDROM=	"Don't sell for profit"
USE_REINPLACE=	yes

MAN1=		su2.1
PLIST_FILES=	bin/su2

post-patch:
	${REINPLACE_CMD} -e 's,/etc/super,${PREFIX}/etc/super,g' ${WRKSRC}/su2.man

.include <bsd.port.mk>
