# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	mutt
PORTVERSION=	1.4.2.3
PORTREVISION=	1
CATEGORIES+=	mail ipv6
MASTER_SITES=	ftp://ftp.mutt.org/mutt/ \
		ftp://ftp.fu-berlin.de/pub/unix/mail/mutt/ \
		ftp://ftp.demon.co.uk/pub/mirrors/mutt/

PATCHVERSION=	1.4.2.2
PATCH_SITES=	http://www.mutt.org.ua/download/mutt-${PATCHVERSION}/:vvv \
		http://www2.mutt.org.ua/download/mutt-${PATCHVERSION}/:vvv \
		http://www3.mutt.org.ua/download/mutt-${PATCHVERSION}/:vvv \
		ftp://ftp.mutt.org.ua/pub/mutt/mutt-${PATCHVERSION}/:vvv \
		ftp://ftp3.mutt.org.ua/pub/mutt/mutt-${PATCHVERSION}/:vvv
PATCHFILES=	patch-${PATCHVERSION}.rr.compressed.gz:vvv \
		patch-${PATCHVERSION}.vvv.initials.gz:vvv
PATCH_DIST_STRIP=	-p1

MAINTAINER?=	udo.schweigert@siemens.com
COMMENT?=	The Mongrel of Mailers (part Elm, Pine, Mush, mh, etc.)

CONFLICTS?=	ja-mutt-[0-9]* ja-mutt-devel-[0-9]* mutt-devel-[0-9]* mutt-devel-lite-[0-9]* mutt-lite-[0-9]* zh-mutt-devel-[0-9]* mutt-[^1].[^4]*
LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}14${PKGNAMESUFFIX}

OPTIONS_DEFINE=	NLS SGML_DOCS LOCALES_FIX MUTT_XFACE MUTT_FLOCK MUTT_ICONV GSSAPI
OPTIONS_DEFAULT=	MUTT_FLOCK MUTT_ICONV GSSAPI

OPTIONS_RADIO=		CONS
OPTIONS_RADIO_CONS=	SLANG NCURSES

.if defined(PACKAGE_BUILDING) && !defined (MUTT_LITE)
OPTIONS_DEFAULT+=	SLANG
.endif

CONS_DESC=	Console driver (if none chosen, uses ncurses from base system)
SLANG_DESC=	Adds display/screen management via S-Lang
NCURSES_DESC=	Adds console graphics support with ncurses from ports
SGML_DOCS_DESC=	Build mutt's SGML documentation
LOCALES_FIX_DESC=	Enable locales fixes
MUTT_XFACE_DESC=	Adds mutt X-Face support
MUTT_FLOCK_DESC=	Use flock() for file locks
MUTT_ICONV_DESC=	Enable mutt's iconv character conversion feature

USE_OPENSSL=	yes

.if defined (MUTT_LITE)
PKGNAMESUFFIX=	-lite
OPTIONS_EXCLUDE=	SGML_DOCS
.endif

.include <bsd.port.options.mk>

RUN_DEPENDS=	${LOCALBASE}/etc/mime.types:${PORTSDIR}/misc/mime-support
.if defined(PACKAGE_BUILDING) && !defined (MUTT_LITE)
WITH_SLANG=	yes
BUILD_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell
RUN_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell \
		urlview:${PORTSDIR}/textproc/urlview
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext iconv
.if ! ${PORT_OPTIONS:MMUTT_ICONV}
IGNORE=	the MUTT_ICONV options of the mutt port only be disabled if \
	NLS is also disabled
.endif
.elif ${PORT_OPTIONS:MMUTT_ICONV}
USES+=	iconv
.endif

.if ${PORT_OPTIONS:MSLANG}
LIB_DEPENDS+=	slang.2:${PORTSDIR}/devel/libslang2
.elif ${PORT_OPTIONS:MNCURSES}
USES+=	ncurses:port
.else
USES+=	ncurses
.endif
.if !defined (MUTT_LITE)
.if defined(WITH_MUTT_CYRUS_SASL)
IGNORE=	the SASL support for mutt has been withdrawn. Please use the mutt-devel port instead
.endif
.if ${PORT_OPTIONS:MSGML_DOCS}
BUILD_DEPENDS+=	sgmlfmt:${PORTSDIR}/textproc/sgmlformat
.endif
.if ${PORT_OPTIONS:MMUTT_XFACE}
PATCH_DEPENDS+=	${NONEXISTENT}:${PORTSDIR}/news/slrnface:extract
RUN_DEPENDS+=	slrnface:${PORTSDIR}/news/slrnface
.endif
.endif

DIST_SUBDIR=	mutt
WRKSRC=		${WRKDIR}/${DISTNAME:S/i$//}
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	automake autoconf
AUTOMAKE_ARGS=	--add-missing
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CC="${CC} -I${LOCALBASE}/include"
CONFIGURE_ARGS=	--enable-pop --enable-imap --disable-fcntl \
		--with-ssl=${OPENSSLBASE} --sysconfdir=${PREFIX}/etc \
		--with-sharedir=${PREFIX}/share/mutt \
		--with-docdir=${DOCSDIR} --with-charmaps \
		--enable-compressed
.if defined(MUTT_CONFIGURE_ARGS)
CONFIGURE_ARGS+=	${MUTT_CONFIGURE_ARGS}
.endif
.if ${PORT_OPTIONS:MMUTT_FLOCK}
CONFIGURE_ARGS+=	--enable-flock
.else
CONFIGURE_ARGS+=	--disable-flock
.endif
.if ${PORT_OPTIONS:MLOCALES_FIX}
CONFIGURE_ARGS+=	--enable-locales-fix
.endif
.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif
.if ! ${PORT_OPTIONS:MMUTT_ICONV} && ! ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=	--disable-iconv
.else
CONFIGURE_ARGS+=	--with-libiconv-prefix=${PREFIX}
.endif
.if ${PORT_OPTIONS:MSLANG}
CONFIGURE_ARGS+=	--with-slang=${PREFIX}
.elif ${PORT_OPTIONS:MNCURSES}
CONFIGURE_ARGS+=	--with-curses=${NCURSESBASE}
CFLAGS+=	-I${NCURSESINC}
.endif
.if ${PORT_OPTIONS:MGSSAPI}
.if exists(${LOCALBASE}/bin/gss-client)
LIB_DEPENDS+=		gssapi_krb5:${PORTSDIR}/security/krb5
CONFIGURE_ARGS+=	--with-gss=${LOCALBASE}
.elif (defined(MAKE_KERBEROS5)) || exists(/usr/lib/libkrb5.a)
CONFIGURE_ARGS+=	--with-gss
WITH_MUTT_KRB5_SYS=YES
.endif
.endif
MAN1=		mutt.1 mutt_dotlock.1
MAN5=		mbox.5 muttrc.5

post-patch::
	@${REINPLACE_CMD} -e 's,/usr/bin/gpg,${LOCALBASE}/bin/gpg,g' \
		${WRKSRC}/contrib/gpg.rc
	@${REINPLACE_CMD} -e 's,pgp6,pgp,g' \
		${WRKSRC}/contrib/pgp6.rc
	@${REINPLACE_CMD} -E -e 's|@samplesdir@|${EXAMPLESDIR}|g' \
		${WRKSRC}/contrib/Makefile.in

.if ${PORT_OPTIONS:MMUTT_XFACE}
post-patch::
	@${ECHO} "===>  Applying XFACE patch"
	slrnface_dir=`${FIND} ${PORTSDIR}/news/slrnface/work -type d \
			-name slrnface-\*`; \
	cd ${BUILD_WRKSRC}; ${PATCH} ${PATCH_ARGS} < $$slrnface_dir/mutt.patch
.endif

pre-configure::
	@(cd ${WRKSRC}; ${SETENV} ${AUTOMAKE_ENV} ${ACLOCAL} -I m4)
.if defined(WITH_MUTT_KRB5_SYS)
	@${ECHO_CMD} "#define HAVE_HEIMDAL" >> ${WRKSRC}/config.h.in
	@${REINPLACE_CMD} -e 's|<gssapi/gssapi\.h>|<gssapi.h>|' \
		${WRKSRC}/imap/auth_gss.c
.endif

# XXX
# this should be done automagically by aclocal but ....
# for now, this will have to do
pre-build:
	@${REINPLACE_CMD} -E -e "s|^(ACLOCAL = ).+|\1${ACLOCAL}|" \
			-e "s|^(AUTOCONF = ).+|\1${AUTOCONF}|" \
			-e "s|^(AUTOMAKE = ).+|\1${AUTOMAKE}|" \
			-e "s|^(AUTOHEADER = ).+|\1${AUTOHEADER}|" \
		${BUILD_WRKSRC}/Makefile

.if ${PORT_OPTIONS:MDOCS}
post-build:
	@${TOUCH} ${WRKSRC}/doc/mutt.man ${WRKSRC}/doc/manual.sgml
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-doc-ref
	@${REINPLACE_CMD} -E -e 's|\$$\{PREFIX\}|${PREFIX}|g' \
		-e 's|\$$\{DOCSDIR\}|${DOCSDIR}|g' \
		-e 's|\$$\{EXAMPLESDIR\}|${EXAMPLESDIR}|g' \
		${WRKSRC}/doc/mutt.man
	@${REINPLACE_CMD} -E -e 's|\$$\{PREFIX\}|${PREFIX}|g' \
		-e 's|\$$\{DOCSDIR\}|${DOCSDIR}|g' \
		-e 's|\$$\{EXAMPLESDIR\}|${EXAMPLESDIR}|g' \
		${WRKSRC}/doc/muttrc.man
.if ${PORT_OPTIONS:MSGML_DOCS}
PLIST:=		${WRKDIR}/PLIST
pre-install:
	@${CAT} ${PKGDIR}/pkg-plist.htmlfiles > ${PLIST}
	@${CAT} ${PKGDIR}/pkg-plist >> ${PLIST}
.endif
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/Muttrc ${PREFIX}/etc/Muttrc.dist
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO} "===>   Installing Mutt documentation"
	@${MKDIR} ${DOCSDIR} && ${CHMOD} a+rx ${DOCSDIR}
	@cd ${WRKSRC}/doc ; ${INSTALL_MAN} manual.txt PGP-Notes.txt \
		${DOCSDIR}
.if ${PORT_OPTIONS:MSGML_DOCS}
	${INSTALL} ${COPY} -o ${MANOWN} -g ${MANGRP} -m 0755 \
	    -d ${DOCSDIR}/html
	${INSTALL_MAN} ${WRKSRC}/doc/*.html ${DOCSDIR}/html
	${INSTALL_MAN} ${WRKSRC}/doc/*.latin1 ${DOCSDIR}
.endif
.endif

.if ${PORT_OPTIONS:MMUTT_XFACE}
	@${ECHO} ""
	@${ECHO} "************************************************************"
	@${ECHO} "  To enable the XFACE support in mutt you also have to add"
	@${ECHO} "        set xface=yes"
	@${ECHO} "  to your ~/.muttrc"
	@${ECHO} "  Additional information is provided by news/slrnface"
	@${ECHO} "************************************************************"
	@${ECHO} ""
.endif

.include <bsd.port.mk>
