# New ports collection makefile for:	RubyNetCDF
# Date created:		11 June 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	netcdf
PORTVERSION=	0.3.5
CATEGORIES=	math ruby
MASTER_SITES=	http://ruby.gfd-dennou.org/products/ruby-netcdf/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	netcdf.1:${PORTSDIR}/math/netcdf
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/narray.so:${PORTSDIR}/math/ruby-narray

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

DOCS=		ChangeLog ToDo doc/*

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/demo/* ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.endif

.include <bsd.port.mk>
