# New ports collection makefile for:	gutenfetch
# Date created:		22-Aug-2001
# Whom:			Russell Francis
#
# $FreeBSD$
#

PORTNAME=	gutenfetch
PORTVERSION=	1.4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gutenfetch

MAINTAINER=	rf358197@ohio.edu
COMMENT=	Fetch listings and books from Project Gutenberg

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl:install

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GETOPT_LONG=	yes

MAN1=		gutenfetch.1
PLIST_FILES=	bin/gutenfetch

post-install:
	${STRIP_CMD} ${PREFIX}/bin/gutenfetch
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's,%%PREFIX%%,${PREFIX},g'

.include <bsd.port.mk>
