# New ports collection makefile for:	pptpclient
# Date created:		19 June 1999
# Whom:			John Polstra <jdp@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	pptpclient
PORTVERSION=	1.0.3
CATEGORIES=	net
MASTER_SITES=	http://prdownloads.sourceforge.net/pptpclient/
DISTNAME=	pptp-linux-1.0.3
DISTFILES=	pptp-linux-1.0.3-1.tar.gz

MAINTAINER=	thomas@cuivre.fr.eu.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

MAKE_ARGS=	DEBUG="" \
		INCLUDE="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lgnugetopt" \
		pptp

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

.include <bsd.port.mk>
