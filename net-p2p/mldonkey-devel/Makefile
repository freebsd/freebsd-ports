# New ports collection makefile for:	mldonkey
# Date created:		21 August 2002
# Whom:			Holger Lamm <holger@e-gitt.net>
#
# $FreeBSD$
#

PORTNAME=	mldonkey
PORTVERSION=	2.7.5
PORTREVISION=	2
CATEGORIES+=	net-p2p
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED} \
		${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-devel

MAINTAINER?=	lioux@FreeBSD.org
COMMENT?=	A OCAML client for multiple peer-to-peer networks

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml

NO_LATEST_LINK=	yes
CONFLICTS=	mldonkey-[0-9]*

USE_BZIP2=	yes
USE_ICONV=	yes
USE_RC_SUBR=	mlnet
USE_AUTOTOOLS=	autoconf:259:env
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	opt

CONFIGURE_ARGS+=\
		--enable-ocamlver=3 \
		--with-libiconv-prefix=${LOCALBASE}
CONFIGURE_ENV+=	\
		NEWCXX="${CXX}" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

###
## Library dependency handling
###
.if !exists(/usr/lib/libbz2.so)
LIB_DEPENDS+=	bz2:${PORTSDIR}/archivers/bzip2
.endif

###
## Options activation
###
.if defined(WITHOUT_GUI)
.if defined(WITHOUT_CORE)
IGNORE=	cannot install: you defined both WITHOUT_GUI and WITHOUT_CORE. I think I'll do nothing
.endif
# have no 'without-' flag
CONFIGURE_ARGS+=--disable-gui \
		--disable-gd
PLIST_SUB+=	CORE="" GUI="@comment " GUICORE="@comment "
CONFLICTS+=	mldonkey-core-[0.9]* mldonkey-core-stable-[0.9]* \
		mldonkey-devel-[0-9]*
PKGNAMESUFFIX=	-core-devel
.else
PLIST_SUB+=	GUI=""
CONFLICTS+=	mldonkey-gui-[0.9]*
.if !defined(WITHOUT_CORE)
CONFLICTS+=	mldonkey-devel-[0-9]*
.endif
BUILD_DEPENDS+=	lablgtk2:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2 \
		${LOCALBASE}/lib/ocaml/jabbr.cma:${PORTSDIR}/net-im/ocaml-jabbr
LIB_DEPENDS+=	gd.4:${PORTSDIR}/graphics/gd \
		rsvg-2.2:${PORTSDIR}/graphics/librsvg2

CONFIGURE_ARGS+=--enable-gui=newgui2
# we don't need lablgtk as RUN dependency, but we need gtk+glib
USE_GNOME=	gtk20

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
PKGMESSAGE=	${WRKDIR}/pkg-message

# build additional tools
ALL_TARGET+=	\
		mld_hash

.include <bsd.port.pre.mk>

# Fix build on 4.x
.if ${OSVERSION} < 500000
USE_GCC=	3.4
.endif

# FreeBSD has reentrant dns code
.if ( ((${OSVERSION} >= 504102) && (${OSVERSION} < 600000)) || (${OSVERSION} >= 600029) )
PTHREAD_CFLAGS+=	-D_REENTRANT
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
# update server.met provider
.for file in \
	src/daemon/common/commonOptions.ml \
	src/networks/donkey/donkeyServers.ml
	@${REINPLACE_CMD} -E \
		-e 's|http://www.gruk.org/server.met.gz|http://www.jd2k.com/server.met|' \
		${WRKSRC}/${file}
.endfor

pre-configure:
	@cd ${WRKSRC}/config && ${AUTOCONF}

post-configure:
	@${REINPLACE_CMD} -E \
		-e 's|^(PTHREAD_CFLAGS[^=]*=).*$$|\1${PTHREAD_CFLAGS}|' \
		-e 's|^(PTHREAD_LIBS[^=]*=).*$$|\1${PTHREAD_LIBS}|' \
		${BUILD_WRKSRC}/config/Makefile.config

pre-install:
.if exists(${.CURDIR}/pkg-message)
	@${SED} -e 's,%%DOCSDIR%%,${DOCSDIR},' \
		< ${.CURDIR}/pkg-message > ${PKGMESSAGE}
.elif exists(${MASTERDIR}/pkg-message)
	@${SED} -e 's,%%DOCSDIR%%,${DOCSDIR},' \
		< ${MASTERDIR}/pkg-message > ${PKGMESSAGE}
.endif

do-install:
.ifndef(WITHOUT_CORE)
	@${INSTALL_PROGRAM} ${WRKSRC}/mld_hash		${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/mlnet		${PREFIX}/bin/mlnet-real
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh		${PREFIX}/bin/mlnet
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_SCRIPT} ${FILESDIR}/kill_mldonkey	${EXAMPLESDIR}
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
