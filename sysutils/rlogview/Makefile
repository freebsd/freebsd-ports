# New ports collection makefile for:	rlogview
# Date created:		15 July 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rlogview
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	sysutils ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby/GTK graphical log viewer for log4r

RUN_DEPENDS=	${RUBY_SITELIBDIR}/log4r.rb:${PORTSDIR}/sysutils/ruby-log4r \
		${RUBY_SITEARCHLIBDIR}/gtk.so:${PORTSDIR}/x11-toolkits/ruby-gtk \
		${RUBY_SITEARCHLIBDIR}/lglade.so:${PORTSDIR}/devel/ruby-libglade

USE_RUBY=	yes
USE_RUBY_FEATURES=	drb

NO_BUILD=	yes

DOCS=		Changelog README

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb --install-dir="${PREFIX}"
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
