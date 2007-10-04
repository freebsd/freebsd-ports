# New ports collection makefile for:	heyu2
# Date created:		29 March 2004
# Whom:			mstowe@chicago.us.mensa.org
#
# $FreeBSD$
#

PORTNAME=	heyu2
PORTVERSION=	2.1.2
CATEGORIES=	misc
MASTER_SITES=	http://www.heyu.org/download/
DISTNAME=	heyu-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	mstowe@chicago.us.mensa.org
COMMENT=	Control a CM11A interface from the command line

CONFLICTS=	heyu-[0-9]*

#IS_INTERACTIVE=	yes
ALL_TARGET=	all
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=	freebsd

MAN1=		heyu.1
MAN5=		x10config.5 \
		x10sched.5 \
		x10scripts.5

post-patch:
	@${REINPLACE_CMD} -E 's|/usr/local|${PREFIX}|g; \
			     s,(CC) =,\1 ?=,g; \
			     s,(CFLAGS) =,\1 +=,g' \
		${WRKSRC}/Configure
	@${REINPLACE_CMD} -e 's|<.*termio[s]*.h|<sys/ttycom.h|g' \
		${WRKSRC}/cm17a.c \
		${WRKSRC}/xsync.c \
		${WRKSRC}/xwrite.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/heyu ${PREFIX}/bin
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/heyu.1 ${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/x10config.5 ${MAN5PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/x10sched.5 ${MAN5PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/x10scripts.5 ${MAN5PREFIX}/man/man5
	${INSTALL_DATA} ${WRKSRC}/x10config.sample ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/x10.sched.sample ${EXAMPLESDIR}

.include <bsd.port.mk>
