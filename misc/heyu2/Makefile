# New ports collection makefile for:	heyu2
# Date created:		29 March 2004
# Whom:			mstowe@chicago.us.mensa.org
#
# $FreeBSD$
#

PORTNAME=	heyu2
PORTVERSION=	2.0.b.2
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://heyu.tanj.com/heyu2/
DISTNAME=	heyu-2.0beta.2
EXTRACT_SUFX=	.tgz

MAINTAINER=	mstowe@chicago.us.mensa.org
COMMENT=	Control a CM11A interface from the command line

CONFLICTS=	heyu-*

#IS_INTERACTIVE=	yes
ALL_TARGET=	all
WRKSRC=		${WRKDIR}/heyu-2.0beta.2
USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=	freebsd

MAN1=		heyu.1
MAN5=		x10config.5 \
		x10sched.5 \
		x10scripts.5

post-patch:
	${REINPLACE_CMD} 's|/usr/local|${PREFIX}|' ${WRKSRC}/Makefile.in

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
