# Created by: Thomas Quinot <thomas@cuivre.fr.eu.org>
# $FreeBSD$

PORTNAME=	calife
PORTVERSION=	3.0.6
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://assets.keltia.net/calife/

MAINTAINER=	roberto@FreeBSD.org
COMMENT=	Lightweight alternative to sudo

LICENSE=	GPLv2

USES=		tar:xz

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-etcdir=${PREFIX}/etc

CONFIGURE_ARGS+=	--with-pam

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/calife ${STAGEDIR}${PREFIX}/bin/calife
	${INSTALL_MAN} ${WRKSRC}/calife.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/calife.auth.5 ${STAGEDIR}${MAN5PREFIX}/man/man5
	${INSTALL_DATA} ${WRKSRC}/calife.auth-dist ${STAGEDIR}${PREFIX}/etc/calife.auth.sample
	${INSTALL_DATA} ${WRKSRC}/pam/freebsd9 ${STAGEDIR}${PREFIX}/etc/pam.d/calife.sample

.include <bsd.port.mk>
