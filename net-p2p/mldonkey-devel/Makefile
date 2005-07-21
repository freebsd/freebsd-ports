# New ports collection makefile for:	mldonkey
# Date created:		21 August 2002
# Whom:			Holger Lamm <holger@e-gitt.net>
#
# $FreeBSD$
#

PORTNAME=	mldonkey
PORTVERSION=	2.6.0
CATEGORIES+=	net
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${DOWNLOADVERSION}

PATCH_SITES=	http://download.berlios.de/pub/mldonkey/spiralvoice/patchpacks/
#PATCHFILES=	patch_pack${PORTVERSION:C/^.\..\.(.)/\1/:C/\.//}.gz

MAINTAINER?=	lioux@FreeBSD.org
COMMENT?=	A OCAML client for multiple peer-to-peer networks

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml

#DOWNLOADVERSION=${PORTVERSION:R}
DOWNLOADVERSION=${PORTVERSION}

NO_LATEST_LINK=	yes
CONFLICTS=	mldonkey-[0-9]* mldonkey-{core,gui}-[0.9]*

USE_BZIP2=	yes
USE_ICONV=	yes
WANT_AUTOCONF_VER=	259
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	opt

CONFIGURE_ARGS+=\
		--enable-ocamlver=3 \
		--with-libiconv-prefix=${LOCALBASE}
CONFIGURE_ENV+=	\
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

#WRKSRC=		${WRKDIR}/${PORTNAME}-${DOWNLOADVERSION}

###
## Options activation
###
.if defined(WITHOUT_GUI)
.if defined(WITHOUT_CORE)
.error "Cool, you defined both WITHOUT_GUI and WITHOUT_CORE. I think I'll do nothing."
.endif
# have no 'without-' flag
CONFIGURE_ARGS+=--disable-gui \
		--disable-gd
PLIST_SUB+=	CORE="" GUI="@comment " GUICORE="@comment "
PKGNAMESUFFIX=	-core-devel
.else
PLIST_SUB+=	GUI=""
BUILD_DEPENDS+=	lablgtk:${PORTSDIR}/x11-toolkits/ocaml-lablgtk \
		${LOCALBASE}/lib/ocaml/jabbr.cma:${PORTSDIR}/net/ocaml-jabbr
LIB_DEPENDS+=	gd.4:${PORTSDIR}/graphics/gd
# we don't need lablgtk as RUN dependency, but we need gtk+glib
USE_GNOME=	gtk12

MAKE_ENV+=	OCAMLRUNPARAM="l=256M"
.if defined(WITHOUT_CORE)
PKGNAMESUFFIX=	-gui-devel
PLIST_SUB+=	CORE="@comment " GUICORE="@comment "
.else
PLIST_SUB+=	CORE=""	GUICORE=""
.endif
.endif

DOCFILES=	Authors.txt Bugs.txt ChangeLog Developers.txt FAQ.html \
		Install.txt Readme.txt Todo.txt ed2k_links.txt
PORTDOCS=	${DOCFILES}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
BROKEN=		"Does not compile on ${ARCH}"
.endif

### Development version
## Thus, we will use non standard threading library
## We will switch from libpthread to libthr which should produce
## better results in some scenarios. You can read more at pthread(3)
.if defined(WITH_THR_THREAD_MODEL)
PTHREAD_CFLAGS=	-D_THREAD_SAFE
PTHREAD_LIBS=	-lthr
.endif

pre-everything::
.if !defined(WITHOUT_GUI) && !defined(WITHOUT_CORE)
	@${ECHO_MSG} "You can disable the GUI by defining WITHOUT_GUI."
	@${ECHO_MSG} "You can disable the CORE by defining WITHOUT_CORE."
	@${ECHO_MSG}
.endif
.ifndef(WITH_THR_THREAD_MODEL)
	@${ECHO_MSG} "Define WITH_THR_THREAD_MODEL to switch from"
	@${ECHO_MSG} "pthread to thr threading model which could produce better"
	@${ECHO_MSG} "results in some scenarios.  Use at your discretion."

.endif

post-patch:
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|" ${FILESDIR}/wrapper.sh > \
		${WRKDIR}/wrapper.sh
	@${REINPLACE_CMD} -E \
		-e 's|%%AUTOCONF%%|${AUTOCONF}|' \
		${BUILD_WRKSRC}/config/Makefile.in

pre-configure:
	cd ${WRKSRC}/config && ${AUTOCONF}

post-configure:
	@${REINPLACE_CMD} -E \
		-e 's|^(PTHREAD_CFLAGS[^=]*=).*$$|\1${PTHREAD_CFLAGS}|' \
		-e 's|^(PTHREAD_LIBS[^=]*=).*$$|\1${PTHREAD_LIBS}|' \
		${BUILD_WRKSRC}/config/Makefile.config

do-install:
.ifndef(WITHOUT_CORE)
	@${INSTALL_PROGRAM} ${WRKSRC}/mlnet		${PREFIX}/bin/mlnet-real
	@${INSTALL_SCRIPT} ${FILESDIR}/kill_mldonkey	${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh		${PREFIX}/bin/mlnet
.endif
.ifndef(WITHOUT_GUI)
	@${INSTALL_PROGRAM} ${WRKSRC}/mlchat		${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/mlgui		${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/mlim		${PREFIX}/bin
.endif
.ifndef(WITHOUT_CORE && WITHOUT_GUI)
	@${INSTALL_SCRIPT} ${WRKSRC}/distrib/mldonkey_previewer ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/mlguistarter	${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/mlnet+gui		${PREFIX}/bin
.endif
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/distrib/${file} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

install-user: extract
.if !defined(LANG)
	@${ECHO_MSG} "Please call as:  make install-user LANG=<lang>"
	@${ECHO_MSG} "with <lang> one of en,de,fr,fr.noaccents,sp !"
.else
	@${CP} ${WRKSRC}/distrib/i18n/gui_messages.ini.${LANG}\
		${HOME}/.mldonkey_gui_messages.ini
.endif

.include <bsd.port.post.mk>
