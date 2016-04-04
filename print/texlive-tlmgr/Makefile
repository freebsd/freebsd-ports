# $FreeBSD$

PORTNAME=	texlive
PORTVERSION=	20150523
PORTREVISION=	2
CATEGORIES=	print perl5
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2015/:tlmgr \
		LOCAL/hrs:tlpkg
PKGNAMESUFFIX=	-tlmgr
DISTFILES=	${PORTNAME}-${PORTVERSION}-extra${EXTRACT_SUFX}:tlmgr \
		${PORTNAME}-20150521-source${EXTRACT_SUFX}:tlmgr \
		${TLPKG_FILE}.xz:tlpkg
DIST_SUBDIR=	TeX
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}-extra${EXTRACT_SUFX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	TeXLive manager modules

RUN_DEPENDS=	tex-kpathsea>=6.2.1_1:devel/tex-kpathsea

CONFLICTS=	texlive-infra-[0-9]* texlive-base-20150521_[12345]

USES=		perl5 tar:xz
USE_PERL5=	run
USE_TEX=	kpathsea
PATCH_WRKSRC=	${WRKDIR}
NO_BUILD=	yes

TLPKG_FILE=	${PORTNAME}-20150924.tlpdb
EXTRACT_AFTER_ARGS_SOURCE= \
	| ${TAR} -xf - -C ${WRKDIR} \
	    --no-same-permission --no-same-owner \
	    ${PORTNAME}-20150521-source/texk/texlive/linked_scripts/texlive

post-extract:
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-20150521-source${EXTRACT_SUFX} \
	    ${EXTRACT_AFTER_ARGS_SOURCE}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${TEXMFDISTDIR}/scripts/texlive
	${INSTALL_SCRIPT} \
	    ${WRKDIR}/${PORTNAME}-20150521-source/texk/texlive/linked_scripts/texlive/tlmgr.pl \
	    ${STAGEDIR}${PREFIX}/${TEXMFDISTDIR}/scripts/texlive
	cd ${STAGEDIR}${PREFIX}/bin && \
	    ${LN} -s ../${TEXMFDISTDIR}/scripts/texlive/tlmgr.pl tlmgr
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/TeXLive
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${PORTVERSION}-extra/tlpkg/TeXLive/*.pm \
	    ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/TeXLive
	@${MKDIR} ${STAGEDIR}${PREFIX}/${TEXMFDISTDIR}
	${TOUCH} ${STAGEDIR}${PREFIX}/${TEXMFDISTDIR}/.texlive-tlmgr
	${MKDIR} ${STAGEDIR}/var/db/tlpkg
	${TOUCH} ${STAGEDIR}/var/db/tlpkg/tlmgr.log
	${XZCAT} ${DISTDIR}/${DIST_SUBDIR}/${TLPKG_FILE}.xz \
	    > ${STAGEDIR}/var/db/tlpkg/texlive.tlpdb
	${INSTALL_DATA} ${LOCALBASE}/share/texmf-dist/web2c/texmf.cnf \
	    ${STAGEDIR}/var/db/tlpkg
	${MKDIR} ${STAGEDIR}/var/db/tlpkg/backups
	${MKDIR} ${STAGEDIR}/var/db/tlpkg/tlpobj
	${LN} -s /var/db/tlpkg ${STAGEDIR}${PREFIX}/share/tlpkg

.include <bsd.port.mk>
