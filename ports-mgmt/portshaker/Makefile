# Created by: Romain Tartiere <romain@blogreen.org>
# $FreeBSD$

PORTNAME?=	portshaker
PORTVERSION=	1.0.8
PORTREVISION?=	0
CATEGORIES?=	ports-mgmt
MASTER_SITES=	http://bsd-sharp.googlecode.com/files/ \
		http://romain.blogreen.org/distfiles/
DISTNAME=	portshaker-${PORTVERSION}

MAINTAINER?=	romain@FreeBSD.org
COMMENT?=	Maintain ports tree using multiple sources

.if ${PORTNAME} == "portshaker"
OPTIONS_DEFINE=	RSYNC SVN GIT HG
OPTIONS_DEFAULT=	RSYNC SVN
RSYNC_DESC=	rsync support
GIT_DESC=	git support
HG_DESC=	mercurial support
MAN5=		portshaker.conf.5 \
		portshaker.d.5
MAN8=		portshaker.8
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
.endif

.include <bsd.port.options.mk>

.if ${PORTNAME} == "portshaker"

. if ${PORT_OPTIONS:MRSYNC}
RUN_DEPENDS+=	rsync:${PORTSDIR}/net/rsync
. endif
. if ${PORT_OPTIONS:MSVN}
RUN_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
. endif
. if ${PORT_OPTIONS:MGIT}
RUN_DEPENDS+=	git:${PORTSDIR}/devel/git
. endif
. if ${PORT_OPTIONS:MHG}
RUN_DEPENDS+=	hg:${PORTSDIR}/devel/mercurial
. endif

.else

. if ${PORT_OPTIONS:MBSDSHARP}
MAKE_ENV+=	WITH_BSDSHARP=1
. endif
. if ${PORT_OPTIONS:MENLIGHTENMENT}
MAKE_ENV+=	WITH_ENLIGHTENMENT=1
. endif
. if ${PORT_OPTIONS:MGECKO}
MAKE_ENV+=	WITH_GECKO=1
. endif
. if ${PORT_OPTIONS:MHASKELL}
MAKE_ENV+=	WITH_HASKELL=1
. endif
. if ${PORT_OPTIONS:MMARCUSCOM}
MAKE_ENV+=	WITH_MARCUSCOM=1
. endif
. if ${PORT_OPTIONS:MTEXLIVE}
MAKE_ENV+=	WITH_TEXLIVE=1
. endif
. if ${PORT_OPTIONS:MXORG}
MAKE_ENV+=	WITH_XORG=1
. endif

.endif

.include <bsd.port.mk>
