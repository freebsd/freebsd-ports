# Created by: Chris Calvey <chris@securityforensics.co.uk>
# $FreeBSD$

PORTNAME=	afflib
PORTVERSION=	3.7.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://cloud.github.com/downloads/simsong/AFFLIBv3/ \
		http://www.c-s.li/ports/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced Forensics Format library and utilities

LICENSE=	BSD

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2 \
		libcurl.so:${PORTSDIR}/ftp/curl

USE_LDCONFIG=	yes
USE_OPENSSL=	yes
USES=		fuse pathfix iconv
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf
CONFIGURE_ARGS=	--enable-s3=yes --libdir=${PREFIX}
CPPFLAGS+=	-DFUSE_USE_VERSION=26

AUTOTOOLSFILES=	aclocal.m4

post-patch:
	@${REINPLACE_CMD} -e 's|2.61|%%AUTOCONF_VERSION%%|g' ${WRKSRC}/aclocal.m4
	@${REINPLACE_CMD} -e 's|(libdir)|(libdir)/lib|' \
		 ${WRKSRC}/lib/Makefile.in
	@${REINPLACE_CMD} -e 's|(libdir)|(libdir)/libdata|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
