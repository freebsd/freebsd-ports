# New ports collection makefile for:	pptpclient
# Date created:		19 June 1999
# Whom:			John Polstra <jdp@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=		pptpclient
PORTVERSION=		1.1.0
PORTREVISION=		1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pptpclient
DISTNAME=		pptp-linux-1.1.0
DISTFILES=		pptp-linux-1.1.0-1.tar.gz

MAINTAINER=	thomas@cuivre.fr.eu.org
COMMENT=	PPTP client for establishing a VPN link with an NT server

USE_GETOPT_LONG=yes

.include <bsd.port.pre.mk>

MAKE_ARGS=	DEBUG=""
.if ${OSVERSION} < 500041
MAKE_ARGS+=	INCLUDE="${CPPFLAGS}" \
		LIBS="${LDFLAGS}"
.endif

GUNZIP_CMD=		${GZIP_CMD} ${EXTRACT_BEFORE_ARGS}

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@(cd ${WRKDIR} && \
	${GUNZIP_CMD} ${_DISTDIR}/${DISTFILES} | tar -xf - && \
	${GUNZIP_CMD} `basename ${DISTFILES} .tar.gz`/${DISTNAME}.tar.gz | \
	tar -xf -)

do-install:
	cd ${WRKSRC} ; ${INSTALL_PROGRAM} pptp ${PREFIX}/sbin
	${MKDIR} ${PREFIX}/share/examples/pptpclient
	${INSTALL_DATA} ${FILESDIR}/README ${PREFIX}/share/examples/pptpclient
	${INSTALL_DATA} ${FILESDIR}/ppp.conf ${PREFIX}/share/examples/pptpclient

.include <bsd.port.post.mk>
