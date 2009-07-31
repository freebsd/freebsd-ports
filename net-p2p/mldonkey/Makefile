# New ports collection makefile for:	mldonkey
# Date created:		21 August 2002
# Whom:			Holger Lamm <holger@e-gitt.net>
#
# $FreeBSD$
#

PORTNAME=	mldonkey
PORTVERSION=	3.0.0
PORTREVISION=	1
CATEGORIES+=	net-p2p
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED} \
		${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER?=	lioux@FreeBSD.org
COMMENT?=	A OCAML client for multiple peer-to-peer networks

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml

NO_LATEST_LINK=	yes
CONFLICTS=	mldonkey{-{core,gui},}-devel-[0-9]*

USE_BZIP2=	yes
USE_ICONV=	yes
USE_AUTOTOOLS=	autoconf:262:env
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	opt
MAKE_ENV+=	OCAMLRUNPARAM="l=256M"
MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ARGS+=\
		--enable-ocamlver=3 \
		--with-libiconv-prefix=${LOCALBASE}
CONFIGURE_ENV+=	\
		NEWCXX="${CXX}" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
# FreeBSD has reentrant dns code
PTHREAD_CFLAGS+=	-D_REENTRANT

###
## Library dependency handling
###
.if !exists(/usr/lib/libbz2.so)
LIB_DEPENDS+=	bz2:${PORTSDIR}/archivers/bzip2
.endif

###
## Options activation
###
.if defined(WITHOUT_GUI) && defined(WITHOUT_CORE)
IGNORE=	cannot install: you defined both WITHOUT_GUI and WITHOUT_CORE. I think I'll do nothing
.endif

.if !(defined(WITHOUT_GUI) || defined(WITHOUT_CORE))
CONFLICTS+=	mldonkey-core-[0.9]*
CONFLICTS+=	mldonkey-gui-[0.9]*

PLIST_SUB+=	CORE="" GUI="" GUICORE=""
.else # (defined(WITHOUT_GUI) || defined(WITHOUT_CORE))

. if defined(WITHOUT_GUI)
PKGNAMESUFFIX=	-core

CONFLICTS+=	mldonkey-gui-[0.9]*

CONFIGURE_ARGS+=--disable-gui
PLIST_SUB+=	CORE="" GUI="@comment " GUICORE="@comment "
. endif # defined(WITHOUT_GUI)

. if defined(WITHOUT_CORE)
PKGNAMESUFFIX=	-gui

CONFLICTS+=	mldonkey-core-[0.9]*

PLIST_SUB+=	CORE="@comment " GUI="" GUICORE="@comment "
. endif # defined(WITHOUT_CORE)

.endif # !(defined(WITHOUT_GUI) || defined(WITHOUT_CORE))

.if !defined(WITHOUT_GUI)
BUILD_DEPENDS+=	${LOCALBASE}/lib/ocaml/lablgtk2/lablrsvg.cma:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2
LIB_DEPENDS+=	rsvg-2.2:${PORTSDIR}/graphics/librsvg2

CONFIGURE_ARGS+=--enable-gui=newgui2
# we don't need lablgtk as RUN dependency, but we need gtk+glib
USE_GNOME=	gtk20
.endif # !defined(WITHOUT_GUI)

.if !defined(WITHOUT_CORE)
USE_RC_SUBR=	mlnet
SUB_LIST+=	SH=${SH:Q}

. if !defined(WITHOUT_GD)
LIB_DEPENDS+=	gd.4:${PORTSDIR}/graphics/gd
. else
CONFIGURE_ARGS+=--disable-gd
. endif
.endif

DOCFILES=	Authors.txt Bugs.txt ChangeLog Developers.txt \
		Install.txt Todo.txt ed2k_links.txt
PORTDOCS=	${DOCFILES}
PKGMESSAGE=	${WRKDIR}/pkg-message

# build additional tools
ALL_TARGET+=	\
		mld_hash

.include <bsd.port.pre.mk>

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
	@${SED} \
		-e "s|%%PREFIX%%|${PREFIX}|" \
		-e "s|%%SH%%|${SH}|" \
		${FILESDIR}/wrapper.sh > \
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
		-e 's|http://www.bluetack.co.uk/config/antip2p.txt|http://www.bluetack.co.uk/config/level1.gz|' \
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
	@${INSTALL_PROGRAM} ${WRKSRC}/mlgui		${PREFIX}/bin
.endif
.ifndef(WITHOUT_CORE && WITHOUT_GUI)
	@${INSTALL_SCRIPT} ${WRKSRC}/distrib/mldonkey_previewer ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/mlguistarter	${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/mlnet+gui		${PREFIX}/bin
.endif
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for _file in ${DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/distrib/${_file} ${DOCSDIR}
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
