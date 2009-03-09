# New ports collection makefile for:	openbgpd
# Date created:				May 10 2005
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	openbgpd
PORTVERSION?=	4.2
PORTREVISION?=	0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.openbsd.org/pub/OpenBSD/OpenBGPD/:openbsd \
		${MASTER_SITE_LOCAL:S/$/:freebsd/g}
MASTER_SITE_SUBDIR=	flz/openbgpd/:freebsd
DISTFILES?=	${PORTNAME}-${PORTVERSION}.tgz:openbsd,freebsd
DISTFILES+=	if_media.h:freebsd hash.h:freebsd strtonum.c:freebsd
DIST_SUBDIR=	openbgpd
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free implementation of the Border Gateway Protocol, Version 4

CONFLICTS=	zebra-0* quagga-0*

WRKSRC=		${WRKDIR}
MANCOMPRESSED=	yes
USE_RC_SUBR=	openbgpd.sh
MAKE_ENV=	BINDIR="${PREFIX}/sbin" \
		MANDIR="${PREFIX}/man/man"
COPTS+=		-DRTA_LABEL=0

PLIST_FILES=	sbin/bgpctl	\
		sbin/bgpd

SUB_FILES=	pkg-message

MAN5=		bgpd.conf.5
MAN8=		bgpctl.8	\
		bgpd.8

SUBDIRS=	bgpd \
		bgpctl

post-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/if_media.h ${WRKSRC}/bgpctl/
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/hash.h ${WRKSRC}/bgpd/

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g"	\
		${WRKSRC}/bgpd/Makefile			\
		${WRKSRC}/bgpd/bgpd.8			\
		${WRKSRC}/bgpd/bgpd.h			\
		${WRKSRC}/bgpd/bgpd.conf.5		\
		${WRKSRC}/bgpctl/Makefile		\
		${WRKSRC}/bgpctl/bgpctl.8
	@${REINPLACE_CMD} -e "/__dead2/d"		\
		${WRKSRC}/bgpd/bgpd.h
	@${REINPLACE_CMD} -e "s|__dead||"		\
		${WRKSRC}/bgpd/bgpd.c 		\
		${WRKSRC}/bgpd/bgpd.h 		\
		${WRKSRC}/bgpctl/bgpctl.c	\
		${WRKSRC}/bgpctl/irrfilter.h	\
		${WRKSRC}/bgpctl/irrfilter.c
	@${REINPLACE_CMD} -e "s|SIMPLEQ|STAILQ|" ${WRKSRC}/bgpd/*.[chy]
	@${REINPLACE_CMD} -e "s|<net/if_media.h>|\"if_media.h\"|" ${WRKSRC}/bgpctl/bgpctl.c
	@${REINPLACE_CMD} -e "s|pfkey.c|pfkey_compat.c|" ${WRKSRC}/bgpd/Makefile
	@${REINPLACE_CMD} -e "s|sys/hash.h|hash.h|"	\
		${WRKSRC}/bgpd/rde_attr.c		\
		${WRKSRC}/bgpd/rde_rib.c		\
		${WRKSRC}/bgpd/rde_update.c
	@${REINPLACE_CMD} -e "s|rtm_fmask|rtm_use|" ${WRKSRC}/bgpd/kroute.c
	@${REINPLACE_CMD} -e "s|RTLABEL_LEN|PFTABLE_LEN|" ${WRKSRC}/bgpd/bgpd.h
	@${REINPLACE_CMD} -e "s|ulong|unsigned\ long|" ${WRKSRC}/bgpctl/irr_parser.c

do-build:
.for i in ${SUBDIRS}
	cd ${WRKSRC}/$i; make COPTS="${COPTS}"
.endfor

do-install:
.for i in ${SUBDIRS}
	cd ${WRKSRC}/$i; make install ${MAKE_ENV}
.endfor

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800059
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>
