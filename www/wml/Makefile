# New ports collection makefile for:	wml
# Version required:	1.6.7
# Date created:		09-Sep-1997
# Whom:			Ralf S. Engelschall <rse@engelschall.com>
#
# $Id: Makefile,v 1.21 1998/06/25 12:34:26 rse Exp $
#

DISTNAME=	wml-1.6.7
CATEGORIES=	www lang
MASTER_SITES=	http://www.engelschall.com/sw/wml/distrib/ \
		ftp://ftp.ch.engelschall.com/sw/wml/ \
		ftp://ftp.de.engelschall.com/sw/wml/ \
		ftp://ftp.hyperreal.org/software/engelschall/wml/

MAINTAINER=	rse@engelschall.com

USE_PERL5=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-perl=${PREFIX}/bin/perl

CAT1=	wml_aux_linklint.1 wml_aux_txt2html.1 \
	wml_aux_wwwtable.1 wml_p2_mhc.1 wml_p4_gm4.1

MAN1=	wmd.1 wmk.1 wml.1 wmb.1 wmu.1 \
	wml_aux_htmlinfo.1 wml_aux_iselect.1 \
	wml_aux_map2html.1 wml_aux_weblint.1 wml_p1_ipp.1 \
	wml_p3_eperl.1 wml_p5_divert.1 wml_p6_asubst.1 \
	wml_p7_htmlfix.1 wml_p8_htmlstrip.1 wml_p9_slice.1

MAN3=	wml::all.3 wml::des::all.3 wml::des::gfont.3 \
	wml::des::lowsrc.3 wml::des::imgdot.3 wml::des::imgbg.3 \
	wml::des::navbar.3 wml::des::preload.3 wml::des::rollover.3 \
	wml::des::space.3 wml::des::typography.3 wml::fmt::all.3 \
	wml::fmt::isolatin.3 wml::fmt::pod.3 wml::fmt::sdf.3 \
	wml::fmt::text.3 wml::fmt::url.3 wml::fmt::verbatim.3 \
	wml::fmt::xtable.3 wml::imp::all.3 wml::imp::csmap.3 \
	wml::imp::fsview.3 wml::imp::generic.3 wml::std::all.3 \
	wml::std::box.3 wml::std::case.3 wml::std::grid.3 \
	wml::std::href.3 wml::std::lang.3 wml::std::logo.3 \
	wml::std::info.3 wml::std::page.3 wml::std::tags.3 \
	wml::std::toc.3 wml::sup::all.3 wml::sup::hextriple.3 \
	wml::sup::path.3 wml::sys::all.3 wml::sys::boot.3

CAT7=	wml_barebone.7 \
	wml_std_css1.7 wml_std_css2.7 wml_std_csspos.7 \
	wml_std_html20.7 wml_std_html32.7 wml_std_html40.7

MAN7=	wml_intro.7 wml_tutorial.7 wml_faq.7 wml_tags.7

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

.include <bsd.port.mk>
