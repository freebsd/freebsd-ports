# New ports collection makefile for:	tinycobol
# Date created:		26 Oct 2000
# Whom:			Patrick Gardella <patrick@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	tinycobol
PORTVERSION=	0.61
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tiny-cobol

MAINTAINER=	patrick@freebsd.org
COMMENT=	A tiny COBOL compiler for IA32 platforms

LIB_DEPENDS=	db2.0:${PORTSDIR}/databases/db2

INSTALLS_SHLIB=	yes
ONLY_FOR_ARCHS=	i386
USE_GETOPT_LONG=yes
HAS_CONFIGURE=	yes
USE_BISON=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS=	--with-libdb=2
# --with-readline disabled because of CPP-clash between readline/chardefs.h
#   and htcobol.tab.h:PAGE/RETURN/ALPHABETIC
#CONFIGURE_ARGS+=	--with-readline
CPPFLAGS=	-I${LOCALBASE}/include
CFLAGS=		${CPPFGLAGS}
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		htcobol.1 htcobf2f.1 htcobolpp.1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/info/*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
