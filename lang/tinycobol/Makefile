# New ports collection makefile for:	tinycobol
# Date created:		26 Oct 2000
# Whom:			Patrick Gardella <patrick@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	tinycobol
PORTVERSION=	0.59
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tiny-cobol

MAINTAINER=	patrick@freebsd.org

LIB_DEPENDS=	db2.0:${PORTSDIR}/databases/db2 \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

ONLY_FOR_ARCHS=	i386
HAS_CONFIGURE=	yes
USE_BISON=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS=	"--with-readline"
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt ${LDFLAGS}" \
		CPPFLAGS="-I${LOCALBASE}/include" 

MAN1=        htcobol.1 htcobf2f.1 htcobolpp.1

pre-install:

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/tinycobol
	${INSTALL_DATA} ${WRKSRC}/info/*.txt ${PREFIX}/share/doc/tinycobol
.endif

.include <bsd.port.mk>
