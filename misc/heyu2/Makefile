# New ports collection makefile for:	heyu
# Date created:		27 December 1999
# Whom:			plambert@plambert.net
#
# $FreeBSD$
#

PORTNAME=	heyu
PORTVERSION=	1.33
CATEGORIES=	misc
MASTER_SITES=	http://heyu.tanj.com/
DISTNAME=	x10_heyu
EXTRACT_SUFX=	.tgz

MAINTAINER=	plambert@plambert.net

IS_INTERACTIVE=	yes
ALL_TARGET=	heyu
WRKSRC=		${WRKDIR}/heyu.dir

MAN1=		heyu.1
MAN5=		x10config.5 \
		x10sched.5

do-configure:
	${PERL} -pi.orig -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/Makefile

pre-patch:
	(cd ${WRKSRC} && ./Configure)

post-install:
	strip ${PREFIX}/bin/heyu
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/heyu
	${INSTALL_DATA} ${WRKSRC}/x10config ${PREFIX}/share/examples/heyu/x10config.sample
	${INSTALL_DATA} ${WRKSRC}/x10sched.conf.sample ${PREFIX}/share/examples/heyu
.endif

.include <bsd.port.mk>
