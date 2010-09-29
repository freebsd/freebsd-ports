# New ports collection makefile for:	doinkd
# Date created:			12 March 1997
# Whom:		Andrew <andrew@ugh.net.au>, Iain Templeton <iain@ugh.net.au>
#
# $FreeBSD$
#

PORTNAME=	doinkd
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/idled/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	A daemon that logs out idle users and those users hogging resources

CONFLICTS=	idled-*
MANCOMPRESSED=	yes
MAN5=		doinkd.cf.5
MAN8=		doinkd.8

USE_RC_SUBR=	${PORTNAME}

PLIST_FILES=	etc/doinkd/doinkd.cf.template sbin/doinkd
PLIST_DIRS=	etc/doinkd

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 900006
EXTRA_PATCHES=	${PATCHDIR}/utmpx-Makefile \
		${PATCHDIR}/utmpx-doinkd.h \
		${PATCHDIR}/utmpx-doinkd.c
.else
EXTRA_PATCHES=	${PATCHDIR}/utmp-Makefile
.endif

post-extract:
	(cd ${WRKSRC}; make clean)

pre-install:
	${MKDIR} ${PREFIX}/etc/doinkd

post-install:
	@${STRIP_CMD} ${PREFIX}/sbin/doinkd

.include <bsd.port.post.mk>
