# New ports collection makefile for:	rlogview
# Date created:		15 July 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rlogview
PORTVERSION=	0.3
CATEGORIES=	sysutils ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	${RUBY_SITELIBDIR}/log4r.rb:${PORTSDIR}/sysutils/ruby-log4r \
		${RUBY_SITEARCHLIBDIR}/gtk.so:${PORTSDIR}/x11-toolkits/ruby-gtk \
		${RUBY_SITEARCHLIBDIR}/lglade.so:${PORTSDIR}/devel/ruby-libglade \
		${RUBY_SITELIBDIR}/drb.rb:${PORTSDIR}/net/ruby-drb
# ROMP is the alternative method to DRb.
#		${RUBY_SITELIBDIR}/romp.rb:${PORTSDIR}/net/ruby-romp

USE_RUBY=	yes

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
