# New ports collection makefile for:    tex
# Date created:         29 September 1994
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	tex
PORTVERSION=	3.14159
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=   ${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	mikeh
#${MASTER_SITE_TEX_CTAN} XXX distfiles disappeared/moved?
#MASTER_SITE_SUBDIR=	systems/web2c
DISTNAME=	web2c-7.2
DISTFILES=	web2c-7.2b.tar.gz web-7.2a.tar.gz tex_base.tar.gz cm_tfm.tar.gz \
		mf_lib.tar.gz cm_mf.tar.gz modes.mf
EXTRACT_ONLY=	web2c-7.2b.tar.gz web-7.2a.tar.gz tex_base.tar.gz cm_tfm.tar.gz \
		mf_lib.tar.gz cm_mf.tar.gz

MAINTAINER=	jmz@FreeBSD.org
COMMENT=	TeX and METAFONT

DIST_SUBDIR=	tex

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		access.1 amstex.1 bibtex.1 dmp.1 dvicopy.1 dvitype.1 eplain.1 \
		etex.1 gftodvi.1 gftopk.1 gftype.1 kpsestat.1 kpsewhich.1 \
		latex.1 makempx.1 mf.1 mft.1 mktexlsr.1 mktexmf.1 mktexpk.1 \
		mktextfm.1 mpost.1 mpto.1 newer.1 omega.1 patgen.1 pdftex.1 \
		pktogf.1 pktype.1 pltotf.1 pooltype.1 readlink.1 tangle.1 \
		tex.1 tftopl.1 tie.1 vftovp.1 vptovf.1 weave.1
INFO=		kpathsea web2c
MAKE_FLAGS=	fmts= all_mems=

pre-configure:
	cd ${WRKDIR} && ${FIND} . -name \*.gz | ${XARGS} gunzip -f

post-configure:
	@cd ${WRKSRC}/web2c; \
	${LN} -s ../../tfm/*.tfm ../../base/*.tex ../../mf/*.mf ../../lib/*.mf .; \
	${CP} ${DISTDIR}/${DIST_SUBDIR}/modes.mf .

do-build:
	@(cd ${WRKSRC}; unset `env|${GREP} ^TEX|${SED} -e s/=.*//`; \
	    ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${ALL_TARGET})

post-install:
	@for i in kpsewhich dmp bibtex dvicopy dvitomp dvitype gftodvi gftopk \
	  gftype mf mft patgen pktogf pktype pltotf pooltype tangle tex tftopl \
	  vftovp vptovf weave; do ${STRIP_CMD} ${PREFIX}/bin/$$i; done
	@${RM} -f ${PREFIX}/bin/mpostf ${PREFIX}/bin/inimpost ${PREFIX}/bin/virmpost  ${PREFIX}/bin/latex \
	  ${PREFIX}/share/texmf/web2c/mpost.mem ${PREFIX}/share/texmf/web2c/plain.mem \
	  ${PREFIX}/share/texmf/web2c/mp.pool ${PREFIX}/bin/mpost ${PREFIX}/bin/mpto
	@${MKDIR} ${PREFIX}/share/texmf/fonts/tfm
	@(cd ${WRKDIR}/tfm; ${INSTALL_DATA} *.tfm ${PREFIX}/share/texmf/fonts/tfm)
	@${MKDIR} ${PREFIX}/share/texmf/metafont
	@(cd ${WRKDIR}/mf; ${INSTALL_DATA} *.mf ${PREFIX}/share/texmf/metafont)
	@${MKDIR} ${PREFIX}/share/texmf/tex
	@(cd ${WRKDIR}/lib; ${INSTALL_DATA} *.tex ${PREFIX}/share/texmf/tex)
	@(cd ${WRKDIR}/base; ${INSTALL_DATA} *.tex ${PREFIX}/share/texmf/tex)

.include <bsd.port.mk>
