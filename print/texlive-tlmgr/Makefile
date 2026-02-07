PORTNAME=	texlive
DISTVERSION=	${TEXLIVE_VERSION}
CATEGORIES=	print perl5
MASTER_SITES=	TEX_CTAN/systems/texlive/${TEXLIVE_YEAR}/
PKGNAMESUFFIX=	-tlmgr
DISTFILES=	${PORTNAME}-${DISTVERSION}-extra${EXTRACT_SUFX} \
		${PORTNAME}-${DISTVERSION}-source${EXTRACT_SUFX}
DIST_SUBDIR=	TeX
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}-extra${EXTRACT_SUFX}

MAINTAINER=	tex@FreeBSD.org
COMMENT=	TeXLive manager modules

LICENSE=	GPLv2

USES=		cpe perl5 tar:xz tex
CPE_VENDOR=	tug
USE_PERL5=	run
USE_TEX=	kpathsea

NO_ARCH=	yes
NO_BUILD=	yes

EXTRACT_AFTER_ARGS_SOURCE=	| ${TAR} -xf - -C ${WRKDIR} \
				--no-same-permission --no-same-owner \
				${PORTNAME}-${DISTVERSION}-source/texk/texlive/linked_scripts/texlive \
				${PORTNAME}-${DISTVERSION}-source/build-aux/config.guess

PATCH_WRKSRC=	${WRKDIR}

post-extract:
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-${DISTVERSION}-source${EXTRACT_SUFX} \
	    ${EXTRACT_AFTER_ARGS_SOURCE}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${TEXMFDISTDIR}/scripts/texlive
	${INSTALL_SCRIPT} \
	    ${WRKDIR}/${PORTNAME}-${DISTVERSION}-source/texk/texlive/linked_scripts/texlive/tlmgr.pl \
	    ${STAGEDIR}${PREFIX}/${TEXMFDISTDIR}/scripts/texlive
	cd ${STAGEDIR}${PREFIX}/bin && \
	    ${LN} -s ../${TEXMFDISTDIR}/scripts/texlive/tlmgr.pl tlmgr
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/TeXLive
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${DISTVERSION}-extra/tlpkg/TeXLive/*.pm \
	    ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/TeXLive
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${DISTVERSION}-extra/tlpkg/TeXLive/trans.pl \
	    ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/TeXLive
	@${MKDIR} ${STAGEDIR}${PREFIX}/${TEXMFDISTDIR}
	${TOUCH} ${STAGEDIR}${PREFIX}/${TEXMFDISTDIR}/.texlive-tlmgr
	${MKDIR} ${STAGEDIR}/var/db/tlpkg/installer
	${TOUCH} ${STAGEDIR}/var/db/tlpkg/tlmgr.log
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${DISTVERSION}-extra/tlpkg/texlive.tlpdb \
	    ${STAGEDIR}/var/db/tlpkg
	${INSTALL_SCRIPT} \
	    ${WRKDIR}/${PORTNAME}-${DISTVERSION}-source/build-aux/config.guess \
	    ${STAGEDIR}/var/db/tlpkg/installer/
	${INSTALL_DATA} ${LOCALBASE}/share/texmf-dist/web2c/texmf.cnf \
	    ${STAGEDIR}/var/db/tlpkg
	${MKDIR} ${STAGEDIR}/var/db/tlpkg/backups
	${MKDIR} ${STAGEDIR}/var/db/tlpkg/tlpobj
	${LN} -s /var/db/tlpkg ${STAGEDIR}${PREFIX}/share/tlpkg

.include <bsd.port.mk>
