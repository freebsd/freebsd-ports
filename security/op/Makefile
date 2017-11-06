# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	op
PORTVERSION=	1.32
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://swapoff.org/files/op/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Controlled privilege escalation tool

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
CONFLICTS_INSTALL=	security/1password-client

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/op.d
	${INSTALL_DATA} -m 0600 ${WRKSRC}/${PORTNAME}.conf \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
