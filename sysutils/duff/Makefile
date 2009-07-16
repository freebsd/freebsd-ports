# New ports collection makefile for:	duff
# Date created:				2009-06-10
# Whom:					Jason E. Hale <bsdkaffee@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	duff
PORTVERSION=	0.4
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	Duplicate file finder

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		duff.1
PLIST_FILES=	bin/duff \
		share/duff/join-duplicates.sh
PLIST_DIRS=	share/duff

post-patch:
	${CHMOD} +x ${WRKSRC}/install-sh

.include <bsd.port.mk>
