# New ports collection makefile for:	bsdinfo
# Date created:        8 June 2012
# Whom:                samu <s@samu.pl>
#
# $FreeBSD$
#

PORTNAME=	bsdinfo
PORTVERSION=	0.22
CATEGORIES=	sysutils
MASTER_SITES=	http://cloud.github.com/downloads/samupl/bsdinfo/

MAINTAINER=	s@samu.pl
COMMENT=	A simple utility to display system-based information

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	X256
X256_DESC=	Build the 256 color version

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX256}
CONFIGURE_ARGS+=--x256
.endif

PLIST_FILES+=	bin/bsdinfo

.include <bsd.port.mk>
