# New ports collection makefile for:	ruby-xmlscan
# Date created:		22 August 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	xslt
PORTVERSION=	0.9.6
CATEGORIES=	textproc ruby
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	ruby-asp
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	wenheping@gmail.com
COMMENT=	An XSLT processor in pure Ruby

USE_GNOME=	libxslt
USE_RUBY=	yes
USE_RUBY_SETUP=	yes

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_MODDOCDIR}
.endif

.include <bsd.port.mk>
