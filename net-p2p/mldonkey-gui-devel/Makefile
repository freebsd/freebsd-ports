# New ports collection makefile for:	mldonkey
# Date created:		19 December 2002
# Whom:			Holger Lamm <holger@e-gitt.net>
#
# $FreeBSD$
#

PORTNAME=	mldonkey
PORTVERSION=	2.04.r1
CATEGORIES=	net
MASTER_SITES=	http://savannah.nongnu.org/download/mldonkey/release-2.04rc1/contributed/holger/
PKGNAMESUFFIX=	-gui
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/rc/}-0.shared.${ARCH}-${OPSYS}-hl

MAINTAINER=	holger@e-gitt.net
COMMENT=	A OCAML/GTK GUI for the mldonkey peer-to-peer network client

ONLY_FOR_ARCHS= i386 alpha
USE_BZIP2=	yes
USE_GNOMENG=    yes
USE_GNOME=      gtk12
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-distrib-${PORTVERSION:S/.r/rc/}-0

DIRNAME=	${HOME}/.mldonkey

post-patch:
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|" ${FILESDIR}/wrapper.sh > \
		${WRKDIR}/wrapper.sh

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mldonkey_gui	${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/mldonkey+gui	${PREFIX}/bin/mldonkey+gui-real
	@if [ -e ${PREFIX}/bin/mldonkey ]; then \
	  ${LN}	${PREFIX}/bin/mldonkey		${PREFIX}/bin/mldonkey+gui; \
	else \
	  ${INSTALL_SCRIPT}  ${WRKDIR}/wrapper.sh	${PREFIX}/bin/mldonkey+gui; \
	fi
	@${INSTALL_PROGRAM} ${WRKSRC}/mldonkey_gui2	${PREFIX}/bin
	@${INSTALL_SCRIPT}  ${WRKSRC}/mldonkey_previewer	${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/mldonkey_guistarter	${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/mlim		${PREFIX}/bin

post-install:
	@${CAT}  ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
LIB_DEPENDS+=	c_r.4:${PORTSDIR}/misc/compat4x
.endif

install-user: extract
.if !defined(LANG)
	@${ECHO_MSG} "Please call as:  make install-user LANG=<lang>"
	@${ECHO_MSG} "with <lang> one of en,de,fr,fr.noaccents,sp !"
.else
	@${CP} ${WRKSRC}/i18n/gui_messages.ini.${LANG}\
		${HOME}/.mldonkey_gui_messages.ini
.endif

.include <bsd.port.post.mk>
