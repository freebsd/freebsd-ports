# New ports collection makefile for:	p5-type1inst
# Date created:		7 Jan 1998
# Whom:			giffunip@asme.org
#
# $FreeBSD$
#

PORTNAME=	p5-type1inst
PORTVERSION=	0.6.1
CATEGORIES=	x11-fonts perl5
MASTER_SITES=	$(MASTER_SITE_SUNSITE)
MASTER_SITE_SUBDIR=X11/xutils
DISTNAME=	type1inst-${PORTVERSION}

MAINTAINER=     giffunip@asme.org

RUN_DEPENDS=	$(X11BASE)/bin/mkfontdir:${PORTSDIR}/x11/XFree86

USE_PERL5=	yes
NO_BUILD=	yes
STRIP=

MANN=	type1inst.n

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/type1inst ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/t1embed ${PREFIX}/bin
	$(INSTALL_MAN) ${WRKSRC}/type1inst.man ${PREFIX}/man/mann/type1inst.n
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/README.type1inst
.endif

.include <bsd.port.mk>
