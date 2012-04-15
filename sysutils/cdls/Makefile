# New ports collection makefile for:	cdls
# Date created:	13 april 2012
# Whom:		Hans de Hartog <hans@dehartog.nl>
#
# $FreeBSD$
#

PORTNAME=	cdls
PORTVERSION=	4.2
CATEGORIES=	sysutils
MASTER_SITES=	ftp://pd7w.fs2a.eu/

MAINTAINER=	hans@dehartog.nl
COMMENT=	A curses based file manager for system managers

PLIST_FILES=	bin/cdls

USE_NCURSES=	yes

.if defined(WITH_NCURSES_BASE)
# no need to use ncurses-config if we use ncurses from the base system
CONFIGURE_ARGS+=	NCURSES_CONFIG=/usr/bin/true
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
