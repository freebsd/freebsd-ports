# New ports collection makefile for:	p5-type1inst
# Date created:		7 Jan 1998
# Whom:			giffunip@asme.org
#
# $FreeBSD$
#

PORTNAME=	type1inst
PORTVERSION=	0.6.1
PORTREVISON=	1
CATEGORIES=	x11-fonts perl5
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=X11/xutils
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A script that helps install Postscript fonts in X Window System

USE_PERL5=	yes
USE_XLIB=	yes
NO_BUILD=	yes

MAN1=	type1inst.1

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/type1inst ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/t1embed ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/type1inst.man ${PREFIX}/man/man1/type1inst.1
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/README.type1inst
.endif

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 4
RUN_DEPENDS+=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
.endif

.include <bsd.port.post.mk>
