PORTNAME=	sslproxy
PORTVERSION=	0.8.3
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	security

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Transparent and scalable SSL/TLS interception

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libevent.so:devel/libevent \
		libnet.so:net/libnet

USES=		gmake pkgconfig uidfix sqlite ssl
USE_GITHUB=	yes
GH_ACCOUNT=	sonertari
GH_PROJECT=	SSLproxy

MAKEFILE=	GNUmakefile
MAKE_ENV=	DESTDIR=${STAGEDIR} MANDIR=man INSTALLUID=${UID} INSTALLGID=${GID}
PLIST_FILES=	bin/sslproxy man/man1/sslproxy.1.gz man/man5/sslproxy.conf.5.gz \
		"@sample etc/sslproxy.conf.sample"

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/Mk/main.mk

.include <bsd.port.mk>
