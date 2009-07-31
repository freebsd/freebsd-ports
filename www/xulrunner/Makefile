# New ports collection makefile for:	xulrunner
# Date created:		2006-02-20
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-stable/www/xulrunner/Makefile,v 1.3 2008/08/07 04:42:36 mezz Exp $
#

PORTNAME=	xulrunner
PORTVERSION=	1.8.0.4
PORTREVISION?=	16
CATEGORIES?=	www devel
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	xulrunner/releases/${PORTVERSION}/source/
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER?=	gecko@FreeBSD.org
COMMENT?=	Mozilla runtime package that can be used to bootstrap XUL+XPCOM apps

WANT_GNOME=	yes
WANT_PERL=	yes
ALL_TARGET=	default
HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes

PORT_MOZCONFIG=	${WRKSRC}/xulrunner/config/mozconfig
MOZ_OPTIONS?=	--with-default-mozilla-five-home=${PREFIX}/lib/${MOZILLA} \
		--disable-javaxpcom --enable-canvas \
		--enable-system-cairo
MOZ_EXTENSIONS=	default,cookie,permissions
OPTIONS=	# Empty, used for generic gecko OPTIONS
USE_GECKO_OPTIONS=	java debug logging optimized_cflags

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/mozilla/Makefile.common"
.include <bsd.port.post.mk>
