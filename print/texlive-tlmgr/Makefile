PORTNAME=	texlive
PORTVERSION=	${TEXLIVE_VERSION}
PORTREVISION=	1
CATEGORIES=	print perl5
MASTER_SITES=	TEX_CTAN/systems/texlive/${TEXLIVE_YEAR}/
PKGNAMESUFFIX=	-tlmgr
DISTFILES=	${PORTNAME}-${PORTVERSION}-extra${EXTRACT_SUFX} \
		${PORTNAME}-${PORTVERSION}-source${EXTRACT_SUFX} \
		${TLPKG_FILE}.tar.gz
DIST_SUBDIR=	TeX
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}-extra${EXTRACT_SUFX}

MAINTAINER=	tex@FreeBSD.org
COMMENT=	TeXLive manager modules

RUN_DEPENDS=	tex-kpathsea>=6.3.3:devel/tex-kpathsea

USES=		cpe perl5 tar:xz
CPE_VENDOR=	tug
USE_PERL5=	run
USE_TEX=	kpathsea

NO_ARCH=	yes
NO_BUILD=	yes

TLPKG_FILE=			${PORTNAME}-${PORTVERSION}-tlpdb-full
EXTRACT_AFTER_ARGS_SOURCE=	| ${TAR} -xf - -C ${WRKDIR} \
				--no-same-permission --no-same-owner \
				${PORTNAME}-${PORTVERSION}-source/texk/texlive/linked_scripts/texlive

PATCH_WRKSRC=	${WRKDIR}

post-extract:
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-${PORTVERSION}-source${EXTRACT_SUFX} \
	    ${EXTRACT_AFTER_ARGS_SOURCE}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${TEXMFDISTDIR}/scripts/texlive
	${INSTALL_SCRIPT} \
	    ${WRKDIR}/${PORTNAME}-${PORTVERSION}-source/texk/texlive/linked_scripts/texlive/tlmgr.pl \
	    ${STAGEDIR}${PREFIX}/${TEXMFDISTDIR}/scripts/texlive
	cd ${STAGEDIR}${PREFIX}/bin && \
	    ${LN} -s ../${TEXMFDISTDIR}/scripts/texlive/tlmgr.pl tlmgr
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/TeXLive
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${PORTVERSION}-extra/tlpkg/TeXLive/*.pm \
	    ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/TeXLive
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${PORTVERSION}-extra/tlpkg/TeXLive/trans.pl \
	    ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/TeXLive
	@${MKDIR} ${STAGEDIR}${PREFIX}/${TEXMFDISTDIR}
	${TOUCH} ${STAGEDIR}${PREFIX}/${TEXMFDISTDIR}/.texlive-tlmgr
	${MKDIR} ${STAGEDIR}/var/db/tlpkg
	${TOUCH} ${STAGEDIR}/var/db/tlpkg/tlmgr.log
	${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/${TLPKG_FILE}.tar.gz -C \
	    ${STAGEDIR}/var/db/tlpkg/ texlive.tlpdb
	${INSTALL_DATA} ${LOCALBASE}/share/texmf-dist/web2c/texmf.cnf \
	    ${STAGEDIR}/var/db/tlpkg
	${MKDIR} ${STAGEDIR}/var/db/tlpkg/backups
	${MKDIR} ${STAGEDIR}/var/db/tlpkg/tlpobj
	${LN} -s /var/db/tlpkg ${STAGEDIR}${PREFIX}/share/tlpkg

.include <bsd.port.mk>
