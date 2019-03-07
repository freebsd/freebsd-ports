# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	op
PORTVERSION=	1.34
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Controlled privilege escalation tool

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	dagwieers

GNU_CONFIGURE=	yes
CONFLICTS_INSTALL=	security/1password-client

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/op.d
	${MV} ${STAGEDIR}${PREFIX}/etc/op.conf-dist \
		${STAGEDIR}${PREFIX}/etc/op.conf.sample

.include <bsd.port.mk>
