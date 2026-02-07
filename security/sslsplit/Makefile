PORTNAME=	sslsplit
DISTVERSION=	0.5.5
PORTREVISION=	3
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
MAKE_ENV=	MANDIR=${PREFIX}/share/man INSTALLUID=${UID} INSTALLGID=${GID}

PLIST_FILES=	bin/sslsplit share/man/man1/sslsplit.1.gz \
		share/man/man5/sslsplit.conf.5.gz \
		"@sample %%ETCDIR%%/sslsplit.conf.sample"

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/sslsplit

.include <bsd.port.mk>
