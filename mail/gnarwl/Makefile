PORTNAME=	gnarwl
PORTVERSION=	3.6
PORTREVISION=	8
CATEGORIES=	mail
MASTER_SITES=	http://www.onyxbits.de/sites/default/files/download/15/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Email autoresponder that gets data from LDAP
WWW=		https://www.onyxbits.de/gnarwl

LICENSE=	GPLv2

LIB_DEPENDS=	libgdbm.so:databases/gdbm

USES=		iconv gmake groff ldap tar:tgz
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--with-docdir=${DOCSDIR} --localstatedir="${PREFIX}/var"
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib ${ICONV_LIB}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
