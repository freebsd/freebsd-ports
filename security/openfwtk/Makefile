# New ports collection makefile for:	openfwtk
# Date created:				12 Oct 2007
# Whom:					Anton Karpov <toxa@toxahost.ru>
#
# $FreeBSD$

PORTNAME=	openfwtk
PORTVERSION=	2.0
CATEGORIES=	security
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Application proxy toolkit which inherits the ideology of TIS fwtk

WRKSRC=	${WRKDIR}/fwtk
WRKSRC_WATCH=	${WRKDIR}/fw_watch
WRKSRC_MILTER=	${WRKDIR}/libci_milter

OPTIONS=	WATCH "Install fw-watch GUI (require TCL/TK!)" off

SUB_FILES=	pkg-message
MANCOMPRESSED=	no

.include <bsd.port.pre.mk>

.if defined(WITH_WATCH)
PLIST_SUB+=	WATCH=""
RUN_DEPENDS+=	wish8.4:${PORTSDIR}/x11-toolkits/tk84
.else
PLIST_SUB+=	WATCH="@comment "
.endif

BUILD_DIRS=	${WRKSRC_MILTER} ${WRKSRC}

do-build:
.for i in ${BUILD_DIRS}
	(cd ${WRKDIR}/${i}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
.endfor

post-build:
	@${REINPLACE_CMD} -e 's|/etc/openfwtk.conf|${PREFIX}/etc/openfwtk.conf|g' \
		${WRKSRC}/reports/summ_resources.sh ${WRKSRC}/reports/daily_report \
		${WRKSRC}/reports/frequentcheck.sh ${WRKSRC}/reports/frequentcheck \
		${WRKSRC}/auth/authadduser.sh ${WRKSRC}/squid-gw/squid-gw.restart \
		${WRKSRC}/reports/daily_report ${WRKSRC}/reports/frequentcheck
pre-install:
	${MKDIR} ${ETCDIR}
post-install:
.if defined(WITH_WATCH)
	${MKDIR} ${PREFIX}/share/fw_watch
	@${REINPLACE_CMD} -e 's|/usr/bin/wish|${PREFIX}/bin/wish8.4|g' \
		${WRKSRC_WATCH}/fileselect.tcl \
		${WRKSRC_WATCH}/fw_watch \
		${WRKSRC_WATCH}/newsb.tcl \
		${WRKSRC_WATCH}/searchbox.tcl \
		${WRKSRC_WATCH}/taputils.tcl
	${CP} ${WRKSRC_WATCH}/fileselect.tcl ${PREFIX}/share/fw_watch/
	${CP} ${WRKSRC_WATCH}/fw_watch ${PREFIX}/share/fw_watch/
	${CP} ${WRKSRC_WATCH}/newsb.tcl ${PREFIX}/share/fw_watch/
	${CP} ${WRKSRC_WATCH}/searchbox.tcl ${PREFIX}/share/fw_watch/
	${CP} ${WRKSRC_WATCH}/taputils.tcl ${PREFIX}/share/fw_watch/
.endif
	${ECHO} "root@`hostname`" > ${ETCDIR}/admin
	@${CAT} ${PKGMESSAGE}

.include "Makefile.man"
.include <bsd.port.post.mk>
