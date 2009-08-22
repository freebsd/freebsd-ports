# New ports collection makefile for:   xdvik
# Date created:        26 Feb 1998
# Whom:                Kentaro Inagaki <JBD01226@niftyserve.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	xdvik
PORTVERSION=	22.84.10
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	SF/xdvi/${PORTNAME}/${PORTVERSION}
PKGNAMESUFFIX=	-tetex

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	DVI Previewer(kpathsearch) for X

BUILD_DEPENDS=	${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal \
		${LOCALBASE}/${TEXMFDISTDIR}/LICENSE.texmf:${PORTSDIR}/print/teTeX-texmf \
		mktexlsr:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS=	${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal \
		${LOCALBASE}/${TEXMFDISTDIR}/LICENSE.texmf:${PORTSDIR}/print/teTeX-texmf \
		mktexlsr:${PORTSDIR}/print/teTeX-base
LIB_DEPENDS=	t1.5:${PORTSDIR}/devel/t1lib

USE_GMAKE=	yes
USE_MOTIF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-system-t1lib \
		--with-t1lib-libdir=${LIBT1_PREFIX}/lib \
		--with-t1lib-include=${LIBT1_PREFIX}/include \
		--disable-multiplatform
CONFIGURE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		CFLAGS="${CFLAGS} -I${LOCALBASE}/include"
INSTALL_WRKSRC=	${WRKSRC}/texk/xdvik

PLIST_SUB=	TEXMFDIR=${TEXMFDIR} TEXMFCONFIGDIR=${TEXMFDIR}-config
CONFLICTS=	xdvi-[0-9]* xdvi-*-[0-9]* \
		*-xdvi-[0-9]* xdvi-*-[0-9]* \
		*-xdvik-[0-9]* ja-ptex-tetex-[0-9]*

MAN1=		xdvi.1 xdvizilla.1
MLINKS=		xdvi.1 oxdvi.1

TEXMFDIR=	share/texmf
TEXMFDISTDIR=	share/texmf-dist
TEXMFLOCALDIR=	share/texmf-local
TEXMFLOCAL_LSR?=${LOCALBASE}/${TEXMFLOCALDIR}/ls-R
TEXCONFIGBIN=	${LOCALBASE}/bin/texconfig-sys
MKTEXLSR?=	${LOCALBASE}/bin/mktexlsr
LIBT1_PREFIX?=	${LOCALBASE}
DOC_FILES=	BUGS CHANGES INSTALL \
		README README.CVS README_maintainer TODO

.if defined(WITH_LETTERSIZE)
FLAVOR+=        letter
PAPERSIZE=      letter
.else
PAPERSIZE=      a4
.endif

PKGINSTALL=	${WRKDIR}/pkg-install.sh
PKGDEINSTALL=	${WRKDIR}/pkg-install.sh
PKGINSTALL_SUB=	MKTEXLSR=${MKTEXLSR} \
		XDVIDIR=${PREFIX}/${TEXMFDIR}/xdvi \
		XDVICONFDIR=${PREFIX}/${TEXMFDIR}-config/xdvi \
		PAPERSIZE=${PAPERSIZE} \
		TEXCONFIGBIN=${TEXCONFIGBIN} \
		LOCALBASE=${LOCALBASE}

pre-install:
	${SED} ${PKGINSTALL_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		< ${FILESDIR}/pkg-install.in > ${PKGINSTALL}
	${CHMOD} 0755 ${PKGINSTALL}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES:S@^@${WRKSRC}/@} ${DOCSDIR}
.endif
	@${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
