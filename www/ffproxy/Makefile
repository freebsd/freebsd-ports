# New ports collection makefile for: 	ffproxy
# Date created:				Jul 20 2003
# Whom:                			Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	ffproxy
PORTVERSION=	1.5.1
CATEGORIES=	www
MASTER_SITES=	http://faith.eu.org/${PORTNAME}/

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Filtering HTTP proxy server

USE_REINPLACE=	yes

MAN5=	${PORTNAME}.conf.5
MAN7=	${PORTNAME}.quick.7
MAN8=	${PORTNAME}.8

post-patch:
	${REINPLACE_CMD} -e \
		's|/etc|${PREFIX}/etc|g ; \
		s|/usr/local|${PREFIX}|g ; \
		s|^CFLAGS =|CFLAGS +=|g ; \
		s|/var/ffproxy|${DOCSDIR}|g' \
			${WRKSRC}/Makefile
	${REINPLACE_CMD} -e \
		's|/etc|${PREFIX}/etc|g' \
			${WRKSRC}/${PORTNAME}.8 \
			${WRKSRC}/${PORTNAME}.conf.5

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 \
		${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.conf.5 \
		${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.quick.7 \
		${PREFIX}/man/man7
	${INSTALL_DATA} ${WRKSRC}/sample.config \
		${PREFIX}/etc/ffproxy.conf.sample
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/db
	${MKDIR} ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/html/* ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/db/* ${DOCSDIR}/db
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
