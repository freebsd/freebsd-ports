# New ports collection makefile for:    fswatch
# Date created:         18 April 2006
# Whom:                 dominik karczmarski <dominik@karczmarski.com>
#
# $FreeBSD$
#

PORTNAME=		fswatch
DISTVERSION=		0.02beta5
CATEGORIES=		security sysutils
MASTER_SITES=		SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-0.02beta5

MAINTAINER=		dominik@karczmarski.com
COMMENT=		File system checksum checker

HAS_CONFIGURE=		yes
SUB_FILES=		pkg-message

WRKSRC=			${WRKDIR}/${PORTNAME}-${PORTVERSION:C/.b/beta/}/

CONFIGURE_ARGS+=	--prefix=${PREFIX} \
			--enable-regex \
			--enable-stflags

PLIST_FILES=	bin/fswbuild bin/fswcmp bin/fswshow \
		bin/fswconf etc/fswatch.conf.sample

MAN1=	fswbuild.1 fswcmp.1 fswshow.1 fswconf.1
MAN5=	fswatch.conf.5
MAN7=	fswatch.7

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
