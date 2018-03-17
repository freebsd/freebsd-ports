# $FreeBSD$

PORTNAME=	trueos-server
PORTVERSION=	201803131015
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
GH_TAGNAME=     f8b9f07940a9b460351f2dfe2c7d53fbe0e832f1

.include <bsd.port.mk>
