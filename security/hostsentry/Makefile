# New ports collection makefile for:   hostsentry
# Date created:        7 February 2003
# Whom:                Andre Ramos <andre.ramos@netcabo.pt>
#
# $FreeBSD$
#

PORTNAME=	hostsentry
PORTVERSION=	0.02
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.netsys.com/len/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Login Anomaly Detector

RUN_DEPENDS=	${LOCALBASE}/bin/python:${PORTSDIR}/lang/python

post-install:
.if !defined(NOPORTSDOCS)
	${MKDIR} ${PREFIX}/share/doc/hostsentry
	${INSTALL_DATA} ${WRKSRC}/README.BUGS \
	${WRKSRC}/README.credits \
	${WRKSRC}/README.install \
	${WRKSRC}/README.intro \
	${WRKSRC}/README.modules \
	${WRKSRC}/README.paper \
	${WRKSRC}/README.technical \
	${WRKSRC}/README.why_python \
	${WRKSRC}/README.wtmp \
	${PREFIX}/share/doc/hostsentry
.endif

	${INSTALL_DATA} ${WRKSRC}/hostsentry.conf \
	${PREFIX}/etc/hostsentry.conf

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
