# New ports collection makefile for:	fdm
# Date created:		25 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fdm
PORTVERSION=	0.5
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Fetches and delivers mail

PLIST_FILES=	bin/fdm etc/fdm.conf.sample
PORTDOCS=	README

CFLAGS=	-I/usr/include/openssl

MAN1=	fdm.1
MAN5=	fdm.conf.5

post-install:
	@${INSTALL_DATA} ${WRKSRC}/fdm.conf ${PREFIX}/etc/fdm.conf.sample
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	does not compile on 4.x
.endif

.include <bsd.port.post.mk>
