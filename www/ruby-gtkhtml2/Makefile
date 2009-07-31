# New ports collection makefile for:	Ruby/GtkHtml2
# Date created:				05 April 2004
# Whom:					Mezz <mezz7@cox.net>
#
# $FreeBSD$
#   $MCom: ports/www/ruby-gtkhtml2/Makefile,v 1.2 2005/10/17 07:05:42 mezz Exp $
#

PORTNAME=	gtkhtml2
PORTVERSION=	${RUBY_GNOME_PORTVERSION}
PORTREVISION=	1
CATEGORIES=	www gnome ruby
MASTER_SITES=	${RUBY_GNOME_MASTER_SITES}
MASTER_SITE_SUBDIR=	${RUBY_GNOME_MASTER_SITE_SUBDIR}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_GNOME_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding for GtkHtml2

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR:S/${PREFIX}/${LOCALBASE}/}/gtk2.so:${PORTSDIR}/x11-toolkits/ruby-gtk2

USE_RUBY=	yes
USE_GNOME=	libgtkhtml
USE_RUBY_EXTCONF=	yes

.include "${.CURDIR}/../../x11/ruby-gnome2/Makefile.common"

WRKSRC=		${RUBY_GNOME_WRKSRC}/gtkhtml2
INSTALL_TARGET=	site-install

DOCS=		COPYING.LIB ChangeLog README

post-patch: general-patch

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${RUBY_MODEXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_MODEXAMPLESDIR}/
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
