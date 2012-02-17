# New ports collection makefile for:	RubyDCL
# Date created:		15 Febrary 2004
# Whom:			Shin'ya Murakami <murakami@ahs.scitec.kobe-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	dcl
PORTVERSION=	1.6.3
CATEGORIES=	science graphics ruby
MASTER_SITES=	http://ruby.gfd-dennou.org/products/ruby-dcl/release/ \
		http://dennou-h.gfd-dennou.org/library/ruby/products/ruby-dcl/release/ \
		http://dennou-q.gfd-dennou.org/library/ruby/products/ruby-dcl/release/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}

MAINTAINER=	murashin@gfd-dennou.org
COMMENT=	A Ruby interface to the scientific graphic library DCL

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${RUBY_SITEARCHLIBDIR}/narray.so:${PORTSDIR}/math/ruby-narray \
		${LOCALBASE}/lib/libcdcl.a:${PORTSDIR}/science/cdcl
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/narray.so:${PORTSDIR}/math/ruby-narray

.if defined(WITHOUT_GTK)
.else
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/gdk_pixbuf2.so:${PORTSDIR}/graphics/ruby-gdk_pixbuf2 \
		${RUBY_SITEARCHLIBDIR}/gtk2.so:${PORTSDIR}/x11-toolkits/ruby-gtk2
.endif

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

DOCS=		ChangeLog LICENSE.txt README ToDo

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=	Does not build on ${ARCH} (Needs to link against shared libraries)
.endif

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	(cd ${WRKSRC}/demo/ && ${COPYTREE_SHARE} \* ${RUBY_MODEXAMPLESDIR})
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}
.endfor
.endif

.include <bsd.port.post.mk>
