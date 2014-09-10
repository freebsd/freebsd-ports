# Created by: Shin'ya Murakami <murakami@ahs.scitec.kobe-u.ac.jp>
# $FreeBSD$

PORTNAME=	dcl
PORTVERSION=	1.7.0
PORTREVISION=	4
CATEGORIES=	science graphics ruby
MASTER_SITES=	http://ruby.gfd-dennou.org/products/ruby-dcl/release/ \
		http://dennou-h.gfd-dennou.org/library/ruby/products/ruby-dcl/release/ \
		http://dennou-q.gfd-dennou.org/library/ruby/products/ruby-dcl/release/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}

MAINTAINER=	murashin@gfd-dennou.org
COMMENT=	Ruby interface to the scientific graphic library DCL

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	rubygem-narray>=0.5.5:${PORTSDIR}/math/rubygem-narray \
		${LOCALBASE}/lib/libcdcl.so:${PORTSDIR}/science/cdcl
RUN_DEPENDS=	${LOCALBASE}/lib/libcdcl.so:${PORTSDIR}/science/cdcl \
		rubygem-narray>=0.5.5:${PORTSDIR}/math/rubygem-narray \
		rubygem-gdk_pixbuf2>=2.1.0:${PORTSDIR}/graphics/rubygem-gdk_pixbuf2 \
		rubygem-gtk2>=2.1.0:${PORTSDIR}/x11-toolkits/rubygem-gtk2

USE_GCC=	yes
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
RUBY_NARRAY_PKGNAME=	narray-${NARRAY_VERSION}
CONFIGURE_ARGS+=	--with-narray-include=${LOCALBASE}/lib/ruby/gems/${RUBY_VER}/gems/${RUBY_NARRAY_PKGNAME}/
MAKE_ARGS=	INSTALL_PROG="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_DATA}"

DOCSDIR=	${RUBY_MODDOCDIR}
EXAMPLESDIR=	${RUBY_MODEXAMPLESDIR}

PORTDOCS=	ChangeLog README ToDo
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

DEPRECATED=	Depends on deprecated math/ruby-narray
EXPIRATION_DATE=	2014-09-20

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=	Does not build on ${ARCH} (Needs to link against shared libraries)
.endif

post-configure:
	@${REINPLACE_CMD} -e 's|CC = cc|CC = `${LOCALBASE}/bin/cdclconfig --cc`|g' ${WRKSRC}/Makefile

.include "${.CURDIR}/../../math/rubygem-narray/Makefile.version"

post-install:
	${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}
	(cd ${WRKSRC}/demo/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${RUBY_MODEXAMPLESDIR})
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}
.endfor

.include <bsd.port.post.mk>
