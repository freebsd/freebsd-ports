# New ports collection makefile for:	ile
# Version required:	1.6
# Date created:		25 Jun 1997
# Whom:			jmz
#
# $Id: Makefile,v 1.1.1.1 1997/06/28 00:54:46 jmz Exp $
#

DISTNAME=	lile
PKGNAME=	ile-1.6
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.inria.fr/system/user/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jmz@FreeBSD.org

MAN1=		ile.1

do-configure:
	@(cd ${WRKSRC}; mv Makefile Makefile.old; \
	sed -e s:/usr/local:${PREFIX}: <Makefile.old > Makefile; \
	echo all: ile >> Makefile)

.include <bsd.port.mk>
