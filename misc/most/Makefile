# New ports collection makefile for:	most
# Version required:	4.7
# Date created:		31 May 1997
# Whom:			rhwang@bigpanda.com
#
# $Id$
#

DISTNAME=	most4.7
PKGNAME=	most-4.7
CATEGORIES=	misc	
MASTER_SITES=	ftp://space.mit.edu/pub/davis/most/ \
		ftp://ftp.uni-stuttgart.de/pub/unix/misc/slang/most/

MAINTAINER=	rhwang@bigpanda.com

LIB_DEPENDS=	slang\\.0\\.99[0-9][0-9]:${PORTSDIR}/devel/libslang

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/most
MAN1=		most.1

.include <bsd.port.mk>
