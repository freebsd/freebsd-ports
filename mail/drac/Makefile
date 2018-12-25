# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	drac
PORTVERSION=	1.12
PORTREVISION=	9
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cc.umanitoba.ca/src/ \
		http://atreides.freenix.no/~anders/ \
		ftp://totem.fix.no/pub/mirrors/misc/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dynamic Relay Authorization Control, a POP-before-SMTP implementation

DEPRECATED=	Unmaintained upstream since 2003
EXPIRATION_DATE=	2019-01-15

PLIST_FILES=	sbin/rpc.dracd include/drac.h lib/libdrac.a \
		etc/dracd.allow-sample

USE_CSTD=	gnu89

MAKE_JOBS_UNSAFE=	yes
OPTIONS_DEFINE=		DB DOCS IPV6
OPTIONS_RADIO=		MUA
OPTIONS_RADIO_MUA=	POSTFIX EXIM
POSTFIX_DESC=		Use POSTFIX
EXIM_DESC=		Use EXIM
DB_DESC=		Use database with POSTFIX

.include <bsd.port.options.mk>

DEFS=		-DWITH_TI_RPC -DFLOCK_LOCK -DGETHOST -DDASH_C

.if ${PORT_OPTIONS:MPOSTFIX}
DEFS+=		-DTERM_KD
RUN_DEPENDS+=	postfix:mail/postfix
.if ${PORT_OPTIONS:MDB}
USES+=		bdb
.endif
.elif ${PORT_OPTIONS:MEXIM}
DEFS+=		-DTERM_KD -DREQ_HASH -DCIDR_KEY
RUN_DEPENDS+=	exim:mail/exim
.endif

NO_WRKSUBDIR=	yes
USE_RC_SUBR=	dracd

.if ${PORT_OPTIONS:MDOCS}
PLIST_FILES+=	man/man3/dracauth.3.gz man/man1/rpc.dracd.1.gz
.endif

.if defined(WITH_TI_RPC)
DEFS+=	-DTI_RPC
.else
DEFS+=	-DSOCK_RPC
.endif

.if defined(WITH_FOREGROUND)
DEFS+=	-DRPC_SVC_FG
.endif

MAKE_ARGS+=	DEFS="${DEFS}"

pre-everything::
.if ${PORT_OPTIONS:MIPV6}
	@${ECHO_MSG} "============================================================="
	@${ECHO_MSG} "It is IPv6 non-correspondence."
	@${ECHO_MSG} "After it understands, it is possible to use it with IPv4."
	@${ECHO_MSG} "============================================================="
	@${ECHO_MSG}
.endif
	@${ECHO_MSG} "============================================================="
	@${ECHO_MSG} "For databases compatible with other MTAs than sendmail, use:"
	@${ECHO_MSG}
	@${ECHO_MSG} "mail/postfix"
	@${ECHO_MSG} "mail/exim"
	@${ECHO_MSG}
	@${ECHO_MSG} "Define WITH_FOREGROUND to make the rpc.dracd daemon stay in"
	@${ECHO_MSG} "foreground instead of detaching itself. This breaks the"
	@${ECHO_MSG} "startup script."
	@${ECHO_MSG} "============================================================="

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/rpc.dracd.1m

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/rpc.dracd ${STAGEDIR}${PREFIX}/sbin/
	@${INSTALL_DATA} ${WRKSRC}/drac.h ${STAGEDIR}${PREFIX}/include/
	@${INSTALL_DATA} ${WRKSRC}/libdrac.a ${STAGEDIR}${PREFIX}/lib/
	@${INSTALL_DATA} ${WRKSRC}/dracd.allow-sample \
		${STAGEDIR}${PREFIX}/etc/
.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL_MAN} ${WRKSRC}/dracauth.3 ${STAGEDIR}${PREFIX}/man/man3/
	@${INSTALL_MAN} ${WRKSRC}/rpc.dracd.1m \
		${STAGEDIR}${PREFIX}/man/man1/rpc.dracd.1
.endif

.include <bsd.port.mk>
