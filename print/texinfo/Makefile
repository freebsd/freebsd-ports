# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	texinfo
PORTVERSION=	6.5
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	print
MASTER_SITES=	GNU \
		LOCAL/sunpoet/${DIST_SUBDIR}:DEFAULT,local
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} htmlxref.cnf:local texi2dvi:local texinfo.tex:local
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Typeset documentation system with multiple format output

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	help2man:misc/help2man \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-Locale-libintl>=0:devel/p5-Locale-libintl \
		p5-Text-Unidecode>=0:converters/p5-Text-Unidecode \
		p5-Unicode-EastAsianWidth>=0:textproc/p5-Unicode-EastAsianWidth

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

USES=		charsetfix cpe gmake iconv libtool ncurses perl5 tar:xz

CONFIGURE_ARGS=	--with-external-libintl-perl \
		--with-external-Text-Unidecode \
		--with-external-Unicode-EastAsianWidth
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip install-tex
MAKE_ARGS=	PERL=${PERL} TEXMF=${LOCALBASE}/${TEXMFDIR}
PKGDEINSTALL=	${PKGINSTALL}
USE_TEX=	yes

INFO=		info-stnd texinfo

CPE_VENDOR=	gnu
CPE_VERSION=	${PORTVERSION:R}

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

post-patch:
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/texinfo.tex ${WRKSRC}/doc/
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/htmlxref.cnf ${WRKSRC}/util/
	@${INSTALL_SCRIPT} ${DISTDIR}/${DIST_SUBDIR}/texi2dvi ${WRKSRC}/util/
	@${REINPLACE_CMD} -e '/rm -f $$(DESTDIR)/ s|$$| $$(DESTDIR)$$(xsdir)/XSParagraph.*|' \
		${WRKSRC}/tp/Texinfo/Convert/XSParagraph/Makefile.in
	@${REINPLACE_CMD} -e 's|free (.*)|Safe&|' ${WRKSRC}/tp/Texinfo/MiscXS/misc.c

post-install:
	${INSTALL_DATA} ${WRKSRC}/util/htmlxref.cnf ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
