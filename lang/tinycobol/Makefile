# New ports collection makefile for:	tinycobol
# Date created:		26 Oct 2000
# Whom:			Patrick Gardella <patrick@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	tinycobol
PORTVERSION=	0.59
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tiny-cobol

MAINTAINER=	patrick@freebsd.org
COMMENT=	A tiny COBOL compiler for IA32 platforms

LIB_DEPENDS=	db2.0:${PORTSDIR}/databases/db2

ONLY_FOR_ARCHS=	i386
USE_GETOPT_LONG=yes
HAS_CONFIGURE=	yes
USE_BISON=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS=	"--with-readline"
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		htcobol.1 htcobf2f.1 htcobolpp.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 501000
BROKEN=		"Does not compile"
.endif

pre-install:

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/tinycobol
	${INSTALL_DATA} ${WRKSRC}/info/*.txt ${PREFIX}/share/doc/tinycobol
.endif

.include <bsd.port.post.mk>
