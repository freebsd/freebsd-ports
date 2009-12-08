# New ports collection makefile for:	pslist
# Date created:				27 October 2000
# Whom:					roam@orbitel.bg
#
# $FreeBSD$
#

PORTNAME=	pslist
PORTVERSION=	1.3
CATEGORIES=	sysutils
MASTER_SITES=	http://devel.ringlet.net/sysutils/pslist/

MAINTAINER=	roam@FreeBSD.org
COMMENT=	A utility to view or send signals to processes with all their children

USE_PERL5_RUN=	yes

MAN1=		pslist.1
MLINKS=		pslist.1 rkill.1 pslist.1 rrenice.1
PLIST_FILES=	bin/pslist \
		bin/rkill \
		bin/rrenice

.include <bsd.port.mk>
