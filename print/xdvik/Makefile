# New ports collection makefile for:   xdvik
# Date created:        26 Feb 1998
# Whom:                Kentaro Inagaki <JBD01226@niftyserve.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	xdvik
PORTVERSION=	22.78
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xdvi

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	DVI Previewer(kpathsearch) for X

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX
RUN_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX
LIB_DEPENDS=	t1.5:${PORTSDIR}/devel/t1lib

USE_XLIB=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-system-t1lib --with-t1lib-libdir=${LIBT1_PREFIX}/lib \
		--with-t1lib-include=${LIBT1_PREFIX}/include
CONFIGURE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"

PLIST_SUB=	TEXMFDIR=${TEXMFDIR} MKTEXLSR=${MKTEXLSR}
CONFLICTS=	xdvi-* *-xdvi*

MAN1=		xdvi.1 t1mapper.1 xdvizilla.1

TEXMFDIR?=	share/texmf
MKTEXLSR?=	${LOCALBASE}/bin/mktexlsr
LIBT1_PREFIX?=	${LOCALBASE}
DOC_FILES=	BUGS CHANGES INSTALL \
		README README.CVS README_maintainer TODO

do-install:
	cd ${WRKSRC}/texk/xdvik && \
		${MAKE_ENV} ${MAKE} ${INSTALL_TARGET}

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/texk/xdvik/t1mapper ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES:S@^@${WRKSRC}/@} ${DOCSDIR}
.endif
	${MKTEXLSR}

.include <bsd.port.mk>
