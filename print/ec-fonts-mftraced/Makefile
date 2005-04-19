# New ports collection makefile for:	ec-fonts-mftraced
# Date created:		Tue Apr 19 01:45:54 UTC 2005
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ec-fonts-mftraced
PORTVERSION=	1.0.12
CATEGORIES=	print
MASTER_SITES=	http://lilypond.org/download/fonts/

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	EC PostScript Type1 fonts with TFMs for TeX

BUILD_DEPENDS=	\
		mftrace:${PORTSDIR}/print/mftrace \
		potrace:${PORTSDIR}/graphics/potrace \
		updmap:${PORTSDIR}/print/teTeX-base

USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
MAKE_ARGS=	\
		prefix=${PREFIX} \
		builddir=${WRKDIR} \
		docdir=${PREFIX}/share/doc \
		sysconfdir=${PREFIX}/etc \
		TEXDIR=${PREFIX}/${TEXMFLOCALDIR} \
		TEXCONFDIR=${PREFIX}/${TEXMFLOCALDIR}
PKGDEINSTALL=	${PKGINSTALL}

PLIST_SUB=	TEXMFLOCALDIR="${TEXMFLOCALDIR}"
PORTDOCS=	\
		COPYING \
		ChangeLog \
		INSTALL \
		LICENSE \
		README

#
TEXMFLOCALDIR=	share/texmf-local

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} \
		${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|function[[:space:]]*||' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.if !exists(${LOCALBASE}/bin/potrace)
	@${REINPLACE_CMD} -E \
		-e 's|--potrace|--autotrace|' \
		${BUILD_WRKSRC}/${MAKEFILE}
.endif
	@${REINPLACE_CMD} -E \
		-e 's|^([[:space:]]*cp)|\1 -f|' \
		${BUILD_WRKSRC}/${MAKEFILE}
.ifdef(NOPORTDOCS)
	@${REINPLACE_CMD} -E \
		-e 's|^.*\(docdir\).*$$||' \
		${BUILD_WRKSRC}/${MAKEFILE}
.endif

.include <bsd.port.post.mk>
