# $FreeBSD$

PORTNAME=	auto-multiple-choice
PORTVERSION=	1.3.0
PORTREVISION=	16
CATEGORIES=	misc
MASTER_SITES=	http://download.gna.org/auto-qcm/
DISTNAME=	auto-multiple-choice_${PORTVERSION}_precomp

MAINTAINER=	hiroto.kagotani@gmail.com
COMMENT=	Multiple-choice questionnaire management with automated marking

BROKEN=		unfetchable

LICENSE=	GPLv2

LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libnetpbm.so:graphics/netpbm \
		libopencv_highgui.so:graphics/opencv \
		libpangocairo-1.0.so:x11-toolkits/pango \
		libpoppler-glib.so:graphics/poppler-glib
RUN_DEPENDS=	p5-DBD-SQLite>=0:databases/p5-DBD-SQLite \
		p5-DBI>=0:databases/p5-DBI \
		p5-Email-MIME>=0:mail/p5-Email-MIME \
		p5-Email-Sender>=0:mail/p5-Email-Sender \
		p5-Glib-Object-Introspection>=0:devel/p5-Glib-Object-Introspection \
		p5-Gtk2-Notify>=0:devel/p5-Gtk2-Notify \
		p5-Locale-gettext>=0:devel/p5-Locale-gettext \
		p5-Module-Pluggable>=0:devel/p5-Module-Pluggable \
		p5-Net-CUPS>=0:print/p5-Net-CUPS \
		p5-OpenOffice-OODoc>=0:textproc/p5-OpenOffice-OODoc \
		p5-Text-CSV>=0:textproc/p5-Text-CSV \
		p5-XML-Simple>=0:textproc/p5-XML-Simple \
		p5-XML-Writer>=0:textproc/p5-XML-Writer \
		pdftoppm:graphics/poppler-utils

WRKSRC=		${WRKDIR}/auto-multiple-choice-${PORTVERSION}
PORTDOCS=	html auto-multiple-choice.*
MANLANG=	"" fr ja

SHARED_MIMEINFO_DIR=	${PREFIX}/share/mime/packages
LANG_GTKSOURCEVIEW_DIR=	${PREFIX}/share/gtksourceview-2.0/language-specs

USES+=		compiler:c++11-lang gettext gmake iconv:build perl5 \
		pkgconfig shared-mime-info
USE_TEX=	latex texhash

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "\
		s|%%DATADIR%%|${DATADIR}|g; \
		s|%%DOCSDIR%%|${DOCSDIR}|g; \
		s|%%LANG_GTKSOURCEVIEW_DIR%%|${LANG_GTKSOURCEVIEW_DIR}|g; \
		s|%%LOCALBASE%%|${LOCALBASE}|g; \
		s|%%MANPREFIX%%|${MANPREFIX}|g; \
		s|%%PREFIX%%|${PREFIX}|g; \
		s|%%SHARED_MIMEINFO_DIR%%|${SHARED_MIMEINFO_DIR}|g; \
		s|%%SITE_PERL_REL%%|${SITE_PERL_REL}|g; \
		s|%%TEXMFLOCALDIR%%|${TEXMFLOCALDIR}|g; \
		" ${WRKSRC}/Makefile.conf
	@${REINPLACE_CMD} -e "s|^#! /usr/bin/perl|#!${LOCALBASE}/bin/perl|" \
		${WRKSRC}/*.pl ${WRKSRC}/*.pl.in
	@${REINPLACE_CMD} -e "s|^#! @/PERLPATH/@|#!${LOCALBASE}/bin/perl|" \
		${WRKSRC}/auto-multiple-choice.in
	@${RM} ${WRKSRC}/vars-subs.pl

pre-install:
	${MKDIR} ${STAGEDIR}/${SHARED_MIMEINFO_DIR} \
		${STAGEDIR}/${LANG_GTKSOURCEVIEW_DIR}

.include <bsd.port.mk>
