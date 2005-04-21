# New ports collection makefile for: viz
# Date created:                      8 Mar 1997
# Whom:                              Brent J. Nordquist <bjn@visi.com>
#
# $FreeBSD$
#

PORTNAME=	viz
PORTVERSION=	1.1.1
CATEGORIES=	misc
MASTER_SITES=		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	fenner
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert invisible (binary) characters to a visible form

MAKE_ARGS=	CC="${CC}" DEFS="${CFLAGS}"

MAN1=		viz.1 inviz.1
PLIST_FILES=	bin/viz bin/inviz

do-install:
		cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PLIST_FILES:T} ${PREFIX}/bin/
		cd ${WRKSRC} && ${INSTALL_MAN} ${MAN1} ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
