# New ports collection makefile for:	libgdome-ruby
# Date created:		12 July 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gdome
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	textproc ruby
MASTER_SITES=	http://download.berlios.de/libgdome-ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	lib${PORTNAME}-ruby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby extension that wraps around gdome2

LIB_DEPENDS=	gdome.8:${PORTSDIR}/textproc/gdome2

USE_BZIP2=	yes

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

post-extract:
	${RM} -rf ${WRKSRC}/examples-ruby/CVS

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples-ruby/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_MODDOCDIR}/
.endif

.include <bsd.port.mk>
