# New ports collection makefile for:	gave
# Date created:		14 March 2004
# Whom:			Shin'ya Murakami <murakami@ahs.scitec.kobe-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	gave
PORTVERSION=	1.0.3
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
		${RUBY_SITEARCHLIBDIR}/gnome2.so:${PORTSDIR}/x11/ruby-gnome2 \
		${RUBY_SITEARCHLIBDIR}/gnomevfs.so:${PORTSDIR}/devel/ruby-gnomevfs

USE_RUBY=	yes
NO_BUILD=	yes
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/gettext/_locale.so:${PORTSDIR}/devel/ruby-gettext
.if ${RUBY_VER} >= 1.7
RUN_DEPENDS+=	${RUBY_ARCHLIBDIR}/iconv.so:${PORTSDIR}/converters/ruby-iconv
.else
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/iconv.so:${PORTSDIR}/converters/ruby-iconv
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/sitelibdir\+\"\/numru\/\"\+package/sitelibdir\+\"\/\"\+package/' ${WRKSRC}/install.rb

do-install:
	@cd ${WRKSRC}/ && ${RUBY} ./install.rb --localedir=${PREFIX}/share/locale/

.include <bsd.port.post.mk>
