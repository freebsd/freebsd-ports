# New ports collection makefile for:	wml
# Date created:		09-Sep-1997
# Whom:			Ralf S. Engelschall <rse@engelschall.com>
#
# $FreeBSD$
#

PORTNAME=	wml
PORTVERSION=	2.0.9
CATEGORIES=	www lang
MASTER_SITES=	http://thewml.org/distrib/ \
		ftp://thewml.org/distrib/

MAINTAINER=	delta@lackas.net
COMMENT=	Website META Language, webdesign toolkit for HTML generation

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-perl=${PERL5}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_LIBTOOL_VER=	15
LIBTOOLFILES=	wml_backend/p2_mp4h/configure
PLIST_SUB+=	ARCH=${LOCAL_PERL_ARCH}

CAT1=	wml_aux_txt2html.1 wml_aux_tidy.1 wml_p4_gm4.1

MAN1=	wmd.1 wmd_missing.1 wmk.1 wml.1 wmb.1 wmu.1 \
	wml_aux_freetable.1 wml_aux_htmlclean.1 wml_aux_htmlinfo.1 wml_aux_iselect.1 \
	wml_aux_map2html.1 wml_aux_weblint.1 wml_p1_ipp.1 \
	wml_p2_mp4h.1 wml_p3_eperl.1 wml_p5_divert.1 wml_p6_asubst.1 \
	wml_p7_htmlfix.1 wml_p8_htmlstrip.1 wml_p9_slice.1 wml_aux_linklint.1

MAN3=	wml::all.3 wml::des::all.3 wml::des::gfont.3 \
	wml::des::lowsrc.3 wml::des::imgdot.3 wml::des::imgbg.3 \
	wml::des::navbar.3 wml::des::preload.3 wml::des::rollover.3 \
	wml::des::space.3 wml::des::typography.3 wml::fmt::all.3 \
	wml::fmt::isolatin.3 wml::fmt::pod.3 wml::fmt::sdf.3 \
	wml::fmt::text.3 wml::fmt::url.3 wml::fmt::verbatim.3 \
	wml::fmt::xtable.3 wml::imp::all.3 wml::imp::csmap.3 \
	wml::imp::fsview.3 wml::imp::generic.3 wml::std::all.3 \
	wml::std::box.3 wml::std::case.3 wml::std::grid.3 \
	wml::std::label.3 wml::std::href.3 wml::std::lang.3 \
	wml::std::logo.3 wml::std::info.3 wml::std::page.3 \
	wml::std::tags.3 wml::std::toc.3 wml::sup::all.3 \
	wml::sup::hextriple.3 wml::mod::MakeMaker.3 wml::mod::all.3 \
	wml::mod::version.3 wml::sup::path.3 wml::sys::all.3 \
	wml::sys::bootp3.3 wml::sys::bootp4.3 wml::sys::compat1.3

CAT7=	wml_barebone.7 \
	wml_std_css1.7 wml_std_css2.7 wml_std_csspos.7 \
	wml_std_html20.7 wml_std_html32.7 wml_std_html40.7 \
	wml_std_html401.7 wml_std_wai10.7 wml_std_xhtml10.7

MAN7=	wml_intro.7 wml_macros.7 wml_tutorial.7 wml_faq.7 wml_tags.7

.include <bsd.port.pre.mk>

.if exists(${PERL5})
LOCAL_PERL_ARCH!=	${PERL5} -MConfig -e 'print "$$Config{archname}"'
.else
LOCAL_PERL_ARCH=	${ARCH}-freebsd
.endif

.if ${ARCH} == "amd64"
BROKEN=		"Build fails on amd64 (needs to build shared libraries with -fPIC)"
.endif

#   catpages are usually not installed, so they are not compressed.
#   But they are really needed as docs, so we compress manually...
.if !defined(NOMANCOMPRESS)
post-install:
.for page in ${CAT1}
	@${GZIP_CMD} ${PREFIX}/man/cat1/${page}
.endfor
.for page in ${CAT7}
	@${GZIP_CMD} ${PREFIX}/man/cat7/${page}
.endfor
.endif

post-build:
	@${ECHO_MSG} "===>  Use 'make test' to run a quick test suite."

test:
	@cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.post.mk>
