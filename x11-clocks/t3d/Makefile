# New ports collection makefile for:	t3d
# Date created:		20 Apr 1998
# Whom:			J Han <hjh@best.com>
#
# $FreeBSD$
#

PORTNAME=	t3d
PORTVERSION=	1.1
CATEGORIES=	x11-clocks
MASTER_SITES=	http://www.jwdt.com/~paysan/
DISTNAME=	t3d
EXTRACT_SUFX=	.shar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Clock using flying balls to display the time

EXTRACT_CMD=		${GZIP_CMD}
EXTRACT_BEFORE_ARGS=	-dc
EXTRACT_AFTER_ARGS=	| ${SH}

NO_WRKSUBDIR=	yes
USE_IMAKE=	yes

MAN1=		t3d.1
PLIST_FILES=	bin/t3d

.include <bsd.port.mk>
