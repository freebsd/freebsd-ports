# New ports collection makefile for:	mldonkey
# Date created:		21 August 2002
# Whom:			Holger Lamm <holger@e-gitt.net>
#
# $FreeBSD$
#

PORTNAME=	mldonkey
PORTVERSION=	2.5.4
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}/release-${PORTVERSION:C/\.(.)$/-\1/}/official
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(.)$/-\1/}

MAINTAINER=	holger@e-gitt.net
COMMENT?=	A OCAML client for multiple peer-to-peer networks

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-pthread --enable-ocamlver=3
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/\.(.)$/-\1/}
USE_GMAKE=	yes
ALL_TARGET=	depend opt

.if defined(WITHOUT_GUI)
.if defined(WITHOUT_CORE)
.error "Cool, you defined both WITHOUT_GUI and WITHOUT_CORE. I think I'll do nothing."
.endif
# have no 'without-' flag
CONFIGURE_ARGS+=--disable-gui
PLIST_SUB+=	CORE="" GUI="@comment " GUICORE="@comment "
PKGNAMESUFFIX=	-core
.else
PLIST_SUB+=	GUI=""
BUILD_DEPENDS+=	lablgtk:${PORTSDIR}/x11-toolkits/ocaml-lablgtk \
		${LOCALBASE}/lib/ocaml/jabbr.cma:${PORTSDIR}/net/ocaml-jabbr
# we don't need lablgtk as RUN dependency, but we need gtk+glib
USE_GNOME=	gtk12
.if defined(WITHOUT_CORE)
PKGNAMESUFFIX=	-gui
PLIST_SUB+=	CORE="@comment " GUICORE="@comment "
.else
PLIST_SUB+=	CORE=""	GUICORE=""
.endif
.endif

DOCFILES=	AUTHORS BUGS ChangeLog FAQ.html \
		INSTALL TODO ed2k_links.txt

pre-everything::
.if !defined(WITHOUT_GUI) && !defined(WITHOUT_CORE)
	@${ECHO_MSG} "You can disable the GUI by defining WITHOUT_GUI."
	@${ECHO_MSG} "You can disable the CORE by defining WITHOUT_CORE."
.endif

post-patch:
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|" ${FILESDIR}/wrapper.sh > \
		${WRKDIR}/wrapper.sh

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

.include <bsd.port.mk>
