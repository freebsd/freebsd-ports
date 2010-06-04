# New ports collection makefile for:    a2ps (letter)
# Date created:         15 July 1998
# Whom:                 Chuck Robey (chuckr@freebsd.org)
#
# $FreeBSD$
#

PORTNAME=	a2ps
PORTVERSION=	4.13b
PORTREVISION=	4
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.enst.fr/pub/unix/a2ps/ \
		ftp://ftp3.ru.freebsd.org/pub/unix/postscript/a2ps/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-${PAPERSIZE}${PKGNAMESUFFIX2}
.if defined(WITH_I18N) || make(makesum) || defined(FETCH_ALL)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${I18N_PACKAGE}${EXTRACT_SUFX}
.endif

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Formats an ascii file for printing on a postscript printer

LICENSE=	GPLv2

USE_PERL5=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAN1=		a2ps.1 ogonkify.1 card.1 psmandup.1 fixps.1 pdiff.1 psset.1 texi2dvi4a2ps.1
INFO=		a2ps ogonkify regex
WRKSRC=		${WRKDIR}/${PORTNAME}-4.13
I18N_PACKAGE=	i18n-fonts-0.1
PORTSCOUT=	skipv:4.14

PAPERSIZE?=	letter
PAPERSIZECNF=	${PAPERSIZE:S/l/L/:S/a/A/}
STRIP=
CONFIGURE_ARGS=	--with-medium=${PAPERSIZECNF} --sharedstatedir=${PREFIX}/share --sysconfdir=${PREFIX}/etc --datadir=${PREFIX}/share --localstatedir=${PREFIX}/share

.if ${PAPERSIZE} != a4 && ${PAPERSIZE} != letter && ${PAPERSIZE} != letterdj
.BEGIN:
	@${ECHO_CMD}
	@${ECHO_CMD} "PAPERSIZE incorrect value: ${PAPERSIZE}."
	@${ECHO_CMD}
	@${ECHO_CMD} "Must specify PAPERSIZE as one of a4, letter, or letterdj."
	@${ECHO_CMD} "letterdj allows a slightly larger margins for DeskJets."
	@${FALSE}
.endif

.if ${PAPERSIZE} == a4
CONFLICTS?=	a2ps-letter-4.* a2ps-letterdj-4.*
.else
.if ${PAPERSIZE} == letter
CONFLICTS?=	a2ps-a4-4.* a2ps-letterdj-4.*
.else
CONFLICTS?=	a2ps-a4-4.* a2ps-letter-4.*
.endif
.endif

.if defined(WITH_EMACS)
PLIST_SUB+=	WITHEMACS=""
.else
PLIST_SUB+=	WITHEMACS="@comment "
.endif

.if defined(WITH_I18N)
PLIST_SUB+=	WITHI18N=""

pre-configure:
	@cd ${WRKDIR}/${I18N_PACKAGE}/afm && ${ECHO} *.afm > afms.lst && \
	${MV} *.afm ${WRKSRC}/afm && cd ../fonts && \
	${MV} *.pfb ${WRKSRC}/fonts

post-configure:
	@cd ${WRKSRC}/fonts && { ${ECHO} ''; \
	${ECHO} "pfb_fonts =" *.pfb; } >> Makefile && \
	${REINPLACE_CMD} 's,^\(fonts_DATA = .*\),\1 $$(pfb_fonts),' Makefile
	@cd ${WRKSRC}/afm && { ${ECHO} ''; \
	${ECHO} "i18n_afms =" `cat ${WRKDIR}/${I18N_PACKAGE}/afm/afms.lst`; } >> Makefile && \
	${REINPLACE_CMD} 's,^\(all_afms = .*\),\1 $$(i18n_afms),' Makefile
.else
PLIST_SUB+=	WITHI18N="@comment "
.endif

post-install:
	${STRIP_CMD} ${PREFIX}/bin/a2ps
.if defined(WITH_EMACS)
	${MKDIR} ${PREFIX}/lib/xemacs/site-lisp
	${LN} -sf ${PREFIX}/share/emacs/site-lisp/a2ps-print.el \
		  ${PREFIX}/lib/xemacs/site-lisp/a2ps-print.el
	${LN} -sf ${PREFIX}/share/emacs/site-lisp/a2ps.el \
		  ${PREFIX}/lib/xemacs/site-lisp/a2ps.el
.endif
	(cd ${WRKSRC}/doc; ${MAKE} install)
	${RM} -f ${PREFIX}/lib/liba2ps.la

.include <bsd.port.mk>
