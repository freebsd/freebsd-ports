# Created by: Chuck Robey <chuckr@freebsd.org>
# $FreeBSD$

PORTNAME=	a2ps
PORTVERSION=	4.13b
PORTREVISION=	5
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GNU} \
		${MASTER_SITE_LOCAL:S/$/:i18n/}
MASTER_SITE_SUBDIR=	${PORTNAME} hrs/a2ps/:i18n

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Formats an ASCII file for printing on a postscript printer

LICENSE=	GPLv2

LIB_DEPENDS=	paper:${PORTSDIR}/print/libpaper

USES=		perl5
USE_CSTD=	gnu89
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAN1=		a2ps.1 ogonkify.1 card.1 psmandup.1 fixps.1 pdiff.1 psset.1 \
		texi2dvi4a2ps.1
INFO=		a2ps ogonkify regex
WRKSRC=		${WRKDIR}/${PORTNAME}-4.13
I18N_PACKAGE=	i18n-fonts-0.1
PORTSCOUT=	skipv:4.14

STRIP=
CONFIGURE_ARGS=	--with-medium=libpaper --sharedstatedir=${PREFIX}/share \
	--sysconfdir=${PREFIX}/etc --datadir=${PREFIX}/share \
	--localstatedir=${PREFIX}/share
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"

PAPERSIZE?=
.if ${PAPERSIZE:L} == a4
RUN_DEPENDS+=	${LOCALBASE}/etc/papersize:${PORTSDIR}/print/papersize-default-a4
.endif

OPTIONS_DEFINE=NLS I18N EMACS
OPTIONS_DEFAULT=NLS
NO_OPTIONS_SORT=yes
EMACS_DESC=Enable Emacs support
I18N_DESC=Enable I18N support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MEMACS}
USE_EMACS=	yes
CONFIGURE_ARGS+=	--with-lispdir=${LOCALBASE}/${EMACS_SITE_LISPDIR}
PLIST_SUB+=	WITHEMACS=""
.else
CONFIGURE_ENV+=	EMACS=no
PLIST_SUB+=	WITHEMACS="@comment "
.endif

.if ${PORT_OPTIONS:MI18N}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${I18N_PACKAGE}${EXTRACT_SUFX}:i18n
PLIST_SUB+=	WITHI18N=""

pre-configure:
	cd ${WRKDIR}/${I18N_PACKAGE}/afm && \
		${ECHO_CMD} *.afm > afms.lst && \
		${MV} *.afm ${WRKSRC}/afm
	cd ${WRKDIR}/${I18N_PACKAGE}/fonts && \
		${MV} *.pfb ${WRKSRC}/fonts

post-configure:
	@cd ${WRKSRC}/fonts && { ${ECHO_CMD} ''; \
	${ECHO_CMD} "pfb_fonts =" *.pfb; } >> Makefile && \
	${REINPLACE_CMD} 's,^\(fonts_DATA = .*\),\1 $$(pfb_fonts),' Makefile
	@cd ${WRKSRC}/afm && { ${ECHO} ''; \
	${ECHO} "i18n_afms =" `cat ${WRKDIR}/${I18N_PACKAGE}/afm/afms.lst`; } >> Makefile && \
	${REINPLACE_CMD} 's,^\(all_afms = .*\),\1 $$(i18n_afms),' Makefile
.else
PLIST_SUB+=	WITHI18N="@comment "
.endif

post-install:
	${STRIP_CMD} ${PREFIX}/bin/a2ps
.if ${PORT_OPTIONS:MEMACS}
	${MKDIR} ${PREFIX}/lib/xemacs/site-lisp
	${LN} -sf ${PREFIX}/share/emacs/site-lisp/a2ps-print.el \
		  ${PREFIX}/lib/xemacs/site-lisp/a2ps-print.el
	${LN} -sf ${PREFIX}/share/emacs/site-lisp/a2ps.el \
		  ${PREFIX}/lib/xemacs/site-lisp/a2ps.el
.endif
	cd ${WRKSRC}/doc && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${.MAKEFLAGS} ${INSTALL_TARGET}
	${RM} -f ${PREFIX}/lib/liba2ps.la

.include <bsd.port.mk>
