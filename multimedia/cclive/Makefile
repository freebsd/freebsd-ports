# Ports collection makefile for:    cclive
# Date created:		1 February 2009
# Whom:			Toni Gundogdu <legatvs@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	cclive
PORTVERSION=	0.2.6
CATEGORIES=	multimedia net
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	legatvs@gmail.com
COMMENT=	Lightweight command line video extraction utility

LIB_DEPENDS=	curl.5:${PORTSDIR}/ftp/curl

OPTIONS=	TITLE 	 "Enable video title parsing (req. Perl)" off \
		SIGWINCH "Enable SIGWINCH handling; resize progressbar" on

MAKE_ENV=	V=1
MAN1=		cclive.1

PLIST_FILES=	bin/cclive

USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.pre.mk>

MAKE_ENV+=	WITH_MAN=yes

.if defined(WITH_TITLE)
MAKE_ENV+=	WITH_PERL=yes
USE_PERL5=	5.8.2+
RUN_DEPENDS+=	p5-HTML-Parser>=3.59:${PORTSDIR}/www/p5-HTML-Parser
.endif

.if defined(WITH_SIGWINCH)
MAKE_ENV+=	WITH_SIGWINCH=yes
.endif

.include <bsd.port.post.mk>
