# New ports collection makefile for:	l2tpd
# Date created:				22 October 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	l2tpd
PORTVERSION=	0.64
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sobomax@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_REINPLACE=	yes

MAN8=	l2tpd.8

do-configure:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/l2tpd.8 \
		${WRKSRC}/doc/l2tpd.conf.sample

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/l2tpd ${PREFIX}/bin
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/l2tpd.8 ${PREFIX}/man/man8
	${MKDIR} ${PREFIX}/etc/l2tpd
	${INSTALL_DATA} ${WRKSRC}/doc/l2tpd.conf.sample ${PREFIX}/etc/l2tpd
	${INSTALL_DATA} ${WRKSRC}/doc/l2tp-secrets.sample ${PREFIX}/etc/l2tpd

.include <bsd.port.mk>
