# New ports collection makefile for:   xdvik
# Date created:        26 Feb 1998
# Whom:                Kentaro Inagaki <JBD01226@niftyserve.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	xdvik
PORTVERSION=	22.78
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xdvi
PKGNAMESUFFIX=	-tetex

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	DVI Previewer(kpathsearch) for X

BUILD_DEPENDS=	tetex-modesw:${PORTSDIR}/print/tex-texmflocal \
		${LOCALBASE}/${TEXMF}/LICENSE.texmf:${PORTSDIR}/print/teTeX-texmf \
		mktexlsr:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS=	tetex-modesw:${PORTSDIR}/print/tex-texmflocal \
		${LOCALBASE}/${TEXMF}/LICENSE.texmf:${PORTSDIR}/print/teTeX-texmf \
		mktexlsr:${PORTSDIR}/print/teTeX-base
LIB_DEPENDS=	t1.5:${PORTSDIR}/devel/t1lib

USE_XLIB=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-system-t1lib --with-t1lib-libdir=${LIBT1_PREFIX}/lib \
		--with-t1lib-include=${LIBT1_PREFIX}/include
CONFIGURE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		CFLAGS="${CFLAGS} -I${LOCALBASE}/include"
INSTALL_WRKSRC=	${WRKSRC}/texk/xdvik

PLIST_SUB=	TEXMF=${TEXMF} MKTEXLSR=${MKTEXLSR}
CONFLICTS=	xdvi-* *-xdvi*

MAN1=		xdvi.1 t1mapper.1 xdvizilla.1

TEXMF?=		share/texmf
MKTEXLSR?=	${LOCALBASE}/bin/mktexlsr
LIBT1_PREFIX?=	${LOCALBASE}
DOC_FILES=	BUGS CHANGES INSTALL \
		README README.CVS README_maintainer TODO

TETEX_MODESW=	${LOCALBASE}/bin/tetex-modesw
PKGINSTALL=	${WRKDIR}/pkg-install.sh
PKGDEINSTALL=	${WRKDIR}/pkg-install.sh
PKGINSTALL_SUB=	TETEX_MODESW=${TETEX_MODESW} \
		MKTEXLSR=${MKTEXLSR}

pre-build:
	${SED} ${PKGINSTALL_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		< ${FILESDIR}/pkg-install.in > ${PKGINSTALL}
	${CHMOD} 0755 ${PKGINSTALL}

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/texk/xdvik/t1mapper ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES:S@^@${WRKSRC}/@} ${DOCSDIR}
.endif
	@${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
