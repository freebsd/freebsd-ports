# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	texinfo
PORTVERSION=	6.7
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	print
MASTER_SITES=	GNU \
		LOCAL/sunpoet/texinfo:DEFAULT,local
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		htmlxref.cnf-${HTMLXREF_CNF_RELDATE}:local \
		texi2dvi-${TEXI2DVI_RELDATE}:local \
		texinfo.tex-${TEXINFO_TEX_RELDATE}:local
DIST_SUBDIR=	texinfo
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

HTMLXREF_CNF_RELDATE=	20190611
TEXI2DVI_RELDATE=	20191018
TEXINFO_TEX_RELDATE=	20190924

CPE_VENDOR=	gnu
CPE_VERSION=	${PORTVERSION:R}

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

post-patch:
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/texinfo.tex-${TEXINFO_TEX_RELDATE} ${WRKSRC}/doc/texinfo.tex
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/htmlxref.cnf-${HTMLXREF_CNF_RELDATE} ${WRKSRC}/util/htmlxref.cnf
	@${INSTALL_SCRIPT} ${DISTDIR}/${DIST_SUBDIR}/texi2dvi-${TEXI2DVI_RELDATE} ${WRKSRC}/util/texi2dvi
	@${REINPLACE_CMD} -e '/rm -f $$(DESTDIR)/ s|$$| $$(DESTDIR)$$(xsdir)/XSParagraph.*|' ${WRKSRC}/tp/Texinfo/XS/Makefile.in
	@${REINPLACE_CMD} -e 's|free (.*)|Safe&|' ${WRKSRC}/tp/Texinfo/XS/misc.c
	@${REINPLACE_CMD} -e 's/tinfo/tinfow/g' ${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${WRKSRC}/util/htmlxref.cnf ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
