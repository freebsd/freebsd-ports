# New ports collection makefile for:    ez-ipupdate
# Date created:         24 July 2002
# Whom:                 se
#
# $FreeBSD$
#

PORTNAME=	ez-ipupdate
PORTVERSION=	3.0.11b7
CATEGORIES=	net
MASTER_SITES=	http://gusnet.cx/proj/ez-ipupdate/dist/

MAINTAINER=	se@FreeBSD.org

GNU_CONFIGURE=	yes

post-install:
	${MKDIR} ${PREFIX}/share/examples/ez-ipupdate
	for f in ${WRKSRC}/example-*.conf; \
	do \
		${INSTALL_DATA} $$f ${PREFIX}/share/examples/ez-ipupdate/; \
	done
	${INSTALL_DATA} ${WRKSRC}/example.conf \
			${PREFIX}/etc/ez-ipupdate.conf.sample

.include <bsd.port.mk>
