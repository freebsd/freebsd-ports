# New ports collection makefile for:	latest texinfo
# Date created:		Sun May 29 17:32:08 UTC 2005
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	texinfo
PORTVERSION=	4.13.20110529
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GNU} \
		ftp://ftp.stack.nl/pub/users/johans/texinfo/${PORTVERSION:E}/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:R}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} texinfo.tex texi2dvi
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	A typeset documentation system with multiple format output

BUILD_DEPENDS+=	help2man:${PORTSDIR}/misc/help2man

CONFLICTS_INSTALL=teTeX-base-[0-9]*

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALL_TARGET=	install install-tex
PKGDEINSTALL=	${PKGINSTALL}
MAKE_JOBS_SAFE=	yes

MAKE_ARGS=	TEXMF=${PREFIX}/${TEXMFLOCAL}
CONFIGURE_ARGS=	--without-included-gettext
CPPFLAGS=	-I${LOCALBASE}/lib
LDFLAGS=	-L${LOCALBASE}/lib -lintl

INFO=		${PORTNAME} info-stnd info
MAN1=		info.1 infokey.1 install-info.1 makeinfo.1 texi2dvi.1 \
		texi2pdf.1 pdftexi2dvi.1 texindex.1
MAN5=		info.5 texinfo.5

PLIST_SUB=	TEXMFLOCAL=${TEXMFLOCAL}

TEXMFLOCAL=	share/texmf-local

.include <bsd.port.pre.mk>

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-patch:
	${CHMOD} 755 ${WRKSRC}/build-aux/install-sh
	${CP} ${DISTDIR}/texinfo.tex ${WRKSRC}/doc/
	${CP} ${DISTDIR}/texi2dvi ${WRKSRC}/util/

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} LOCALBASE=${LOCALBASE} ${SH} \
		${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
