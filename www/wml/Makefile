# New ports collection makefile for:	wml
# Version required:	1.1.0
# Date created:		Mon Aug 18 12:25:28 MET DST 1997
# Whom:			Ralf S. Engelschall <rse@engelschall.com>
#
# $Id$
#

DISTNAME=	wml-1.1.0
CATEGORIES=	www lang
MASTER_SITES=	http://www.engelschall.com/sw/wml/distrib/ \
		ftp://ftp.engelschall.com/sw/

MAINTAINER=	rse@engelschall.com

USE_PERL5=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-perl=${PREFIX}/bin/perl

CAT1=	wml_aux_linklint.1 wml_aux_txt2html.1 \
	wml_aux_wwwtable.1 wml_p2_mhc.1 wml_p4_gm4.1

MAN1=	wml.1 wml_aux_gfont.1 wml_aux_htmlinfo.1 \
	wml_aux_map2html.1 wml_aux_weblint.1 wml_p1_ipp.1 \
	wml_p3_eperl.1 wml_p5_divert.1 wml_p6_asubst.1 \
	wml_p7_htmlfix.1 wml_p8_htmlstrip.1 wml_p9_slice.1

MAN3=	wml::all.3 wml::app::all.3 wml::app::javascript.3 \
	wml::app::toc.3 wml::app::navbar.3 wml::des::all.3 \
	wml::des::box.3 wml::des::gfont.3 wml::des::grid.3 \
	wml::des::imgdot.3 wml::des::imgsize.3 wml::des::rollover.3 \
	wml::des::space.3 wml::des::typography.3 wml::fmt::all.3 \
	wml::fmt::isolatin.3 wml::fmt::verbatim.3 wml::imp::all.3 \
	wml::imp::csmap.3 wml::imp::generic.3 wml::imp::pod.3 \
	wml::imp::remote.3 wml::imp::sdf.3 wml::imp::text.3 \
	wml::imp::view.3 wml::imp::wwwtable.3 wml::msc::all.3 \
	wml::msc::hextriple.3 wml::msc::m4.3 wml::msc::path.3 \
	wml::std::all.3 wml::std::divert.3 wml::std::fileinfo.3 \
	wml::std::headfoot.3 wml::std::stack.3 wml::std::symbol.3 \
	wml::std::tags.3 wml::std::url.3 wml::sys::boot.3

#   catpages are usually not installed, so they are not compressed.
#   But they are really needed as docs, so we compress manually...
.if !defined(NOMANCOMPRESS)
post-install:
.for page in ${CAT1}
	@${GZIP_CMD} ${PREFIX}/man/cat1/${page}
.endfor
.endif

.include <bsd.port.mk>
