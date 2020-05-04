# Created by: Holger Lamm <holger@e-gitt.net>
# $FreeBSD$

PORTNAME=	mldonkey
PORTVERSION=	3.1.5
PORTREVISION=	3
CATEGORIES+=	net-p2p
MASTER_SITES=	SF

EXTRA_PATCHES=	${FILESDIR}/git-30e77e2:-p1

MAINTAINER?=	danfe@FreeBSD.org
COMMENT?=	Multi-protocol peer-to-peer client written in OCaml

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/Copying.txt

CONFLICTS=	mldonkey{-{core,gui},}-devel-[0-9]*

USES=		compiler:c++11-lang gmake iconv pkgconfig tar:bzip2
USE_OCAML=	yes
USE_OCAML_CAMLP4=yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	ac_cv_lib_charset_locale_charset=no
ALL_TARGET=	opt
MAKE_ENV+=	OCAMLRUNPARAM="l=256M"
MAKE_JOBS_UNSAFE=	yes

SUB_FILES=	pkg-message

###
## Options activation
###

OPTIONS_DEFINE=	GD DOCS EXAMPLES
OPTIONS_DEFAULT=CORE GD GUI
OPTIONS_MULTI=	CLIENT
OPTIONS_MULTI_CLIENT=CORE GUI
CORE_DESC=	Client 'core' support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGUI} && ${PORT_OPTIONS:MCORE}
CONFLICTS+=	mldonkey-core-[0.9]*
CONFLICTS+=	mldonkey-gui-[0.9]*

PLIST_SUB+=	CORE="" GUI="" GUICORE=""
.else # (${PORT_OPTIONS:MGUI} && ${PORT_OPTIONS:MCORE})

. if !${PORT_OPTIONS:MGUI}
PKGNAMESUFFIX=	-core

CONFLICTS+=	mldonkey-gui-[0.9]*

CONFIGURE_ARGS+=--disable-gui
PLIST_SUB+=	CORE="" GUI="@comment " GUICORE="@comment "
. endif # !${PORT_OPTIONS:MGUI}

. if !${PORT_OPTIONS:MCORE}
PKGNAMESUFFIX=	-gui

CONFLICTS+=	mldonkey-core-[0.9]*

PLIST_SUB+=	CORE="@comment " GUI="" GUICORE="@comment "
. endif # !${PORT_OPTIONS:MCORE}

.endif # ${PORT_OPTIONS:MGUI} && ${PORT_OPTIONS:MCORE}

.if ${PORT_OPTIONS:MGUI}
BUILD_DEPENDS+=	${LOCALBASE}/lib/ocaml/site-lib/lablgtk2/lablrsvg.cma:x11-toolkits/ocaml-lablgtk2

CONFIGURE_ARGS+=--enable-gui=newgui2
# we don't need lablgtk as RUN dependency, but we need gtk+glib
USES+=		gnome
USE_GNOME=	gtk20 librsvg2
.endif # ${PORT_OPTIONS:MGUI}

.if ${PORT_OPTIONS:MCORE}
USE_RC_SUBR=	mlnet
SUB_LIST+=	SH=${SH:Q}

. if ${PORT_OPTIONS:MGD}
LIB_DEPENDS+=	libgd.so:graphics/gd
. else
CONFIGURE_ARGS+=--disable-gd
. endif
.endif

PORTDOCS=	Authors.txt Bugs.txt ChangeLog Developers.txt \
		Install.txt Todo.txt ed2k_links.txt

# build additional tools
ALL_TARGET+=	\
		mld_hash

.include <bsd.port.pre.mk>

.if ${ARCH} == powerpc64
USE_GCC=	yes
.endif

post-patch:
	@${SED} \
		-e "s|%%PREFIX%%|${PREFIX}|" \
		-e "s|%%SH%%|${SH}|" \
		${FILESDIR}/wrapper.sh > \
		${WRKDIR}/wrapper.sh
	@${REINPLACE_CMD} \
		-e 's|$$OCAMLLIB/$$LABLGTK_NAME|$$OCAMLLIB/site-lib/$$LABLGTK_NAME|' \
		${WRKSRC}/config/configure
	@${REINPLACE_CMD} \
		-e 's|+labl|+site-lib/labl|' \
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
	@${REINPLACE_CMD} \
		-e 's/[u(]int32/&_t/' ${WRKSRC}/src/utils/cdk/zlibstubs.c \
		${WRKSRC}/src/utils/cdk/gdstubs.c
	@${REINPLACE_CMD} \
		-e 's/int64/&_t/' ${WRKSRC}/src/config/unix/os_stubs_c.c \
		${WRKSRC}/src/utils/lib/os_stubs.h \
		${WRKSRC}/src/utils/lib/fst_hash.c

do-install:
.if ${PORT_OPTIONS:MCORE}
	${INSTALL_PROGRAM} ${WRKSRC}/mld_hash ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mlnet ${STAGEDIR}${PREFIX}/bin/mlnet-real
	${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${STAGEDIR}${PREFIX}/bin/mlnet
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${FILESDIR}/kill_mldonkey ${STAGEDIR}${EXAMPLESDIR}
.endif
.endif
.if ${PORT_OPTIONS:MGUI}
	${INSTALL_PROGRAM} ${WRKSRC}/mlgui ${STAGEDIR}${PREFIX}/bin
.endif
.if ${PORT_OPTIONS:MGUI} && ${PORT_OPTIONS:MCORE}
	${INSTALL_SCRIPT} ${WRKSRC}/distrib/mldonkey_previewer ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mlguistarter ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mlnet+gui ${STAGEDIR}${PREFIX}/bin
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for _file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/distrib/${_file} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

install-user: extract
.if !defined(LANGUAGE)
	@${ECHO_MSG} "Please call as:  make install-user LANGUAGE=<lang>"
	@${ECHO_MSG} "with <lang> one of en,de,fr,fr.noaccents,sp !"
.else
	@${CP} ${WRKSRC}/distrib/i18n/gui_messages.ini.${LANGUAGE}\
		${HOME}/.mldonkey_gui_messages.ini
.endif

.include <bsd.port.post.mk>
