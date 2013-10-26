# Created by: Shin'ya Murakami <murakami@ahs.scitec.kobe-u.ac.jp>
# $FreeBSD$

PORTNAME=	dcl
PORTVERSION=	1.7.0
PORTREVISION=	1
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
		${LOCALBASE}/lib/libcdcl.so:${PORTSDIR}/science/cdcl
RUN_DEPENDS=	${LOCALBASE}/lib/libcdcl.so:${PORTSDIR}/science/cdcl \
		${RUBY_SITEARCHLIBDIR}/narray.so:${PORTSDIR}/math/ruby-narray \
		${RUBY_SITEARCHLIBDIR}/gdk_pixbuf2.so:${PORTSDIR}/graphics/ruby-gdk_pixbuf2 \
		${RUBY_SITEARCHLIBDIR}/gtk2.so:${PORTSDIR}/x11-toolkits/ruby-gtk2

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

DOCSDIR=	${RUBY_MODDOCDIR}
EXAMPLESDIR=	${RUBY_MODEXAMPLESDIR}

PORTDOCS=	ChangeLog README ToDo
PORTEXAMPLES=	*

NO_STAGE=	yes
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
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}
.endfor
.endif

.include <bsd.port.post.mk>
