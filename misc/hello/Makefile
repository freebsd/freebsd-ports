# New ports collection makefile for:	hello
# Version required:			1.3
# Date created:				Fri Jul 23, 1999
# Whom:					shipley@dis.org
#
# $FreeBSD$
#

DISTNAME=	hello-1.3
PKGNAME=	hello-1.3.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	hello

MAINTAINER=	shipley@dis.org

WRKSRC=		${WRKDIR}/hello-1.3

GNU_CONFIGURE=	YES

post-install:
	@install-info --dir-file=${PREFIX}/info/dir \
	    --entry="* Hello: (hello).		Hello Reference Manual." \
	    ${PREFIX}/info/hello.info

.include <bsd.port.mk>
