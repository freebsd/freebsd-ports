# Created by: jmz
# $FreeBSD$

PORTNAME=	tex
PORTVERSION=	3.14159
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	mikeh
#${MASTER_SITE_TEX_CTAN} XXX distfiles disappeared/moved?
#MASTER_SITE_SUBDIR=	systems/web2c
DISTNAME=	web2c-7.2
DISTFILES=	web2c-7.2b.tar.gz web-7.2a.tar.gz tex_base.tar.gz cm_tfm.tar.gz \
		mf_lib.tar.gz cm_mf.tar.gz modes.mf
EXTRACT_ONLY=	web2c-7.2b.tar.gz web-7.2a.tar.gz tex_base.tar.gz cm_tfm.tar.gz \
		mf_lib.tar.gz cm_mf.tar.gz

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	TeX and METAFONT

DIST_SUBDIR=	tex

CONFLICTS=	teTeX*

USES=		gmake desthack
GNU_CONFIGURE=	yes

INFO=		kpathsea web2c
MAKE_FLAGS=	fmts= all_mems=

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		Segfault during build on ia64
.endif

pre-configure:
	cd ${WRKDIR} && ${FIND} . -name \*.gz | ${XARGS} ${GUNZIP_CMD} -f

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
	  vftovp vptovf weave; do ${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/$$i; done
	@${RM} -f ${STAGEDIR}${PREFIX}/bin/mpostf ${STAGEDIR}${PREFIX}/bin/inimpost \
	${STAGEDIR}${PREFIX}/bin/virmpost ${STAGEDIR}${PREFIX}/bin/latex \
	  ${STAGEDIR}${PREFIX}/share/texmf/web2c/mpost.mem ${STAGEDIR}${PREFIX}/share/texmf/web2c/plain.mem \
	  ${STAGEDIR}${PREFIX}/share/texmf/web2c/mp.pool ${STAGEDIR}${PREFIX}/bin/mpost ${STAGEDIR}${PREFIX}/bin/mpto
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/texmf/fonts/tfm
	@(cd ${WRKDIR}/tfm; ${INSTALL_DATA} *.tfm ${STAGEDIR}${PREFIX}/share/texmf/fonts/tfm)
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/texmf/metafont
	@(cd ${WRKDIR}/mf; ${INSTALL_DATA} *.mf ${STAGEDIR}${PREFIX}/share/texmf/metafont)
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/texmf/tex
	@(cd ${WRKDIR}/lib; ${INSTALL_DATA} *.tex ${STAGEDIR}${PREFIX}/share/texmf/tex)
	@(cd ${WRKDIR}/base; ${INSTALL_DATA} *.tex ${STAGEDIR}${PREFIX}/share/texmf/tex)

.include <bsd.port.post.mk>
