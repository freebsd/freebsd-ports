# New ports collection makefile for:	gtksubtitler
# Date created:         Thu Nov 21 15:05:53 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	GTKsubtitler
PORTVERSION=	0.2.0.p1
PORTREVISION=	1
CATEGORIES=	multimedia gnome
MASTER_SITES=	http://dark.pkn.com.pl/~pawel/gtksubtitler/download/
DISTNAME=	${PORTNAME}-v${PORTVERSION:C/.p(.)$/pre\1/}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A small GNOME program for editing and converting subtitles

USE_X_PREFIX=	yes
USE_GETOPT_LONG=	yes
USE_GNOME=	gnomeprefix gnomelibs
USE_REINPLACE=	yes
USE_SIZE=	yes
GNU_CONFIGURE=	yes

post-patch:
# disable GNU auto* tools
	@${FIND} ${WRKSRC} -type f -name "Makefile.in" | \
		${XARGS} -x -n 10 ${REINPLACE_CMD} -E -e \
		's!^(ACLOCAL|AUTOCONF|AUTOMAKE|AUTOHEADER).+$$!\1=${TRUE}!'

.include <bsd.port.mk>
