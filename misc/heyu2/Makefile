# New ports collection makefile for:	heyu2
# Date created:		29 March 2004
# Whom:			mstowe@chicago.us.mensa.org
#
# $FreeBSD$
#

PORTNAME=	heyu2
PORTVERSION=	2.0.a.5
CATEGORIES=	misc
MASTER_SITES=	http://heyu.tanj.com/heyu2/
DISTNAME=	heyu2.alpha-5
EXTRACT_SUFX=	.tgz

MAINTAINER=	mstowe@chicago.us.mensa.org
COMMENT=	Control a CM11A interface from the command line

#IS_INTERACTIVE=	yes
ALL_TARGET=	heyu2
WRKSRC=		${WRKDIR}/heyu2.alpha-5.2.dir
USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=	freebsd

MAN1=		heyu2.1
MAN5=		x10config2.5 \
		x10sched2.5 \
		x10scripts2.5

post-patch:
	${REINPLACE_CMD} 's|/usr/local|${PREFIX}|' ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/heyu2 ${PREFIX}/bin
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/heyu2.1 ${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/x10config2.5 ${MAN5PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/x10sched2.5 ${MAN5PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/x10scripts2.5 ${MAN5PREFIX}/man/man5
	${INSTALL_DATA} ${WRKSRC}/x10config.sample ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/x10.sched.sample ${EXAMPLESDIR}

.include <bsd.port.mk>
