# New ports collection makefile for:	heyu
# Date created:		27 December 1999
# Whom:			plambert@plambert.net
#
# $FreeBSD$
#

PORTNAME=	heyu
PORTVERSION=	1.35
PORTREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	http://www.heyu.org/version1/
DISTNAME=	x10_heyu
EXTRACT_SUFX=	.tgz

MAINTAINER=	mstowe@chicago.us.mensa.org
COMMENT=	Control a CM11A interface from the command line

CONFLICTS=	heyu2-[0-9]*

FOR_CDROM=	yes
ALL_TARGET=	heyu
WRKSRC=		${WRKDIR}/heyu.dir

MAN1=		heyu.1 heyuhelper.1
MAN5=		x10config.5 \
		x10sched.5

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -E 's|/usr/local|${PREFIX}|g; \
		s,(CC) =,\1 ?=,g; \
		s,(CFLAGS) =,\1 +=,g'\
		${WRKSRC}/Configure

do-configure:
	(cd ${WRKSRC} && ./Configure freebsd)

post-install:
	${STRIP_CMD} ${PREFIX}/bin/heyu
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/x10config ${EXAMPLESDIR}/x10config.sample
	${INSTALL_DATA} ${WRKSRC}/x10sched.conf.sample ${EXAMPLESDIR}

.include <bsd.port.post.mk>
