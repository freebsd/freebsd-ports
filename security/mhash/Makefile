# New ports collection makefile for:	mhash
# Date created:		Mon Jun 28 17:59:13 PDT 1999
# Whom:			nsayer@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	mhash
PORTVERSION=	0.9.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	roam@FreeBSD.org
COMMENT=	An easy-to-use library for strong hashes such as MD5 and SHA1

INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=13
USE_PERL5_BUILD=yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--with-LDFLAGS="${PTHREAD_LIBS}" --enable-static \
			--with-gnu-ld

MAN3=		mhash.3

DOCFILES=	example.c md5-rfc1321.txt skid2-authentication

.if !defined(NOPORTDOCS)
post-install:
		${MKDIR} ${DOCSDIR}
		${INSTALL_DATA} ${DOCFILES:S,^,${WRKSRC}/doc/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
