# New ports collection makefile for:	mldonkey
# Date created:		19 December 2002
# Whom:			Holger Lamm <holger@e-gitt.net>
#
# $FreeBSD$
#

PORTNAME=	mldonkey
PORTVERSION=	2.02.0
CATEGORIES=	net
MASTER_SITES=	http://ernie.eit.uni-kl.de/mldonkey/ \
		http://savannah.nongnu.org/download/mldonkey/stable/contributed/
PKGNAMESUFFIX=	-gui
DISTNAME=	${PORTNAME}-${PORTVERSION:C/.0$/-0/}.shared.${ARCH}-${OPSYS}

MAINTAINER=	holger@e-gitt.net

LIB_DEPENDS=	c.4:${PORTSDIR}/misc/compat4x

ONLY_FOR_ARCHS= i386 alpha
USE_BZIP2=	yes
USE_GNOMENG=    yes
USE_GNOME=      gtk12
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-distrib-${PORTVERSION}

DIRNAME=	${HOME}/.mldonkey

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mldonkey_gui	${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/mldonkey_gui2	${PREFIX}/bin

post-install:
	@${FMT} < ${PKGMESSAGE}

.include <bsd.port.pre.mk>

install-user: extract
.if !defined(LANG)
	@${ECHO_MSG} "Please call as:  make install-user LANG=<lang>"
	@${ECHO_MSG} "with <lang> one of en,de,fr,fr.noaccents !"
.else
	@${CP} ${WRKSRC}/i18n/gui_messages.ini.${LANG}\
		${HOME}/.mldonkey_gui_messages.ini
.endif

.include <bsd.port.post.mk>
