# New ports collection makefile for:	imap-uw
# Version required:	4.7c2
# Date created:		9 Jan 1997
# Whom:			pst
#
# $FreeBSD$
#

PORTNAME=	imap-uw
PORTVERSION=	4.7c
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cac.washington.edu/imap/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.cac.washington.edu/mail/ \
		http://mirror.nucba.ac.jp/mirror/imap/ \
		ftp://ftp.uni-halle.de/pub/mail/pine/
DISTNAME=	imap-${PORTVERSION}
EXTRACT_SUFX=	.tar.Z
DISTFILES=	${DISTNAME}2${EXTRACT_SUFX} \
		imap-utils${EXTRACT_SUFX}

MAINTAINER=	imap-uw@freebsd.ady.ro

LIB_DEPENDS=	c-client4.7:${PORTSDIR}/mail/cclient

Y2K=		http://www.washington.edu/imap/IMAP-FAQs/FAQ-00002.html

PAMAUTH?=	yes
.if ${PAMAUTH} != "no"
ALL_TARGET=	bfp
.else
ALL_TARGET=	bsf
.endif
MAN8=		ipopd.8 imapd.8

.include <bsd.port.pre.mk>

pre-extract:
.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
	@${SH} ${PKGDIR}/INSTALL foo PRE-INSTALL || ${FALSE}
.endif

post-build:
	@(cd ${WRKDIR}/mlock; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} all)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/imapd/imapd ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/ipopd/ipop2d ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/ipopd/ipop3d ${PREFIX}/libexec
	${INSTALL} ${COPY} ${STRIP} -o ${BINOWN} -g mail -m 2711 \
		${WRKDIR}/mlock/mlock ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/mtest/mtest ${PREFIX}/bin/mboxtest
	${INSTALL_MAN} \
		${WRKSRC}/src/imapd/imapd.8c ${PREFIX}/man/man8/imapd.8
	${INSTALL_MAN} \
		${WRKSRC}/src/ipopd/ipopd.8c ${PREFIX}/man/man8/ipopd.8

.include <bsd.port.post.mk>
