# New ports collection makefile for:	ruby-xmlscan
# Date created:		22 August 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	xslt
PORTVERSION=	0.8.1
CATEGORIES=	textproc ruby
MASTER_SITES=	http://gregoire.lejeune.free.fr/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}_${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	An XSLT processor in pure Ruby

USE_GNOME=	libxslt
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/ruby-${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_MODDOCDIR}
.endif

.include <bsd.port.mk>
