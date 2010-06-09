# New ports collection makefile for:	portshaker
# Date created:		2008-11-01
# Whom:			Romain Tartiere <romain@blogreen.org>
#
# $FreeBSD$
#

PORTNAME?=	portshaker
PORTVERSION=	1.0.0
PORTREVISION?=	0
CATEGORIES?=	ports-mgmt
MASTER_SITES=	http://bsd-sharp.googlecode.com/files/ \
		http://romain.blogreen.org/distfiles/
DISTNAME=	portshaker-${PORTVERSION}

MAINTAINER?=	romain@FreeBSD.org
COMMENT?=	Maintain ports tree using multiple sources

.if ${PORTNAME} == "portshaker"
OPTIONS=	RSYNC          "Force dependency on rsync"             on \
		SVN            "Force dependency on Subversion"        on \
		GIT            "Force dependency on Git"               off \
		HG             "Force dependency on Mercurial"         off \

MAN5=		portshaker.conf.5 \
		portshaker.d.5
MAN8=		portshaker.8
.else
OPTIONS=	BSDSHARP  "Enable BSD-sharp ports"                on \
		MARCUSCOM "Enable GNOME development ports"        off \
		TEXLIVE   "Enable TeXLive ports (Experimental)"   off
.endif

.include <bsd.port.options.mk>

.if ${PORTNAME} == "portshaker"

. if defined(WITH_RSYNC)
RUN_DEPENDS+=	rsync:${PORTSDIR}/net/rsync
. endif
. if defined(WITH_SVN)
RUN_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
. endif
. if defined(WITH_GIT)
RUN_DEPENDS+=	git:${PORTSDIR}/devel/git
. endif
. if defined(WITH_HG)
RUN_DEPENDS+=	hg:${PORTSDIR}/devel/mercurial
. endif

.else

. if defined (WITH_BSDSHARP)
MAKE_ENV+=	WITH_BSDSHARP=1
. endif
. if defined (WITH_MARCUSCOM)
MAKE_ENV+=	WITH_MARCUSCOM=1
. endif
. if defined (WITH_TEXLIVE)
MAKE_ENV+=	WITH_TEXLIVE=1
. endif

.endif

.include <bsd.port.mk>
