# New ports collection makefile for:	wuzzah
# Date created:				8 Sep 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	wuzzah
PORTVERSION=	0.53
CATEGORIES=	sysutils
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A command line utility for stalking users

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

LICENSE=	GPLv2

PLIST_FILES=	bin/wuzzah
MAN1=		wuzzah.1

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} >= 900007
	@${REINPLACE_CMD} -e '/^CFLAGS/d' -e 's|^\(SUBDIRS.*\)utmpx|\1|p' \
		${WRKSRC}/Makefile.in
.else
	@${REINPLACE_CMD} -e '/^CFLAGS/d' ${WRKSRC}/Makefile.in
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
