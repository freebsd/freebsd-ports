# Created by: Romain Tartiere <romain@blogreen.org>
# $FreeBSD$

PORTNAME?=	portshaker
PORTVERSION=	1.0.10
DISTVERSIONPREFIX=	v
PORTREVISION?=	1
CATEGORIES?=	ports-mgmt

MAINTAINER?=	romain@FreeBSD.org
COMMENT?=	Maintain ports tree using multiple sources

USES+=		uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	smortex
GH_PROJECT=	portshaker

.if ${PORTNAME} == "portshaker"
OPTIONS_DEFINE=	RSYNC SVN GIT HG
OPTIONS_DEFAULT=	RSYNC SVN
RSYNC_DESC=	rsync support
GIT_DESC=	git support
HG_DESC=	mercurial support
RSYNC_RUN_DEPENDS=	rsync:net/rsync
.if defined(WITH_SUBVERSION_VER) && ${WITH_SUBVERSION_VER} == 18
SVN_RUN_DEPENDS=	svn:devel/subversion18
.else
SVN_RUN_DEPENDS=	svn:devel/subversion
.endif
GIT_RUN_DEPENDS=	git:devel/git
HG_RUN_DEPENDS=		hg:devel/mercurial
.else
OPTIONS_DEFINE=	BSDSHARP ENLIGHTENMENT GECKO HASKELL MARCUSCOM TEXLIVE XORG
OPTIONS_DEFAULT=	BSDSHARP
BSDSHARP_DESC=		Enable BSD-sharp ports
ENLIGHTENMENT_DESC=	Enable Enlightnement ports
GECKO_DESC=		Enable Gecko ports
HASKELL_DESC=		Enable Haskell ports
MARCUSCOM_DESC=		Enable GNOME development ports
TEXLIVE_DESC=		Enable TeXLive ports (Experimental)
XORG_DESC=		Enable Xorg development ports
BSDSHARP_MAKE_ENV=	WITH_BSDSHARP=1
ENLIGHTENMENT_MAKE_ENV=	WITH_ENLIGHTENMENT=1
GECKO_MAKE_ENV=		WITH_GECKO=1
HASKELL_MAKE_ENV=	WITH_HASKELL=1
MARCUSCOM_MAKE_ENV=	WITH_MARCUSCOM=1
TEXLIVE_MAKE_ENV=	WITH_TEXLIVE=1
XORG_MAKE_ENV=		WITH_XORG=1
.endif

.include <bsd.port.mk>
