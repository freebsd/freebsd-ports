# New ports collection makefile for:	gave
# Date created:		14 March 2004
# Whom:			Shin'ya Murakami <murakami@ahs.scitec.kobe-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	gave
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	science graphics ruby
MASTER_SITES=	http://ruby.gfd-dennou.org/products/gave/
DIST_SUBDIR=	ruby

MAINTAINER=	murakami@ahs.scitec.kobe-u.ac.jp
COMMENT=	A gtk+ based grid data analyser and viewer written in Ruby

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/narray.so:${PORTSDIR}/math/ruby-narray \
		${RUBY_SITEARCHLIBDIR}/numru/dcl_raw.so:${PORTSDIR}/science/ruby-dcl-gtk \
		${RUBY_SITEARCHLIBDIR}/numru/netcdfraw.so:${PORTSDIR}/math/ruby-netcdf \
		${RUBY_SITELIBDIR}/numru/gphys.rb:${PORTSDIR}/science/ruby-gphys \
		${RUBY_SITEARCHLIBDIR}/libglade2.so:${PORTSDIR}/devel/ruby-libglade2 \
		${RUBY_SITEARCHLIBDIR}/gnomevfs.so:${PORTSDIR}/devel/ruby-gnomevfs

USE_RUBY=	yes
NO_BUILD=	yes

.if !defined(WITHOUT_GETTEXT)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/gettext/_locale.so:${PORTSDIR}/devel/ruby-gettext
.endif

do-install:
	@cd ${WRKSRC}/ && ${RUBY} ./install.rb --localedir=${PREFIX}/share/locale/

.include <bsd.port.mk>
