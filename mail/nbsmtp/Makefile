# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	nbsmtp
PORTVERSION=	1.00
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Simple program for outgoing SMTP delivery

LICENSE=	GPLv2

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--enable-ssl --enable-ipv6

PLIST_FILES=	bin/nbsmtp man/man5/nbsmtprc.5.gz man/man8/nbsmtp.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nbsmtprc.5 ${STAGEDIR}${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/nbsmtp.8 ${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
