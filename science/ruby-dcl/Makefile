# New ports collection makefile for:	RubyDCL
# Date created:		15 Febrary 2004
# Whom:			Shin'ya Murakami <murakami@ahs.scitec.kobe-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	dcl
PORTVERSION=	1.5.2
CATEGORIES=	science graphics ruby
MASTER_SITES=	http://www.gfd-dennou.org/arch/ruby/products/ruby-dcl/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}

MAINTAINER=	murakami@ahs.scitec.kobe-u.ac.jp
COMMENT=	A Ruby interface to the scientific graphic library DCL

BUILD_DEPENDS=	${RUBY_SITEARCHLIBDIR}/narray.so:${PORTSDIR}/math/ruby-narray
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/narray.so:${PORTSDIR}/math/ruby-narray

.if defined(WITHOUT_GTK)
.else
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/gdk_pixbuf2.so:${PORTSDIR}/graphics/ruby-gdk_pixbuf2 \
		${RUBY_SITEARCHLIBDIR}/gtk2.so:${PORTSDIR}/x11-toolkits/ruby-gtk2
BUILD_DEPENDS+=	${X11BASE}/lib/libcdcl53.a:${PORTSDIR}/science/cdcl
.endif

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

DOCS=		ChangeLog README ToDo
DEMODIRS=	gokuraku grph1 grph2 math2 rakuraku
DEMOGOKU=	hop jump layout step u1d u2d
DEMOGRPH1=	scpack sgpack slpack
DEMOGRPH2=	grpack g2pack ucpack udegpk ulpack umpack uspack uupack \
		uxyzpk ximage
DEMOMATH1=	gt2dlib
DEMOMATH2=	fftlib intrlib rnmlib vstlib
DEMORAKU=	color kihon layout map3d miss quick u2d uspack uxyz
DEMODAT=	grph1/scpack/t810630.dat grph1/scpack/t811231.dat \
		grph2/umpack/t811231.dat grph2/ximage/MEMO \
		grph2/ximage/tomsclm.dat

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=	Does not build on amd64 (Needs to link against shared libraries)
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${DEMODIRS}
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/${f}
.endfor
.for f in ${DEMOGOKU}
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/gokuraku/${f}
	${INSTALL_DATA} ${WRKSRC}/demo/gokuraku/${f}/*.rb ${RUBY_MODEXAMPLESDIR}/gokuraku/${f}
.endfor
.for f in ${DEMOGRPH1}
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/grph1/${f}
	${INSTALL_DATA} ${WRKSRC}/demo/grph1/${f}/*.rb ${RUBY_MODEXAMPLESDIR}/grph1/${f}
.endfor
.for f in ${DEMOGRPH2}
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/grph2/${f}
	${INSTALL_DATA} ${WRKSRC}/demo/grph2/${f}/*.rb ${RUBY_MODEXAMPLESDIR}/grph2/${f}
.endfor
.for f in ${DEMOMATH1}
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/math1/${f}
	${INSTALL_DATA} ${WRKSRC}/demo/math1/${f}/*.rb ${RUBY_MODEXAMPLESDIR}/math1/${f}
.endfor
.for f in ${DEMOMATH2}
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/math2/${f}
	${INSTALL_DATA} ${WRKSRC}/demo/math2/${f}/*.rb ${RUBY_MODEXAMPLESDIR}/math2/${f}
.endfor
.for f in ${DEMORAKU}
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/rakuraku/${f}
	${INSTALL_DATA} ${WRKSRC}/demo/rakuraku/${f}/*.rb ${RUBY_MODEXAMPLESDIR}/rakuraku/${f}
.endfor
.for f in ${DEMODAT}
	${INSTALL_DATA} ${WRKSRC}/demo/${f} ${RUBY_MODEXAMPLESDIR}/${f}
.endfor
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}
.endfor
.endif

.include <bsd.port.post.mk>
