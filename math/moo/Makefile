# New ports collection makefile for:	moo
# Date created:				05 Apr 2007
# Whom:					Steven Kreuzer <skreuzer@f2o.org>
#
# $FreeBSD$
#

PORTNAME=	moo
PORTVERSION=	1.3
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_OPENBSD}
MASTER_SITE_SUBDIR=	distfiles
EXTRACT_SUFX=	.tgz

MAINTAINER=	skreuzer@exit2shell.com
COMMENT=	Calculator that accepts C-like syntax as input

PLIST_FILES=	bin/moo
MAN1=		moo.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/moo ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/moo.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
