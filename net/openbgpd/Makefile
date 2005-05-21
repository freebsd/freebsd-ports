# New ports collection makefile for:	openbgpd
# Date created:				May 10 2005
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openbgpd
PORTVERSION=	3.6
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.openbsd.org/pub/OpenBSD/OpenBGPD/:openbsd \
		${MASTER_SITE_LOCAL:S/$/:freebsd/g}
MASTER_SITE_SUBDIR=	flz/openbgpd/:freebsd
DISTFILES=	${PORTNAME}-${PORTVERSION}.tgz:openbsd,freebsd \
		if_media.h:freebsd pfkey_compat.c:freebsd
DIST_SUBDIR=	openbgpd
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}.tgz

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Free implementation of the Border Gateway Protocol, Version 4

WRKSRC=		${WRKDIR}
MANCOMPRESSED=	yes
USE_RC_SUBR=	openbgpd.sh
USE_REINPLACE=	yes
MAKE_ENV=	BINDIR="${PREFIX}/sbin" \
		MANDIR="${PREFIX}/man/man"

PLIST_FILES=	sbin/bgpctl	\
		sbin/bgpd

MAN5=		bgpd.conf.5
MAN8=		bgpctl.8	\
		bgpd.8

SUBDIRS=	bgpd \
		bgpctl

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500037
IGNORE=		Requires macros present in <sys/tree.h>
.endif

post-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/if_media.h ${WRKSRC}/bgpctl/
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/pfkey_compat.c ${WRKSRC}/bgpd/

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g"	\
		${WRKSRC}/bgpd/Makefile			\
		${WRKSRC}/bgpd/bgpd.8			\
		${WRKSRC}/bgpd/bgpd.h			\
		${WRKSRC}/bgpd/bgpd.conf.5		\
		${WRKSRC}/bgpctl/Makefile

do-build:
.for i in ${SUBDIRS}
	cd ${WRKSRC}/$i; make
.endfor

do-install:
.for i in ${SUBDIRS}
	cd ${WRKSRC}/$i; make install ${MAKE_ENV}
.endfor

.include <bsd.port.post.mk>
