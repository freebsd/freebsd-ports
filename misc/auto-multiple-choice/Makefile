# $FreeBSD$

PORTNAME=	auto-multiple-choice
PORTVERSION=	1.2.1
PORTREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	http://download.gna.org/auto-qcm/
DISTNAME=	auto-multiple-choice_${PORTVERSION}_precomp

MAINTAINER=	hiroto.kagotani@gmail.com
COMMENT=	Multiple-choice questionnaire management with automated marking

LICENSE=	GPLv2

LIB_DEPENDS=	libnetpbm.so:${PORTSDIR}/graphics/netpbm \
		libopencv_highgui.so:${PORTSDIR}/graphics/opencv
RUN_DEPENDS=	p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-Email-MIME>=0:${PORTSDIR}/mail/p5-Email-MIME \
		p5-Email-Sender>=0:${PORTSDIR}/mail/p5-Email-Sender \
		p5-Gtk2-Notify>=0:${PORTSDIR}/devel/p5-Gtk2-Notify \
		p5-Locale-gettext>=0:${PORTSDIR}/devel/p5-Locale-gettext \
		p5-OpenOffice-OODoc>=0:${PORTSDIR}/textproc/p5-OpenOffice-OODoc \
		p5-Text-CSV>=0:${PORTSDIR}/textproc/p5-Text-CSV \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-XML-Writer>=0:${PORTSDIR}/textproc/p5-XML-Writer \
		pdftoppm:${PORTSDIR}/graphics/poppler-utils

WRKSRC=		${WRKDIR}/auto-multiple-choice-${PORTVERSION}
PORTDOCS=	html auto-multiple-choice.*
MANLANG=	"" fr ja

SHARED_MIMEINFO_DIR=	${PREFIX}/share/mime/packages
LANG_GTKSOURCEVIEW_DIR=	${PREFIX}/share/gtksourceview-2.0/language-specs
MAKE_JOBS_UNSAFE=	yes

USE_TEX=	latex texhash
USES+=		gettext gmake iconv:build perl5 shared-mime-info

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

pre-install:
	${MKDIR} ${STAGEDIR}/${SHARED_MIMEINFO_DIR} \
		${STAGEDIR}/${LANG_GTKSOURCEVIEW_DIR}

.include <bsd.port.mk>
