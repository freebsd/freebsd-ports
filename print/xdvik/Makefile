# Created by: Kentaro Inagaki <JBD01226@niftyserve.ne.jp>
# $FreeBSD$

PORTNAME=	xdvik
PORTVERSION=	22.84.16
PORTREVISION=	6
CATEGORIES=	print
MASTER_SITES=	SF/hoge
#/xdvi/${PORTNAME}/${PORTVERSION}
PKGNAMESUFFIX=	-tetex

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	DVI Previewer(kpathsearch) for X

LIB_DEPENDS=	libt1.so:${PORTSDIR}/devel/t1lib

USES=		gmake iconv motif
USE_TEX=	base texmf
MAKE_JOBS_UNSAFE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-system-t1lib \
		--with-t1lib-libdir=${LIBT1_PREFIX}/lib \
		--with-t1lib-include=${LIBT1_PREFIX}/include \
		--disable-multiplatform
CONFIGURE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_WRKSRC=	${WRKSRC}/texk/xdvik

PLIST_SUB=	TEXMFDIR=${TEXMFDIR} TEXMFCONFIGDIR=${TEXMFDIR}-config
CONFLICTS_INSTALL=	xdvi-[0-9]* xdvi-*-[0-9]* *-xdvi-[0-9]* \
			*-xdvik-[0-9]* ja-xdvik-*-[0-9]* \
			texlive-[0-9]* tex-web2c-[0-9]* \
			tex-kpathsea-[0-9]* tex-xdvik-[0-9]* \
			tex-dvipsk-[0-9]* tex-dvipdfmx-[0-9]*

MAN1=		xdvi.1
MLINKS=		xdvi.1 oxdvi.1

TEXMFDIR=	share/texmf
TEXMFDISTDIR=	share/texmf-dist
TEXMFLOCALDIR=	share/texmf-local
TEXMFLOCAL_LSR?=${LOCALBASE}/${TEXMFLOCALDIR}/ls-R
TEXCONFIGBIN=	${LOCALBASE}/bin/texconfig-sys
MKTEXLSR?=	${LOCALBASE}/bin/mktexlsr
LIBT1_PREFIX?=	${LOCALBASE}
PORTDOCS=	BUGS CHANGES INSTALL \
		README README.CVS README_maintainer TODO

.if defined(WITH_LETTERSIZE)
FLAVOR+=	letter
PAPERSIZE=	letter
.else
PAPERSIZE=	a4
.endif

PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
SUB_LIST=	MKTEXLSR=${MKTEXLSR} \
		XDVIDIR=${PREFIX}/${TEXMFDIR}/xdvi \
		XDVICONFDIR=${PREFIX}/${TEXMFDIR}-config/xdvi \
		PAPERSIZE=${PAPERSIZE} \
		TEXCONFIGBIN=${TEXCONFIGBIN} \
		LOCALBASE=${LOCALBASE}

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} 's/@iconv_libs@/${ICONV_LIB}/' \
	    ${WRKSRC}/texk/xdvik/Makefile.in \
	    ${WRKSRC}/texk/xdvik/tests/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
