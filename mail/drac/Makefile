# New ports collection makefile for:	drac
# Date created:			07 January 2001
# Whom:				Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	drac
PORTVERSION= 	1.11
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cc.umanitoba.ca/src/ \
		http://www.freenix.no/~anders/ \
		ftp://totem.fix.no/pub/mirrors/misc/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	anders@fix.no

.if defined(WITH_POSTFIX_DB3)
LIB_DEPENDS+=	db3.2:${PORTSDIR}/databases/db3
.endif

NO_WRKSUBDIR=	yes

MAN3=		dracauth.3
MAN1=		rpc.dracd.1

.include <bsd.port.pre.mk>
.if ${OSVERSION} >= 500018
MAKE_ARGS+=	-DWITH_TI_RPC
.endif

pre-everything:
	@${ECHO} "================================================================================"
	@${ECHO} "For databases compatible with other MTAs than sendmail, use:"
	@${ECHO}
	@${ECHO} "WITH_POSTFIX=yes	(Postfix)"
	@${ECHO} "WITH_POSTFIX_DB3=yes	(Postfix with DB3 database maps)"
	@${ECHO} "WITH_EXIM=yes		(Exim)"
	@${ECHO}
	@${ECHO} "Define WITH_FOREGROUND to make the rpc.dracd daemon stay in foreground instead"
	@${ECHO} "of detaching itself. This breaks the startup script."
	@${ECHO} "================================================================================"

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/rpc.dracd.1m

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/rpc.dracd ${PREFIX}/sbin/
	@${INSTALL_DATA} ${WRKSRC}/drac.h ${PREFIX}/include/
	@${INSTALL_DATA} ${WRKSRC}/libdrac.a ${PREFIX}/lib/
.if !defined(NOPORTDOCS)
	@${INSTALL_MAN} ${WRKSRC}/dracauth.3 ${PREFIX}/man/man3/
	@${INSTALL_MAN} ${WRKSRC}/rpc.dracd.1m ${PREFIX}/man/man1/rpc.dracd.1
.endif
	@if [ ! -f ${PREFIX}/etc/rc.d/dracd.sh.sample ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/dracd.sh.sample startup file."; \
		${INSTALL_SCRIPT} -m 751 ${FILESDIR}/dracd.sh ${PREFIX}/etc/rc.d/dracd.sh.sample; \
	fi

.include <bsd.port.post.mk>
