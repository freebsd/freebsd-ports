# New ports collection makefile for:	dejagnu
# Version required:	1.3
# Date created:		12 October 1996
# Whom:			markm
#
# $Id: Makefile,v 1.6 1997/04/20 13:19:29 wosch Exp $
#

DISTNAME=	dejagnu-1.3
CATEGORIES=	misc tk80
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	markm@FreeBSD.ORG

RUN_DEPENDS=	expect:${PORTSDIR}/lang/expect

WRKSRC=		${WRKDIR}/${DISTNAME}/dejagnu
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	i386-freebsd
STRIP=
MAN1=		runtest.1

.include <bsd.port.mk>
