# ports collection makefile for: 		mixminion
# Date created: 				2004.06.11
# Whom:						freebsd-ports@rikrose.net
#
# $FreeBSD$
#

PORTNAME=	Mixminion
PORTVERSION=	0.0.7.1
CATEGORIES=	mail security
MASTER_SITES=	http://www.mixminion.net/dist/${PORTVERSION}/ \
		ftp://ftp.aha.ru/pub/FreeBSD/ports/distfiles/ \
		http://www.mirrors.wiretapped.net/security/cryptography/apps/mail/mixminion/0.0.7.1/

MAINTAINER=	freebsd-ports@rikrose.net
COMMENT=	A Type III Anonymous Remailer

USE_OPENSSL=	yes
USE_REINPLACE=	yes
USE_PYTHON=	2.0+

MAN1=	mixminion.1
MAN5=	mixminiond.conf.5 mixminionrc.5
MAN8=	mixminiond.8

post-patch:
	@${REINPLACE_CMD} -e "s|share/man|man|g" ${WRKSRC}/setup.py

.include <bsd.port.mk>
