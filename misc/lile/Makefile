# New ports collection makefile for:	ile
# Version required:	2.0
# Date created:		25 Jun 1997
# Whom:			jmz
#
# $Id: Makefile,v 1.2 1997/06/29 09:08:47 obrien Exp $
#

DISTNAME=	lile-2.0
PKGNAME=	ile-2.0
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.inria.fr/system/user/
EXTRACT_SUFX=	.tar.z

MAINTAINER=	jmz@FreeBSD.org

MAN1=		ile.1

do-configure:
	@(cd ${WRKSRC}; mv Makefile Makefile.old; \
	sed -e s:/usr/local:${PREFIX}: <Makefile.old > Makefile; \
	echo all: ile >> Makefile; echo CC=cc ${CFLAGS} >> Makefile)

.include <bsd.port.mk>
