PORTNAME=	sslproxy
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.10
PORTEPOCH=	1
CATEGORIES=	security

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Transparent and scalable SSL/TLS interception
WWW=		https://github.com/sonertari/SSLproxy

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libevent.so:devel/libevent \
		libnet.so:net/libnet

USES=		gmake pkgconfig sqlite ssl uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	sonertari
GH_PROJECT=	SSLproxy

MAKEFILE=	GNUmakefile
MAKE_ENV=	INSTALLUID=${UID} INSTALLGID=${GID}

PLIST_FILES=	bin/sslproxy share/man/man1/sslproxy.1.gz \
		share/man/man5/sslproxy.conf.5.gz \
		"@sample etc/sslproxy.conf.sample"

post-patch:
	@${REINPLACE_CMD} -e \
		's|^EXAMPLESDIR.*|EXAMPLESDIR?=	etc|g' \
			${WRKSRC}/Mk/main.mk

.include <bsd.port.mk>
