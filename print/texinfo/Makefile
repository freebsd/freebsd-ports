# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	texinfo
PORTVERSION=	6.3
PORTEPOCH=	1
CATEGORIES=	print
MASTER_SITES=	GNU \
		LOCAL/sunpoet/${DIST_SUBDIR}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} htmlxref.cnf texinfo.tex texi2dvi
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Typeset documentation system with multiple format output

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	help2man:misc/help2man

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install install-tex
MAKE_ARGS=	PERL=${PERL} TEXMF=${LOCALBASE}/${TEXMFDIR}
PKGDEINSTALL=	${PKGINSTALL}
USE_TEX=	yes
USES=		charsetfix cpe gmake iconv ncurses perl5 tar:xz

INFO=		info-stnd texinfo

CPE_VENDOR=	gnu
CPE_VERSION=	${PORTVERSION:R}

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

post-patch:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/texinfo.tex ${WRKSRC}/doc/
	@${INSTALL_SCRIPT} ${DISTDIR}/${DIST_SUBDIR}/texi2dvi ${WRKSRC}/util/
	@${REINPLACE_CMD} '/rm -f ..DESTDIR/s:$$: $$(DESTDIR)$$(xsdir)/XSParagraph.*:' \
		${WRKSRC}/tp/Texinfo/Convert/XSParagraph/Makefile.in

post-install:
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/htmlxref.cnf ${STAGEDIR}${DATADIR}
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}

.include <bsd.port.mk>
