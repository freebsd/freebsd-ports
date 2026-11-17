PORTNAME=	sslproxy
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.1
PORTEPOCH=	1
CATEGORIES=	security

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Transparent and scalable SSL/TLS interception
WWW=		https://github.com/sonertari/SSLproxy

LICENSE=	BSD-2-Clause LGPL-3.0-only MIT
LICENSE_COMB=	multi
LICENSE_FILE_BSD-2-Clause=	${WRKSRC}/LICENSE
LICENSE_FILE_LGPL-3.0-only=	${WRKSRC}/src/aho_corasick_template.h
LICENSE_FILE_MIT=		${WRKSRC}/src/khash.h

LIB_DEPENDS=	libevent.so:devel/libevent \
		libnet.so:net/libnet \
		libnghttp2.so:www/libnghttp2

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
