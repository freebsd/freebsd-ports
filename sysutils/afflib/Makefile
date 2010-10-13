# Ports collection makefile for: afflib
#
# Date created: 	15/02/2008
# Whom: 		Chris Calvey <chris@securityforensics.co.uk>
#
# $FreeBSD$
#

PORTNAME=	afflib
PORTVERSION=	3.6.3
CATEGORIES=	sysutils
MASTER_SITES=	http://afflib.org/downloads/ \
		http://www.c-s.li/ports/

MAINTAINER=	c-s@c-s.li
COMMENT=	The Advanced Forensics Format library and utilities

LIB_DEPENDS=	fuse:${PORTSDIR}/sysutils/fusefs-libs \
 		expat:${PORTSDIR}/textproc/expat2 \
		curl:${PORTSDIR}/ftp/curl

LICENSE=	BSD

USE_LDCONFIG=	yes
USE_OPENSSL=	yes
USE_ICONV =	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack
USE_AUTOTOOLS=	autoconf:267
CONFIGURE_ARGS=	--enable-s3=yes --libdir=${PREFIX}
CONFIGURE_ENV=	CPPFLAGS='-DFUSE_USE_VERSION=26' \
		LDFLAGS='${PTHREAD_LIBS}'
CFLAGS+=	${PTHREAD_LIBS}
MAKE_JOBS_SAFE=	yes

MAN1=		affcat.1

post-patch:
	@${REINPLACE_CMD} -e 's|2.61|2.67|g' ${WRKSRC}/aclocal.m4
	@${REINPLACE_CMD} -e 's|(libdir)|(libdir)/lib|' \
		 ${WRKSRC}/lib/Makefile.in
	@${REINPLACE_CMD} -e 's|(libdir)|(libdir)/libdata|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
