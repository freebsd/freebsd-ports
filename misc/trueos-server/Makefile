# $FreeBSD$

PORTNAME=	trueos-server
PORTVERSION=	201802221443
CATEGORIES=	misc
MASTER_SITES=
DISTFILES=

MAINTAINER=	jmaloney@ixsystems.com
COMMENT=	TrueOS Server

RUN_DEPENDS=	trueos-core>=0:misc/trueos-core \
		${LOCALBASE}/bin/sudo:security/sudo \
		${LOCALBASE}/bin/zsh:shells/zsh \
		${LOCALBASE}/bin/rsync:net/rsync \
		${LOCALBASE}/bin/screen:sysutils/screen \
		${LOCALBASE}/bin/tmux:sysutils/tmux \
		${LOCALBASE}/bin/nano:editors/nano

CONFLICTS=	pcbsd-utils-[0-9]* trueos-desktop-[0-9]*
WRKSRC_SUBDIR=	package-files
MAKE_ARGS=	STAGEDIR=${STAGEDIR}  TYPE=server

USE_GITHUB=     yes
GH_ACCOUNT=     trueos
GH_PROJECT=     trueos-core
GH_TAGNAME=     2a4f26fcd46a5df1615ab1a120d6aeaa9f88ab65

.include <bsd.port.mk>
