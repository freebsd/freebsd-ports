# New ports collection makefile for:	pptpclient
# Date created:		19 June 1999
# Whom:			John Polstra <jdp@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=		pptpclient
PORTVERSION=		1.5.0
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pptpclient
DISTNAME=		pptp-linux-1.5.0

MAINTAINER=	thomas@cuivre.fr.eu.org
COMMENT=	PPTP client for establishing a VPN link with an NT server

USE_GETOPT_LONG=yes

MAN8=	pptp.8

.include <bsd.port.pre.mk>

MAKE_ARGS=	DEBUG=""
.if ${OSVERSION} < 500041
MAKE_ARGS+=	INCLUDE="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pptp ${PREFIX}/sbin
	${MKDIR} ${PREFIX}/share/examples/pptpclient
	${INSTALL_DATA} ${FILESDIR}/README ${PREFIX}/share/examples/pptpclient
	${INSTALL_DATA} ${FILESDIR}/ppp.conf ${PREFIX}/share/examples/pptpclient
	${INSTALL_MAN} ${WRKSRC}/pptp.8 ${PREFIX}/man/man8

.include <bsd.port.post.mk>
