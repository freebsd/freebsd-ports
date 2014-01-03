# Created by: LEVAI Daniel <leva@ecentrum.hu>
# $FreeBSD$

PORTNAME=	kc
PORTVERSION=	2.3.2
CATEGORIES=	security
MASTER_SITES=	http://github.com/levaidaniel/${PORTNAME}/archive/${PORTVERSION}.tar.gz?dummy=/

MAINTAINER=	leva@ecentrum.hu
COMMENT=	Console based password storing application

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libxml2.so:${PORTSDIR}/textproc/libxml2 \
		libpcre.so:${PORTSDIR}/devel/pcre

USES=		pkgconfig uidfix

PLIST_FILES=	bin/kc man/man1/kc.1.gz

MAKE_ENV+=	HAVE_PCRE=yes

post-patch:
	@${REINPLACE_CMD} -e 's|pkg-config|${LOCALBASE}/bin/pkgconf|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
