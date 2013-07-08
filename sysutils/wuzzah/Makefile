# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	wuzzah
PORTVERSION=	0.53
CATEGORIES=	sysutils
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Command-line utility for stalking users

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USES=		gmake
MAKE_JOBS_SAFE=	yes

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
