# New ports collection makefile for:	slirp
# Version required:	1.0c
# Date created:		25 Aug 1995
# Whom:			Alain Kalker <A.C.P.M.Kalker@student.utwente.nl>
#
# $Id: Makefile,v 1.9 1998/10/14 01:18:49 jseger Exp $
#

DISTNAME=	slirp-1.0c
CATEGORIES=	net
MASTER_SITES=	ftp://blitzen.canberra.edu.au/pub/slirp/

MAINTAINER=	A.C.P.M.Kalker@student.utwente.nl

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 300000
BROKEN=         tcp_subr.c
.endif

WRKSRC=		${WRKDIR}/slirp-1.0c/src
HAS_CONFIGURE=	yes
MAN1=		slirp.1

.include <bsd.port.post.mk>
