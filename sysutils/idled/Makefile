# New ports collection makefile for:	idled
# Date created:			12 March 1997
# Whom:		Andrew <andrew@ugh.net.au>, Iain Templeton <iain@ugh.net.au>
#
# $FreeBSD$
#

PORTNAME=	idled
PORTVERSION=	1.16
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.netsw.org/system/tools/process/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A daemon that logs out idle users and those users hogging resources

DEPRECATED=     Upstream disapear and distfile is no more available, consider using sysutils/doinkd
EXPIRATION_DATE=        2011-05-01

NO_CDROM=	non-profit use and distribution only
MANCOMPRESSED=	yes
MAN5=		idled.cf.5
MAN8=		idled.8

USE_RC_SUBR=	${PORTNAME}

PLIST_FILES=	etc/idled.cf.template libexec/idled

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 900006
EXTRA_PATCHES=	${PATCHDIR}/utmpx-Makefile \
		${PATCHDIR}/utmpx-idled.h \
		${PATCHDIR}/utmpx-idled.c
.else
EXTRA_PATCHES=	${PATCHDIR}/utmp-Makefile
.endif

post-extract:
	(cd ${WRKSRC}; make clean)

post-install:
	@${STRIP_CMD} ${PREFIX}/libexec/idled

.include <bsd.port.post.mk>
