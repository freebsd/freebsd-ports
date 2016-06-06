# Created by: Felix Hanley <felix@userspace.com.au>
# $FreeBSD$

PORTNAME=	libnss-pgsql
PORTVERSION=	1.5.0
CATEGORIES=	net
MASTER_SITES=	PGSQL/projects/pgFoundry/sysauth/NSS/nss1.5.0-beta
DISTNAME=	${PORTNAME}-${PORTVERSION}-beta

MAINTAINER=	felix@userspace.com.au
COMMENT=	NSS module using a PostgreSQL database for backend

LICENSE=	GPLv2

BUILD_DEPENDS=	xmlto:textproc/xmlto

USES=		autoreconf gmake libtool pgsql tar:tgz
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc --includedir=${PREFIX}/include --libdir=${PREFIX}/lib --with-docdir=${DOCSDIR}
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/conf/* ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} files/nsswitch.conf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
