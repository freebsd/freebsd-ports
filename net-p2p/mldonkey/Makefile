# Created by: Holger Lamm <holger@e-gitt.net>
# $FreeBSD$

PORTNAME=	mldonkey
PORTVERSION=	3.1.3
PORTREVISION=	1
CATEGORIES+=	net-p2p
MASTER_SITES=	SF

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	A OCAML client for multiple peer-to-peer networks

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/Copying.txt

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml

NO_LATEST_LINK=	yes
CONFLICTS=	mldonkey{-{core,gui},}-devel-[0-9]*

USES=		iconv tar:bzip2 gmake
USE_AUTOTOOLS=	autoconf:env
GNU_CONFIGURE=	yes
ALL_TARGET=	opt
MAKE_ENV+=	OCAMLRUNPARAM="l=256M"
MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ARGS+=${ICONV_CONFIGURE_ARG}
CONFIGURE_ENV+=	NEWCXX="${CXX}" \
		PTHREAD_LIBS="-pthread"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SUB_FILES=	pkg-message

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
BUILD_DEPENDS+=	${LOCALBASE}/lib/ocaml/site-lib/lablgtk2/lablrsvg.cma:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2
LIB_DEPENDS+=	rsvg-2:${PORTSDIR}/graphics/librsvg2

CONFIGURE_ARGS+=--enable-gui=newgui2
# we don't need lablgtk as RUN dependency, but we need gtk+glib
USE_GNOME=	gtk20
.endif # !defined(WITHOUT_GUI)

.if !defined(WITHOUT_CORE)
USE_RC_SUBR=	mlnet
SUB_LIST+=	SH=${SH:Q}

. if !defined(WITHOUT_GD)
LIB_DEPENDS+=	gd:${PORTSDIR}/graphics/gd
. else
CONFIGURE_ARGS+=--disable-gd
. endif
.endif

DOCFILES=	Authors.txt Bugs.txt ChangeLog Developers.txt \
		Install.txt Todo.txt ed2k_links.txt
PORTDOCS=	${DOCFILES}

# build additional tools
ALL_TARGET+=	\
		mld_hash

NO_STAGE=	yes
.include <bsd.port.pre.mk>

pre-everything::
.if !defined(WITHOUT_GUI) && !defined(WITHOUT_CORE)
	@${ECHO_MSG} "You can disable the GUI by defining WITHOUT_GUI."
	@${ECHO_MSG} "You can disable the CORE by defining WITHOUT_CORE."
	@${ECHO_MSG}
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
	@${REINPLACE_CMD} -E \
		-e 's@(\+)(lablgtk2)@\1site-lib/\2@' \
		-e 's@(\+)(labl\$$\(GTK\))@\1site-lib/\2@' \
		-e 's@(OCAMLLIB/)(\$$LABLGTK_NAME)@\1site-lib/\2@' \
		${WRKSRC}/config/configure.in \
		${WRKSRC}/config/Makefile.in
	@${REINPLACE_CMD} -E \
		-e 's@(#include <)(lablgtk2/)@\1site-lib/\2@'  \
		${WRKSRC}/src/gtk2/gui/x11/systraystubs.c
# update server.met provider
	@${REINPLACE_CMD} -E \
		-e 's|http://www.gruk.org/server.met.gz|http://www.jd2k.com/server.met|' \
		-e 's|http://www.bluetack.co.uk/config/antip2p.txt|http://www.bluetack.co.uk/config/level1.gz|' \
		${WRKSRC}/src/daemon/common/commonOptions.ml \
		${WRKSRC}/src/networks/donkey/donkeyServers.ml

pre-configure:
	@cd ${WRKSRC}/config && ${AUTOCONF}

do-install:
.ifndef(WITHOUT_CORE)
	@${INSTALL_PROGRAM} ${WRKSRC}/mld_hash		${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/mlnet		${PREFIX}/bin/mlnet-real
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh		${PREFIX}/bin/mlnet
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_SCRIPT} ${FILESDIR}/kill_mldonkey	${EXAMPLESDIR}
.endif
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
