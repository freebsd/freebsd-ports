PORTNAME=	sslsplit
PORTVERSION=	0.5.5
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://mirror.roe.ch/rel/sslsplit/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Transparent and scalable SSL/TLS interception
WWW=		https://www.roe.ch/SSLsplit

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED= Upstream has mentioned inactivity with the possibility of returning

LIB_DEPENDS=	libevent.so:devel/libevent \
		libnet.so:net/libnet

USES=		gmake pkgconfig tar:bzip2 uidfix ssl
MAKEFILE=	GNUmakefile
MAKE_ENV=	MANDIR=${PREFIX}/man INSTALLUID=${UID} INSTALLGID=${GID}
PLIST_FILES=	bin/sslsplit man/man1/sslsplit.1.gz \
		man/man5/sslsplit.conf.5.gz \
		"@sample %%ETCDIR%%/sslsplit.conf.sample"

.include <bsd.port.options.mk>

.if ( ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400092 && ${SSL_DEFAULT} == base ) || ${SSL_DEFAULT:Mopenssl} || ${SSL_DEFAULT:Mopenssl3*}
IGNORE_SSL=	base openssl openssl31
IGNORE_SSL_REASON=	error: undefined symbol: ERR_GET_FUNC which were deprecated in OpenSSL 3.0.0 and later
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/sslsplit

.include <bsd.port.mk>
