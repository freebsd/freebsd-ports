# Created by: Sergei Vyshenski <svysh.fbsd@gmail.com>
# $FreeBSD$

PORTNAME=	openca-tools-forked
PORTVERSION=	1.4.0
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	security

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Tools to deal with SCEP and PKCS7 messages

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	openxpki

GNU_CONFIGURE=	yes
USES=		gmake perl5
USE_OPENSSL=	yes

# security/openssl already has a verify.1 manpage.
post-stage:
.for f in sign.1 verify.1
	@${MV} ${STAGEDIR}${PREFIX}/man/man1/${f} ${STAGEDIR}${PREFIX}/man/man1/openca-${f}
.endfor

.include <bsd.port.mk>
