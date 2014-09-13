# Created by: Romain Tartiere <romain@blogreen.org>
# $FreeBSD$

PORTNAME?=	portshaker
PORTVERSION=	1.0.10
PORTREVISION?=	0
CATEGORIES?=	ports-mgmt
DISTNAME=	portshaker-${PORTVERSION}

MAINTAINER?=	romain@FreeBSD.org
COMMENT?=	Maintain ports tree using multiple sources

USES+=		uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	smortex
GH_PROJECT=	portshaker
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	b88edd7

.if ${PORTNAME} == "portshaker"
OPTIONS_DEFINE=	RSYNC SVN GIT HG
OPTIONS_DEFAULT=	RSYNC SVN
RSYNC_DESC=	rsync support
GIT_DESC=	git support
HG_DESC=	mercurial support
RSYNC_RUN_DEPENDS=	rsync:${PORTSDIR}/net/rsync
SVN_RUN_DEPENDS=	svn:${PORTSDIR}/devel/subversion
GIT_RUN_DEPENDS=	git:${PORTSDIR}/devel/git
HG_RUN_DEPENDS=		hg:${PORTSDIR}/devel/mercurial
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
