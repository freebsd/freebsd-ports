# New ports collection makefile for:	tac_plus
# Date created:		4 Mar 1997
# Whom:			Igor Vinokurov <igor@zynaps.ru>
#
# $FreeBSD$
#

PORTNAME=	tac_plus
PORTVERSION=	F4.0.4
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp-eng.cisco.com/pub/tacacs/
DISTNAME=	tac_plus.F4.0.4.alpha
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	marcus@FreeBSD.org

ALL_TARGET=	tac_plus
MAN1=		tac_plus.1

# To change the text displayed when users are prompted to enter
# a username, set appropriately TAC_CHANGE_PROMPT variable.
.if defined(TAC_CHANGE_PROMPT) && ${TAC_CHANGE_PROMPT} == YES
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-ba
.endif

# check expiration dates against 'expire' field of master.passwd file
.if defined(TAC_EXPIRE_MASTER_PASSWD) && ${TAC_EXPIRE_MASTER_PASSWD} == YES
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-bb
.endif

# finger output differs for CISCO IOS versions 11 and 12.
# Define version of your IOS (default is 11):
# Example: make TAC_IOS_VERSION=12
#
.if defined(TAC_IOS_VERSION)
CFLAGS+=	-DTAC_IOS_VERSION=${TAC_IOS_VERSION}
.else
CFLAGS+=	-DTAC_IOS_VERSION=11
.endif

.if exists(/usr/include/skey.h) && !defined(WITHOUT_SKEY)
MAKE_ENV+=	WITH_SKEY=1
.endif

.if exists(/usr/include/opie.h) && !defined(WITHOUT_OPIE)
MAKE_ENV+=	WITH_OPIE=1
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tac_plus ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/generate_passwd ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tac_plus.1 ${PREFIX}/man/man1/tac_plus.1
	${INSTALL_DATA} ${FILESDIR}/tac_plus.conf.example ${PREFIX}/etc/
	@if [ ! -f ${PREFIX}/etc/rc.d/tac_plus.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/tac_plus.sh startup file."; \
		${INSTALL_SCRIPT} -m 751 ${FILESDIR}/tac_plus.sh ${PREFIX}/etc/rc.d/tac_plus.sh; \
	fi
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/tac_plus
	${INSTALL_DATA} ${WRKSRC}/users_guide ${PREFIX}/share/doc/tac_plus
	${INSTALL_SCRIPT} ${WRKSRC}/convert.pl ${PREFIX}/share/doc/tac_plus
.endif

post-install:
	strip ${PREFIX}/sbin/tac_plus

.include <bsd.port.mk>
