# New ports collection makefile for:	tinycobol
# Date created:		26 Oct 2000
# Whom:			Patrick Gardella <patrick@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	tinycobol
PORTVERSION=	0.4
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tiny-cobol

MAINTAINER=	patrick@freebsd.org

LIB_DEPENDS=	db2.0:${PORTSDIR}/databases/db

ONLY_FOR_ARCHS=	i386
HAS_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS=	"--with-readline"
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib ${LDFLAGS}"

pre-build:
	${CP} ${FILESDIR}/getopt.h ${WRKSRC}

pre-install:

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/tinycobol
	${INSTALL_DATA} ${WRKSRC}/info/*.txt ${PREFIX}/share/doc/tinycobol
.endif

.include <bsd.port.mk>
