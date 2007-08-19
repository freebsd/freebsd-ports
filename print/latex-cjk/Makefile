# New ports collection makefile for:	zh-CJK
# Date created:		5 Sep 1999
# Whom:			Jing-Tang Keith Jang (keith@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	latex-cjk
PORTVERSION=	4.7.0
PORTREVISION=	1
CATEGORIES=	print chinese japanese korean
MASTER_SITES=	http://cjk.ffii.org/ \
		ftp://freebsd.csie.ntu.edu.tw/users/rafan/
DISTNAME=	cjk-${PORTVERSION}
DISTFILES=	${DISTNAME}.tar.gz

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	A LaTeX2e macro package which enables the use of CJK scripts

RUN_DEPENDS=	${LOCALBASE}/share/fonts/TrueType/bsmi00lp.ttf:${PORTSDIR}/chinese/arphicttf \
		latex:${PORTSDIR}/print/teTeX \
		ttf2pk:${PORTSDIR}/print/freetype-tools
BUILD_DEPENDS=	${RUN_DEPENDS} \
		${LOCALBASE}/share/ttf2pt1/maps/cugb.map:${PORTSDIR}/chinese/ttf2pt1 \
		ttf2pt1:${PORTSDIR}/print/ttf2pt1

USE_GMAKE=	yes
USE_FREETYPE=	yes

MAN1=		bg5conv.1 cef5conv.1 cefconv.1 cefsconv.1 extconv.1 \
		hbf2gf.1 sjisconv.1

SUB_FILES=	pkg-message
SUB_LIST=	TEXMFMAIN=${LOCALBASE}/share/texmf

INSTALL_DIR=	${INSTALL} -d -m 0755 -o root -g wheel

CJKDIR=		${PREFIX}/share/texmf/tex/latex/CJK
CJKMAPDIR=	${PREFIX}/share/texmf/fonts/map/dvips/CJK
WRKFONTDIR=	${WRKDIR}/fonts

# Options: WITH_*/WITHOUT_*
OPTIONS=	CCMAP       "CCT CCMap package (for PDFTeX's CID support)" on \
		DVIPDFMX    "Install and configure DVIPDFMx for CJK" on \
		UTF8ARPHIC  "Arphic free fonts in UTF-8 (no Type 1)" off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_CCMAP)
PLIST_SUB+=	CCMAP="@comment "
.else
MASTER_SITES+=	http://ftp.intron.ac/pub/FreeBSD/local-distfiles/:cct
DISTFILES+=	cct-20060219-ccmap.tar.gz:cct
PLIST_SUB+=	CCMAP=""
.endif

.if !defined(WITHOUT_DVIPDFMX)
RUN_DEPENDS+=	dvipdfmx:${PORTSDIR}/print/dvipdfmx
# Configuration is done by "pkg-install"
.endif

.if defined(WITH_UTF8ARPHIC)
PLIST_SUB+=	UTF8ARPHIC=""
.else
PLIST_SUB+=	UTF8ARPHIC="@comment "
.endif

post-extract:
	@${RM} -f ${WRKSRC}/Makefile

post-patch:
	# be compatible with Debian
	@${CP} -p ${WRKSRC}/texinput/Bg5/c00kai.fd ${WRKSRC}/texinput/Bg5/c00bkai.fd
	@${REINPLACE_CMD} -e 's,c00kai.fd,c00bkai.fd,; s,{kai},{bkai},' ${WRKSRC}/texinput/Bg5/c00bkai.fd
	@${FIND} -E ${WRKSRC} -regex '.*.(orig|bak)' -delete

pre-su-install:
	${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
.if !defined(NOPORTDOCS)
	${RM} -fr ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc ${DOCSDIR}
.endif
	${RM} -fr ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples ${EXAMPLESDIR}

# Install Arphic fonts for Type 3 or DVIPDFMx
	@${ECHO_CMD} "Generating Arphic fonts' TFM files..."
	${SETENV} LOCALBASE=${LOCALBASE} ${SH} ${SCRIPTDIR}/installtfm.sh \
		arb5sung arb5sung.ttf UBig5
	${SETENV} LOCALBASE=${LOCALBASE} ${SH} ${SCRIPTDIR}/installtfm.sh \
		arb5kai arb5kai.ttf UBig5
	${SETENV} LOCALBASE=${LOCALBASE} ${SH} ${SCRIPTDIR}/installtfm.sh \
		argbsung argbsung.ttf UGB
	${SETENV} LOCALBASE=${LOCALBASE} ${SH} ${SCRIPTDIR}/installtfm.sh \
		argbkai argbkai.ttf UGB

# Install Arphic fonts for Type 1 and PDFTeX
	@${ECHO_CMD} "Generating Type 1 Arphic fonts..."
	${MKDIR} ${WRKFONTDIR}
	${ECHO} -n "" > ${WRKFONTDIR}/CJK-type1.map
	${ECHO} -n "" > ${WRKFONTDIR}/CJK-pdftex.map
	cd ${WRKFONTDIR} && ${SETENV} LOCALBASE=${LOCALBASE} ${SH} \
		${SCRIPTDIR}/installt1enc.sh arb5sung arb5sung.ttf Bg5
	cd ${WRKFONTDIR} && ${SETENV} LOCALBASE=${LOCALBASE} ${SH} \
		${SCRIPTDIR}/installt1enc.sh arb5kai arb5kai.ttf Bg5
	cd ${WRKFONTDIR} && ${SETENV} LOCALBASE=${LOCALBASE} ${SH} \
		${SCRIPTDIR}/installt1enc.sh argbsung argbsung.ttf GB
	cd ${WRKFONTDIR} && ${SETENV} LOCALBASE=${LOCALBASE} ${SH} \
		${SCRIPTDIR}/installt1enc.sh argbkai argbkai.ttf GB

# Install package ccmap
.if !defined(WITHOUT_CCMAP)
	@${ECHO_CMD} "Installing ccmap..."
	${LOCALBASE}/bin/mktexlsr
	cd ${WRKDIR}/ccmap && ${SH} make.sh
	${CP} -R ${WRKDIR}/ccmap ${CJKDIR}/
.endif

# Install Arphic fonts in Unicode separation for Type 3 or DVIPDFMx
.if defined(WITH_UTF8ARPHIC)
	@${ECHO_CMD} "Generating Arphic fonts' TFM files in Unicode..."
	${SETENV} LOCALBASE=${LOCALBASE} ${SH} ${SCRIPTDIR}/installtfm.sh \
		arb5sungu arb5sung.ttf Unicode
	${SETENV} LOCALBASE=${LOCALBASE} ${SH} ${SCRIPTDIR}/installtfm.sh \
		arb5kaiu arb5kai.ttf Unicode
	${SETENV} LOCALBASE=${LOCALBASE} ${SH} ${SCRIPTDIR}/installtfm.sh \
		argbsungu argbsung.ttf Unicode
	${SETENV} LOCALBASE=${LOCALBASE} ${SH} ${SCRIPTDIR}/installtfm.sh \
		argbkaiu argbkai.ttf Unicode
.endif

# Mapping files for updmap(1) and PDFTeX
	${INSTALL_DIR} ${CJKMAPDIR}
	${INSTALL_DATA} ${WRKFONTDIR}/CJK-type1.map ${CJKMAPDIR}
	${INSTALL_DATA} ${WRKFONTDIR}/CJK-pdftex.map ${CJKMAPDIR}

# Final
	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
