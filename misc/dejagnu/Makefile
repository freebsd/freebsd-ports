# New ports collection makefile for:	dejagnu
# Version required:	1.3
# Date created:		12 October 1996
# Whom:			markm
#
# $Id: Makefile,v 1.4 1996/11/17 09:05:37 obrien Exp $
#

DISTNAME=	dejagnu-1.3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	markm@FreeBSD.ORG

RUN_DEPENDS=	expect:${PORTSDIR}/lang/expect

WRKSRC=		${WRKDIR}/${DISTNAME}/dejagnu
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	i386-freebsd
STRIP=
MAN1=		runtest.1

.include <bsd.port.mk>
