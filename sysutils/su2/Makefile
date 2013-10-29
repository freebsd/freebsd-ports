# Created by: gurney_j@efn.org
# $FreeBSD$

PORTNAME=	su2
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	sysutils security
MASTER_SITES=	ftp://ftp.ccs.neu.edu/pub/sysadmin/

MAINTAINER=	gd.workbox@gmail.com
COMMENT=	Enhanced su, allows users to su with own password + more

PATCH_DEPENDS=	rcsdiff:${PORTSDIR}/devel/rcs

NO_CDROM=	Don't sell for profit

PLIST_FILES=	bin/su2 \
		man/man1/su2.1.gz

post-patch:
	${REINPLACE_CMD} -e '/^CC=gcc/d' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's,/etc/super,${PREFIX}/etc/super,g' \
		${WRKSRC}/su2.man

.include <bsd.port.mk>
