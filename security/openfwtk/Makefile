# New ports collection makefile for:	openfwtk
# Date created:				12 Oct 2007
# Whom:					Anton Karpov <toxa@toxahost.ru>
#
# $FreeBSD$

PORTNAME=	openfwtk
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Release%20${PORTVERSION}
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Application proxy toolkit which inherits the ideology of TIS fwtk

LICENSE=	BSD

OPTIONS=	WATCH "Install fw-watch GUI (require TCL/TK!)" off

WRKSRC=		${WRKDIR}/fwtk
WRKSRC_WATCH=	${WRKDIR}/fw_watch
WRKSRC_MILTER=	${WRKDIR}/libci_milter

MAKE_JOBS_UNSAFE=yes

SUB_FILES=	pkg-message
MANCOMPRESSED=	no

.include <bsd.port.options.mk>

.if defined(WITH_WATCH)
USE_TK_WRAPPER=	yes
PLIST_SUB+=	WATCH=""
.else
PLIST_SUB+=	WATCH="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 900007
BROKEN=		fails to build with new utmpx
.endif

post-patch:
.for conf in auth/authadduser.sh reports/summ_resources.sh \
	reports/daily_report reports/frequentcheck \
	reports/frequentcheck.sh squid-gw/squid-gw.restart
	@${REINPLACE_CMD} -e \
		's|/etc/openfwtk.conf|${PREFIX}/etc/openfwtk.conf|g' ${WRKSRC}/${conf}
.endfor
.for wish in fileselect.tcl fw_watch
	@${REINPLACE_CMD} -e \
		's|/usr/bin/|${LOCALBASE}/bin/|g' ${WRKSRC_WATCH}/${wish}
.endfor
	@${REINPLACE_CMD} -e \
		'/^CC/s|=.*|= ${CC}|g ; \
		 /^COPT/s|=.*|= ${CFLAGS}|g' ${WRKSRC_MILTER}/Makefile
	@${REINPLACE_CMD} -e \
		'/^CC/s|=.*|= ${CC}|g ; \
		 /^COPT/s|-std=c99|${CFLAGS}|g' ${WRKSRC}/configs/FreeBSD

pre-build:
	@(cd ${WRKSRC_MILTER}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

pre-install:
	@${MKDIR} ${ETCDIR}

post-install:
.if defined(WITH_WATCH)
	@${MKDIR} ${PREFIX}/share/fw_watch
.for data in fileselect.tcl fw_watch newsb.tcl searchbox.tcl taputils.tcl
	${INSTALL_DATA} ${WRKSRC_WATCH}/${data} ${PREFIX}/share/fw_watch
.endfor
.endif
	${ECHO_CMD} "root@`hostname`" > ${ETCDIR}/admin
	@${CAT} ${PKGMESSAGE}

.include "Makefile.man"
.include <bsd.port.post.mk>
