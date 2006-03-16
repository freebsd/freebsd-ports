# New ports collection makefile for:	zh-CJK
# Date created:		5 Sep 1999
# Whom:			Jing-Tang Keith Jang (keith@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	CJK
PORTVERSION=	4.6.0
PORTREVISION=	1
CATEGORIES=	chinese
MASTER_SITES=	http://cjk.ffii.org/ \
		ftp://freebsd.csie.ntu.edu.tw/users/rafan/
DISTNAME=	cjk-${PORTVERSION}
DISTFILES=	${DISTNAME}.tar.gz

MAINTAINER=	rafan@infor.org
COMMENT=	A LaTeX2e macro package which enables the use of CJK scripts

BUILD_DEPENDS=	latex:${PORTSDIR}/print/teTeX \
		${LOCALBASE}/share/fonts/TrueType/bsmi00lp.ttf:${PORTSDIR}/chinese/arphicttf \
		ttf2pk:${PORTSDIR}/print/freetype-tools
RUN_DEPENDS:=	${BUILD_DEPENDS} # Equal to BUILD_DEPENDS, immediate effect

BUILD_DEPENDS+=	ttf2pt1:${PORTSDIR}/print/ttf2pt1 \
		${LOCALBASE}/share/ttf2pt1/maps/cugb.map:${PORTSDIR}/chinese/ttf2pt1

USE_GMAKE=	yes
USE_FREETYPE=	yes

MAN1=		bg5conv.1 cef5conv.1 cefconv.1 cefsconv.1 extconv.1 \
		hbf2gf.1 sjisconv.1

SUB_FILES=	pkg-message
SUB_LIST=	TEXMFMAIN=${LOCALBASE}/share/texmf

INSTALL_DIR=	/usr/bin/install -d -m 0755 -o root -g wheel

CJKDIR=		${PREFIX}/share/texmf/tex/latex/CJK
WRKFONTDIR=	${WRKDIR}/fonts
CJKMAPDIR=	${PREFIX}/share/texmf/fonts/map/CJK

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
BUILD_DEPENDS+=	dvipdfmx:${PORTSDIR}/print/dvipdfmx
RUN_DEPENDS+=	dvipdfmx:${PORTSDIR}/print/dvipdfmx
# Configuration is done by "pkg-install"
.endif

.if defined(WITH_UTF8ARPHIC)
PLIST_SUB+=	UTF8ARPHIC=""
.else
PLIST_SUB+=	UTF8ARPHIC="@comment "
.endif

pre-patch:
	@${RM} -f ${WRKSRC}/Makefile

post-patch:
	@${FIND} ${WRKSRC}/texinput -name \*.orig | ${XARGS} -n 1 ${RM} -f

pre-install:
	${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
.if !defined(NOPORTDOCS)
	${RM} -fr ${PREFIX}/share/doc/CJK
	${CP} -R ${WRKSRC}/doc ${PREFIX}/share/doc/CJK
.endif
	${RM} -fr ${PREFIX}/share/examples/CJK
	${CP} -R ${WRKSRC}/examples ${PREFIX}/share/examples/CJK

# Install Arphic fonts for Type 3 or DVIPDFMx
	@${ECHO_CMD} "Generating Arphic fonts' TFM files..."
	LOCALBASE=${LOCALBASE} ${SH} ${SCRIPTDIR}/installtfm.sh   arb5sung arb5sung.ttf UBig5
	LOCALBASE=${LOCALBASE} ${SH} ${SCRIPTDIR}/installtfm.sh   arb5kai  arb5kai.ttf  UBig5
	LOCALBASE=${LOCALBASE} ${SH} ${SCRIPTDIR}/installtfm.sh   argbsung argbsung.ttf UGB
	LOCALBASE=${LOCALBASE} ${SH} ${SCRIPTDIR}/installtfm.sh   argbkai  argbkai.ttf  UGB

# Install Arphic fonts for Type 1 and PDFTeX
	@${ECHO_CMD} "Generating Type 1 Arphic fonts..."
	${MKDIR} ${WRKFONTDIR}
	${ECHO} -n "" > ${WRKFONTDIR}/CJK-type1.map
	${ECHO} -n "" > ${WRKFONTDIR}/CJK-pdftex.map
	cd ${WRKFONTDIR} && LOCALBASE=${LOCALBASE} ${SH} ${SCRIPTDIR}/installt1enc.sh arb5sung arb5sung.ttf Bg5
	cd ${WRKFONTDIR} && LOCALBASE=${LOCALBASE} ${SH} ${SCRIPTDIR}/installt1enc.sh arb5kai  arb5kai.ttf  Bg5
	cd ${WRKFONTDIR} && LOCALBASE=${LOCALBASE} ${SH} ${SCRIPTDIR}/installt1enc.sh argbsung argbsung.ttf GB
	cd ${WRKFONTDIR} && LOCALBASE=${LOCALBASE} ${SH} ${SCRIPTDIR}/installt1enc.sh argbkai  argbkai.ttf  GB

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
	LOCALBASE=${LOCALBASE} ${SH} ${SCRIPTDIR}/installtfm.sh arb5sungu arb5sung.ttf Unicode
	LOCALBASE=${LOCALBASE} ${SH} ${SCRIPTDIR}/installtfm.sh arb5kaiu  arb5kai.ttf  Unicode
	LOCALBASE=${LOCALBASE} ${SH} ${SCRIPTDIR}/installtfm.sh argbsungu argbsung.ttf Unicode
	LOCALBASE=${LOCALBASE} ${SH} ${SCRIPTDIR}/installtfm.sh argbkaiu  argbkai.ttf  Unicode
.endif

# Mapping files for updmap(1) and PDFTeX
	${INSTALL_DIR} ${CJKMAPDIR}
	${INSTALL_DATA} ${WRKFONTDIR}/CJK-type1.map ${CJKMAPDIR}
	${INSTALL_DATA} ${WRKFONTDIR}/CJK-pdftex.map ${CJKMAPDIR}

# Final
	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
