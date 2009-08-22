# New ports collection makefile for:	l2tpd
# Date created:				22 October 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	l2tpd
PORTVERSION=	0.69
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/L2TPd/${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	An implementation of the layer two tunneling protocol

MAN5=	l2tp-secrets.5 l2tpd.conf.5
MAN8=	l2tpd.8

.include <bsd.port.pre.mk>

do-configure:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/doc/l2tpd.8 \
		${WRKSRC}/doc/l2tpd.conf.sample ${WRKSRC}/doc/l2tp-secrets.5 \
		${WRKSRC}/doc/l2tpd.conf.5

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/l2tpd ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	${INSTALL_MAN} ${WRKSRC}/doc/l2tpd.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/doc/l2tp-secrets.5 ${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/doc/l2tpd.conf.5 ${PREFIX}/man/man5
	${MKDIR} ${PREFIX}/etc/l2tp
	${INSTALL_DATA} ${WRKSRC}/doc/l2tpd.conf.sample ${PREFIX}/etc/l2tp
	${INSTALL_DATA} ${WRKSRC}/doc/l2tp-secrets.sample ${PREFIX}/etc/l2tp

.include <bsd.port.post.mk>
