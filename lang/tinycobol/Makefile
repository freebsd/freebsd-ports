# New ports collection makefile for:	tinycobol
# Date created:		26 Oct 2000
# Whom:			Patrick Gardella <patrick@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	tinycobol
PORTVERSION=	0.63
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tiny-cobol

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tiny COBOL compiler for IA32 platforms

LIB_DEPENDS=	db3:${PORTSDIR}/databases/db3

USE_LDCONFIG=	yes
ONLY_FOR_ARCHS=	i386
USE_GETOPT_LONG=yes
HAS_CONFIGURE=	yes
USE_BISON=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS=	--with-libdb=3
CPPFLAGS=	-I${LOCALBASE}/include
CFLAGS=		${CPPFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		htcobol.1 htcobf2f.1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/info/*.txt ${DOCSDIR}
.endif

.include <bsd.port.pre.mk>

# doesn't work with readline on FreeBSD 4.x
.if ${OSVERSION} >= 500000
CONFIGURE_ARGS+=	--with-readline
.endif

.include <bsd.port.post.mk>
