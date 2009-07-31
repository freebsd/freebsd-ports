# Ports collection makefile for:    cclive
# Date created:		1 February 2009
# Whom:			Toni Gundogdu <legatvs@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	cclive
PORTVERSION=	0.4.6
CATEGORIES=	multimedia net
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	legatvs@gmail.com
COMMENT=	Lightweight command line video extraction utility

LIB_DEPENDS=	curl.5:${PORTSDIR}/ftp/curl

OPTIONS=	PERL "With Perl interpreter" off \
		SIGWINCH "With resizing progressbar" on

MAN1=		cclive.1

PLIST_FILES=	bin/cclive

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GCC=	4.2+
MAKE_JOBS_SAFE=	yes
USE_GNOME=	pkgconfig

.include <bsd.port.pre.mk>

.if defined(WITH_PERL)
CONFIGURE_ARGS+=--with-perl
USE_PERL5=	5.8.2+
BUILD_DEPENDS+=	p5-HTML-Parser>=3.59:${PORTSDIR}/www/p5-HTML-Parser
RUN_DEPENDS+=	p5-HTML-Parser>=3.59:${PORTSDIR}/www/p5-HTML-Parser
.else
CONFIGURE_ARGS+=--without-perl
.endif

.if defined(WITH_SIGWINCH)
CONFIGURE_ARGS+=--enable-sigwinch
.else
CONFIGURE_ARGS+=--disable-sigwinch
.endif

.include <bsd.port.post.mk>
