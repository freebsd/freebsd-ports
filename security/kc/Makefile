# Created by: LEVAI Daniel <leva@ecentrum.hu>
# $FreeBSD$

PORTNAME=	kc
PORTVERSION=	2.3.2
PORTREVISION=	2
CATEGORIES=	security

MAINTAINER=	leva@ecentrum.hu
COMMENT=	Console based password storing application

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxml2.so:textproc/libxml2 \
		libpcre.so:devel/pcre

USES=		libedit pkgconfig uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	levaidaniel

PLIST_FILES=	bin/kc man/man1/kc.1.gz

MAKE_ENV+=	HAVE_PCRE=yes

post-patch:
	@${REINPLACE_CMD} -e 's|pkg-config|${LOCALBASE}/bin/pkgconf|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
