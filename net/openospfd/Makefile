# New ports collection makefile for:	openospfd-devel
# Date created:				Mar 08 2005
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openospfd-devel
PORTVERSION=	${SNAPSHOT}
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.openbsd.org/pub/OpenBSD/OpenOSPFD/:openbsd \
		${MASTER_SITE_LOCAL:S/$/:freebsd/g}
MASTER_SITE_SUBDIR=	flz/openospfd/:freebsd
DISTFILES=	${PORTNAME}-${PORTVERSION}.tgz:freebsd \
		if_media.h:freebsd hash.h:freebsd
DIST_SUBDIR=	openospfd
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}.tgz

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Free implementation of the Open Shortest Path First Protocol

LIB_DEPENDS=	event-1.1a.1:${PORTSDIR}/devel/libevent

CONFLICTS=	zebra-0* quagga-0*

SNAPSHOT=	20060516
WRKSRC=		${WRKDIR}
MANCOMPRESSED=	yes
USE_RC_SUBR=	openospfd.sh
MAKE_ENV=	BINDIR="${PREFIX}/sbin" \
		MANDIR="${PREFIX}/man/man"
COPTS=		-I${LOCALBASE}/include -DMD5_DIGEST_LENGTH=16
LDADD=		-L${LOCALBASE}/lib -levent -lmd

PLIST_FILES=	sbin/ospfctl	\
		sbin/ospfd

MAN5=		ospfd.conf.5
MAN8=		ospfctl.8	\
		ospfd.8

SUBDIRS=	ospfd \
		ospfctl

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500037
IGNORE=		requires macros present in <sys/tree.h>
.endif

post-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/if_media.h ${WRKSRC}/ospfctl/
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/hash.h ${WRKSRC}/ospfd/

post-patch:
	@${REINPLACE_CMD} -e "s|sys/hash.h|hash.h|" ${WRKSRC}/ospfd/lsupdate.c
	@${REINPLACE_CMD} -e "s|<net/if_media.h>|\"if_media.h\"|" ${WRKSRC}/ospfctl/ospfctl.c
	@${REINPLACE_CMD} -e "s|rtm_fmask|rtm_use|" ${WRKSRC}/ospfd/kroute.c
	@${REINPLACE_CMD} -e "/rc.conf.local/d" ${WRKSRC}/ospfd/ospfd.conf.5
	@${REINPLACE_CMD} -e "s|/etc|${PREFIX}/etc|g" \
		${WRKSRC}/ospfd/ospfd.h \
		${WRKSRC}/ospfd/ospfd.8 \
		${WRKSRC}/ospfd/ospfd.conf.5
	@${REINPLACE_CMD} -e "s|__dead||"	\
		${WRKSRC}/ospfd/log.h \
		${WRKSRC}/ospfd/ospfd.c \
		${WRKSRC}/ospfctl/ospfctl.c

do-build:
.for i in ${SUBDIRS}
	cd ${WRKSRC}/$i; make COPTS="${COPTS}" LDADD="${LDADD}"
.endfor

do-install:
.for i in ${SUBDIRS}
	cd ${WRKSRC}/$i; make install ${MAKE_ENV} LOCALBASE=${LOCALBASE}
.endfor

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
