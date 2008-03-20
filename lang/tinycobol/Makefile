# New ports collection makefile for:	tinycobol
# Date created:		26 Oct 2000
# Whom:			Patrick Gardella <patrick@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	tinycobol
PORTVERSION=	0.63
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tiny-cobol

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tiny COBOL compiler for IA32 platforms

LIB_DEPENDS=	db3:${PORTSDIR}/databases/db3

USE_LDCONFIG=	yes
ONLY_FOR_ARCHS=	i386
HAS_CONFIGURE=	yes
USE_BISON=	build
USE_GMAKE=	yes

CONFIGURE_ARGS=	--with-libdb=3 \
		--with-readline
CPPFLAGS=	-I${LOCALBASE}/include
CFLAGS+=		${CPPFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		htcobol.1 htcobf2f.1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/info/*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
