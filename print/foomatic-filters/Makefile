# New ports collection makefile for:	foomatic-rip
# Date created:		2005-01-28
# Whom:			Michael Nottebrock <lofi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	foomatic-filters
PORTVERSION=	4.0.1
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://www.linuxprinting.org/download/foomatic/ \
		http://www.openprinting.org/download/foomatic/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Foomatic wrapper scripts

USE_AUTOTOOLS=	autoheader:262
USE_PERL5=	yes
USE_GHOSTSCRIPT=yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_A2PS=${LOCALBASE}/bin/a2ps \
		ac_cv_path_CUPS=${LOCALBASE}/libexec/cups \
		ac_cv_path_CUPS_FILTERS=${LOCALBASE}/libexec/cups/filter \
		ac_cv_path_CUPS_BACKENDS=${LOCALBASE}/libexec/cups/backend \
		ac_cv_path_ENSCRIPT=${LOCALBASE}/bin/enscript \
		ac_cv_path_MPAGE=${LOCALBASE}/bin/mpage \
		ac_cv_path_PPR=${LOCALBASE}/lib/ppr \
		ac_cv_path_PPR_INTERFACES=${LOCALBASE}/lib/ppr/interfaces \
		ac_cv_path_PPR_LIB=${LOCALBASE}/lib/ppr/lib \
		ac_cv_path_TEXTTOPS=${LOCALBASE}/libexec/cups/filter/texttops \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	CUPS_IMAGE	"Install cups image utilities"	on \
		A2PS_A4	"Install a2ps convertor (A4)"	on \
		A2PS_LETTER	"Install a2ps convertor (letter)"	off \
		A2PS_LETTERDJ	"Install a2ps convertor (letterdj)"	off \
		ENSCRIPT_A4 "Install enscript convertor (A4)"	on \
		ENSCRIPT_LETTER "Install enscript convertor (letter)"	off \
		ENSCRIPT_LETTERDJ "Install enscript convertor (letterdj)"	off \
		MPAGE	"Print multiple pages per sheet of paper"	on

MAN1=		foomatic-rip.1

.include <bsd.port.pre.mk>

.if defined(WITH_CUPS_IMAGE)
RUN_DEPENDS+=	${LOCALBASE}/lib/libcupsimage.so:${PORTSDIR}/print/cups-image
.endif

.if defined(WITH_A2PS_A4)
.	if defined(WITH_A2PS_LETTER) || defined(WITH_A2PS_LETTERDJ)
IGNORE=		Please select only one a2ps convertor
.	else
RUN_DEPENDS+=	a2ps:${PORTSDIR}/print/a2ps-a4
.	endif
.endif

.if defined(WITH_A2PS_LETTER) 
.	if defined(WITH_A2PS_A4) || defined(WITH_A2PS_LETTERDJ)
IGNORE=		Please select only one a2ps convertor
.	else
RUN_DEPENDS+=	a2ps:${PORTSDIR}/print/a2ps-letter
.	endif
.endif

.if defined(WITH_A2PS-LETTERDJ)
.	if defined(WITH_A2PS-A4) || defined(WITH_A2PS_LETTER)
IGNORE=		Please select only one a2ps convertor
.	else
RUN_DEPENDS+=	a2ps:${PORTSDIR}/print/a2ps-letterdj
.	endif
.endif

.if defined(WITH_ENSCRIPT_A4)
.	if defined(WITH_ENSCRIPT_LETTER) || defined(WITH_ENSCRIPT_LETTERDJ)
IGNORE=		Please select only one enscript convertor
.	else
RUN_DEPENDS+=	enscript:${PORTSDIR}/print/enscript-a4
.	endif
.endif

.if defined(WITH_ENSCRIPT_LETTER)
.	if defined(WITH_ENSCRIPT_A4) || defined(WITH_ENSCRIPT_LETTERDJ)
IGNORE=		Please select only one enscript convertor
.	else
RUN_DEPENDS+=	enscript:${PORTSDIR}/print/enscript-letter
.	endif
.endif

.if defined(WITH_ENSCRIPT_LETTERDJ)
.	if defined(WITH_ENSCRIPT_A4) || defined(WITH_ENSCRIPT_LETTER)
IGNORE=		Please just select only one enscript convertor
.	else
RUN_DEPENDS+=	enscript:${PORTSDIR}/print/enscript-letterdj
.	endif
.endif

.if defined(WITH_MPAGE)
RUN_DEPENDS+=	mpage:${PORTSDIR}/print/mpage
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|${SH}|g' ${WRKSRC}/foomaticrip.c

.include <bsd.port.post.mk>
