# New ports collection makefile for:	p5-type1inst
# Date created:		7 Jan 1998
# Whom:			giffunip@asme.org
#
# $FreeBSD$
#

PORTNAME=	type1inst
PORTVERSION=	0.6.1
PORTREVISION=	2
CATEGORIES=	x11-fonts perl5
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=X11/xutils
PKGNAMEPREFIX=	p5-

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A script that helps install Postscript fonts in X Window System

RUN_DEPENDS=	mkfontdir:${X_CLIENTS_PORT}

USE_PERL5=	yes
USE_XLIB=	yes
NO_BUILD=	yes

MAN1=	type1inst.1

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/type1inst ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/t1embed ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/type1inst.man ${PREFIX}/man/man1/type1inst.1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README.type1inst
.endif

.include <bsd.port.mk>
