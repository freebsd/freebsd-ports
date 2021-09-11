# Created by: Sergei Vyshenski <svysh.fbsd@gmail.com>

PORTNAME=	openca-tools-forked
PORTVERSION=	1.4.0
DISTVERSIONPREFIX=	v
PORTREVISION=	4
CATEGORIES=	security

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Tools to deal with SCEP and PKCS7 messages

LICENSE=	APACHE20

DEPRECATED=	Use modern port security/libscep instead
EXPIRATION_DATE=	2021-09-30

USES=		gmake perl5 ssl
BROKEN_SSL=	openssl

USE_GITHUB=	yes
GH_ACCOUNT=	openxpki

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-openssl-prefix=${OPENSSLBASE}

# security/openssl already has a verify.1 manpage.
post-install:
.for f in sign.1 verify.1
	@${MV} ${STAGEDIR}${PREFIX}/man/man1/${f} ${STAGEDIR}${PREFIX}/man/man1/openca-${f}
.endfor

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200000 && ${SSL_DEFAULT} == base
BROKEN=	OpenSSL-1.1.1 not supported by the upstream
.endif

.include <bsd.port.post.mk>
