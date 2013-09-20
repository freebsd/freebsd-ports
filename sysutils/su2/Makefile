# Created by: gurney_j@efn.org
# $FreeBSD$

PORTNAME=	su2
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	sysutils security
MASTER_SITES=	ftp://ftp.ccs.neu.edu/pub/sysadmin/

MAINTAINER=	gd@rambler-co.ru
COMMENT=	An enhanced su, allows users to su with own password + more

NO_CDROM=	Don't sell for profit

MAN1=		su2.1
PLIST_FILES=	bin/su2

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e '/^CC=gcc/d' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's,/etc/super,${PREFIX}/etc/super,g' \
		${WRKSRC}/su2.man

.include <bsd.port.mk>
