# New ports collection makefile for:	most
# Version required:	4.8.1
# Date created:		31 May 1997
# Whom:			rhwang@bigpanda.com
#
# $Id: Makefile,v 1.3 1998/05/17 22:55:15 mph Exp $
#

DISTNAME=	most4.8.1
PKGNAME=	most-4.8.1
CATEGORIES=	misc	
MASTER_SITES=	ftp://space.mit.edu/pub/davis/most/ \
		ftp://ftp.uni-stuttgart.de/pub/unix/misc/slang/most/

MAINTAINER=	rhwang@bigpanda.com

LIB_DEPENDS=	slang.1:${PORTSDIR}/devel/libslang

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/most
MAN1=		most.1

.include <bsd.port.mk>
