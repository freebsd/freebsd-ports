# New ports collection makefile for:    tex
# Version required:     7.1
# Date created:         29 September 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.32 1997/12/15 02:19:01 jmz Exp $
#

DISTNAME=	web2c-7.1
PKGNAME=	tex-3.14159
CATEGORIES=	print
MASTER_SITES=   ftp://ftp.cdrom.com/pub/tex/package/
DISTFILES=	web2c-7.1.tar.gz web-7.1.tar.gz tex_base.tar.gz cm_tfm.tar.gz \
		mf_lib.tar.gz cm_mf.tar.gz modes.mf 

MAINTAINER=	jmz@FreeBSD.org

MANUAL_PACKAGE_BUILD=	has to be built with latex port
EXTRACT_ONLY=	web2c-7.1.tar.gz web-7.1.tar.gz tex_base.tar.gz cm_tfm.tar.gz \
		mf_lib.tar.gz cm_mf.tar.gz

USE_GMAKE=	yes

MAKE_FLAGS=	fmts= all_mems=

do-build:
	 @(cd ${WRKSRC}; unset `env|grep ^TEX|sed -e s/=.*//`; \
	    ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${ALL_TARGET})

post-install:
	@for i in kpsewhich dmp bibtex dvicopy dvitomp dvitype gftodvi gftopk \
	  gftype mf mft patgen pktogf pktype pltotf pooltype tangle tex tftopl \
	  vftovp vptovf weave; do strip ${PREFIX}/bin/$$i; done
	@rm -f ${PREFIX}/bin/mpostf ${PREFIX}/bin/inimpost ${PREFIX}/bin/virmpost  ${PREFIX}/bin/latex \
	  ${PREFIX}/share/texmf/web2c/mpost.mem ${PREFIX}/share/texmf/web2c/mp.pool
	@${MKDIR} ${PREFIX}/share/texmf/fonts/tfm
	@(cd ${WRKDIR}/tfm; ${INSTALL_DATA} *.tfm ${PREFIX}/share/texmf/fonts/tfm)
	@${MKDIR} ${PREFIX}/share/texmf/metafont
	@(cd ${WRKDIR}/mf; ${INSTALL_DATA} *.mf ${PREFIX}/share/texmf/metafont)
	@${MKDIR} ${PREFIX}/share/texmf/tex
	@(cd ${WRKDIR}/lib; ${INSTALL_DATA} *.tex ${PREFIX}/share/texmf/tex)
	@(cd ${WRKDIR}/base; ${INSTALL_DATA} *.tex ${PREFIX}/share/texmf/tex)

.include <bsd.port.mk>
