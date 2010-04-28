# New ports collection makefile for:	spread
# Date created:		11 June 2001
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	spread4
PORTVERSION=	4.1.0
CATEGORIES=	net perl5
MASTER_SITES=	LOCAL/wen
DISTNAME=	spread-src-${PORTVERSION}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	The Spread Group Communication System, a network toolkit

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_RC_SUBR=	spread.sh
USE_LDCONFIG=	yes
ALL_TARGET=	all

WRKSRC=		${WRKDIR}/spread-src-${PORTVERSION}

PKGMESSAGE=	${WRKSRC}/license.txt

DOCFILES=	DynamicConfiguration.txt Flush_or_SpreadAPI.txt \
		MultithreadedClients.txt Short_Buffer_Handling.txt \
		TODO PORTING
MAN1=		spflooder.1 spmonitor.1 spread.1 sptuser.1 spuser.1
MAN3=		SP_connect.3 SP_disconnect.3 SP_equal_group_ids.3 \
		SP_error.3 SP_get_memb_info.3 SP_get_vs_set_members.3 \
		SP_get_vs_sets_info.3 SP_join.3 SP_kill.3 \
		SP_leave.3 SP_multicast.3 SP_multigroup_multicast.3 \
		SP_multigroup_scat_multicast.3 SP_poll.3 SP_receive.3 \
		SP_scat_get_memb_info.3 SP_scat_get_vs_set_members.3 \
		SP_scat_get_vs_sets_info.3 SP_scat_multicast.3 \
		SP_scat_receive.3 SP_version.3 libspread.3

.include <bsd.port.pre.mk>

post-extract:
		@${REINPLACE_CMD} -e 's|INSTALLSUBDIRS=daemon docs|INSTALLSUBDIRS=daemon|' \
		${WRKSRC}/Makefile.in

pre-install:
	${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/sample.spread.conf \
		${PREFIX}/etc/spread.conf.sample
	${INSTALL_DATA} ${WRKSRC}/docs/sample.spread.access_ip \
		${PREFIX}/etc/spread.access_ip.sample

.if !exists(${PREFIX}/etc/spread.conf)
	${INSTALL_DATA} ${WRKSRC}/docs/sample.spread.conf \
		${PREFIX}/etc/spread.conf
.endif

.if !exists(${PREFIX}/etc/spread.access_ip)
	${INSTALL_DATA} ${WRKSRC}/docs/sample.spread.access_ip \
		${PREFIX}/etc/spread.access_ip
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DOCSDIR}
.endfor
.endif

.for f in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/docs/${f} ${LOCALBASE}/man/man1/
.endfor

.for f in ${MAN3}
	${INSTALL_MAN} ${WRKSRC}/docs/${f} ${LOCALBASE}/man/man3/
.endfor

	@${CAT} ${PKGMESSAGE}
	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
