# New ports collection makefile for:	mldonkey
# Date created:		18 January 2003
# Whom:			Holger Lamm <holger@e-gitt.net>
#
# $FreeBSD$
#

PORTNAME=	mldonkey
PORTVERSION=	2.04.r1
CATEGORIES=	net
MASTER_SITES=	http://savannah.nongnu.org/download/mldonkey/release-${PORTVERSION:S/.r/rc/}/
PKGNAMESUFFIX=	-src
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/rc/}.sources

MAINTAINER=	holger@e-gitt.net
COMMENT=	A OCAML client for eDonkey and Overnet peer-to-peer networks

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-multinet \
		--enable-pthread
WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GMAKE=	yes
ALL_TARGET=	depend all

.if defined(WITHOUT_GUI)
# have no 'without-' flag
CONFIGURE_ARGS+=	--disable-gui
PLIST_SUB+=	GUI="@comment "
.else
PLIST_SUB+=	GUI=""
BUILD_DEPENDS+=	lablgtk:${PORTSDIR}/x11-toolkits/ocaml-lablgtk \
		${LOCALBASE}/lib/ocaml/jabbr.cma:${PORTSDIR}/net/ocaml-jabbr
# we don't need lablgtk as RUN dependency, but we need gtk+glib
USE_GNOMENG=	yes
USE_GNOME=	gtk12
.endif

DOCFILES=	AUTHORS BUGS ChangeLog Developers.txt FAQ.html \
		Readme.txt TODO ed2k_links.txt

pre-everything::
.if !defined(WITHOUT_GUI)
	@${ECHO_MSG} "You can disable the GUI by defining WITHOUT_GUI."
.endif

post-patch:
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|" ${FILESDIR}/wrapper.sh > \
		${WRKDIR}/wrapper.sh

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mldonkey		${PREFIX}/bin/mldonkey-real
	@${INSTALL_SCRIPT} ${FILESDIR}/kill_mldonkey	${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh		${PREFIX}/bin/mldonkey
.ifndef(WITHOUT_GUI)
	@${INSTALL_SCRIPT} ${WRKSRC}/distrib/mldonkey_previewer ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/mldonkey_guistarter	${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/mldonkey_gui	${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/mldonkey_gui2	${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/mldonkey+gui	${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/mlchat		${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/mlim		${PREFIX}/bin
.endif
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/distrib/${file} ${DOCSDIR}
.endfor
.endif

post-install:
	@${FMT} < ${PKGMESSAGE}

install-user: extract
.if !defined(LANG)
	@${ECHO_MSG} "Please call as:  make install-user LANG=<lang>"
	@${ECHO_MSG} "with <lang> one of en,de,fr,fr.noaccents,sp !"
.else
	@${CP} ${WRKSRC}/distrib/i18n/gui_messages.ini.${LANG}\
		${HOME}/.mldonkey_gui_messages.ini
.endif

.include <bsd.port.mk>
