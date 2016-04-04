# Created by: Michael Nottebrock <lofi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	foomatic-filters
PORTVERSION=	4.0.17
PORTREVISION=	7
CATEGORIES=	print
MASTER_SITES=	http://www.openprinting.org/download/foomatic/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Foomatic wrapper scripts

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdbus-1.so:devel/dbus

CONFLICTS=	cups-filters-[0-9]*

USES=		autoreconf ghostscript perl5 pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_A2PS=${LOCALBASE}/bin/a2ps \
		ac_cv_path_CUPS=${LOCALBASE}/libexec/cups \
		ac_cv_path_CUPS_FILTERS=${LOCALBASE}/libexec/cups/filter \
		ac_cv_path_CUPS_BACKENDS=${LOCALBASE}/libexec/cups/backend \
		ac_cv_path_ENSCRIPT=${LOCALBASE}/bin/enscript \
		ac_cv_path_MPAGE=${LOCALBASE}/bin/mpage \
		ac_cv_path_PERL=${LOCALBASE}/bin/perl \
		ac_cv_path_PPR=${LOCALBASE}/lib/ppr \
		ac_cv_path_PPR_INTERFACES=${LOCALBASE}/lib/ppr/interfaces \
		ac_cv_path_PPR_LIB=${LOCALBASE}/lib/ppr/lib \
		ac_cv_path_TEXTTOPS=${LOCALBASE}/libexec/cups/filter/texttops

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	A2PS CUPS_IMAGE MPAGE
OPTIONS_RADIO=	ENSCRIPT
OPTIONS_RADIO_ENSCRIPT=	ENSCRIPT_A4 ENSCRIPT_LETTER ENSCRIPT_LETTERDJ
OPTIONS_DEFAULT=	CUPS_IMAGE A2PS ENSCRIPT_A4 MPAGE
CUPS_IMAGE_DESC=	Install cups image utilities
A2PS_DESC=		Install a2ps convertor
ENSCRIPT_A4_DESC=	Install enscript convertor (A4)
ENSCRIPT_LETTER_DESC=	Install enscript convertor (letter)
ENSCRIPT_LETTERDJ_DESC=	Install enscript convertor (letterdj)
MPAGE_DESC=		Print multiple pages per sheet of paper

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCUPS_IMAGE}
RUN_DEPENDS+=	${LOCALBASE}/lib/libcupsimage.so:print/cups
.endif

.if ${PORT_OPTIONS:MA2PS}
RUN_DEPENDS+=	a2ps:print/a2ps
.endif

.if ${PORT_OPTIONS:MENSCRIPT_A4}
RUN_DEPENDS+=	enscript:print/enscript-a4
.endif

.if ${PORT_OPTIONS:MENSCRIPT_LETTER}
RUN_DEPENDS+=	enscript:print/enscript-letter
.endif

.if ${PORT_OPTIONS:MENSCRIPT_LETTERDJ}
RUN_DEPENDS+=	enscript:print/enscript-letterdj
.endif

.if ${PORT_OPTIONS:MMPAGE}
RUN_DEPENDS+=	mpage:print/mpage
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|${SH}|g' ${WRKSRC}/foomaticrip.c
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/foomaticrip.c
	@${REINPLACE_CMD} -e '/filter.conf/ s|if|#if|g' ${WRKSRC}/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/foomatic-rip

.include <bsd.port.mk>
