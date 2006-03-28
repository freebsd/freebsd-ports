# Ports collection makefile for:	bioapi
# Date created:				10 January 2006
# Whom:					Fredrik Lindberg <fli@shapeshifter.se>
#
# $FreeBSD$
#

PORTNAME=	bioapi
PORTVERSION=	1.2.2
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	http://www.qrivy.net/~michael/blua/bioapi/ \
		http://shapeshifter.se/pub/bioapi/

MAINTAINER=	fli@shapeshifter.se
COMMENT=	BioAPI library implementation

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var/db/ --with-Qt-dir=no

INSTALLS_SHLIB=	yes
# @cwd in plist vs ldconfig workaround
LDCONFIG_DIRS=	${PREFIX}/lib

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
IGNORE=		needs at least FreeBSD 6.0-RELEASE
.endif

.include <bsd.port.post.mk>
