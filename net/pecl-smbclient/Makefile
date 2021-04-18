PORTNAME=	smbclient
PORTVERSION=	1.0.6
CATEGORIES=	net pear

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Smbclient wrapper extension

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		php:pecl samba:lib

CONFIGURE_ARGS=	--with-libsmbclient=${LOCALBASE}
CPPFLAGS+=	-I${SAMBAINCLUDES}
LDFLAGS+=	-L${SAMBALIBS}

.include <bsd.port.mk>
