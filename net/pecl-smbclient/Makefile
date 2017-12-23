# $FreeBSD$

PORTNAME=	smbclient
PORTVERSION=	0.9.0
PORTREVISION=	3
CATEGORIES=	net pear

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Smbclient wrapper extension

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		php:pecl samba:lib

CONFIGURE_ARGS=	--with-libsmbclient=${LOCALBASE}
CPPFLAGS+=	-I${SAMBAINCLUDES}
LDFLAGS+=	-L${SAMBALIBS}

.include <bsd.port.mk>
