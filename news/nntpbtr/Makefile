# New ports collection makefile for:    nntpbtr
# Date created:         1 July 1996
# Whom:                 dk
#
# $FreeBSD$
#

PORTNAME=	nntpbtr
PORTVERSION=	1.7
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.kiarchive.ru/pub/unix/news/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	dk@farm.org
COMMENT=	NNTP bulk transfer

MAN1=		nntpbtr.1
PLIST_FILES=	sbin/nntpbtr

# "patch" complains otherwise
post-extract:
	@${RM} -rf ${WRKSRC}/RCS

pre-build:
	cd ${FILESDIR} ; ${PAX} -rw -l -u dbz ${WRKDIR} || ${TRUE}
	cd ${WRKDIR}/dbz ; ${CC} ${CFLAGS} -c -I. dbz.c

.include <bsd.port.mk>
