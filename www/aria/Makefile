# New ports collection makefile for:   aria
# Date created:        30 March 2001
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aria
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://rabien.virtualave.net/linux/storage/sources/ \
		http://aria.rednoah.com/storage/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet another download tool

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnometarget gtk12
USE_OPENSSL=	yes
USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=	13
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS=	-I${LOCALBASE}/include -DHAVE_DECL_GETOPT
LDFLAGS=	-L${LOCALBASE}/lib

post-extract:
	@${RM} -f ${WRKSRC}/src/getopt*

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|-lssl|-lcrypto -lssl|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's| -O2 -Wall | @CXXFLAGS@ |g ; \
		s|getopt.c getopt1.c getopt.h||g ; \
		s|getopt.o getopt1.o||g ; \
		s|\.deps/getopt.P ||g ; \
		s|\.deps/getopt1.P ||g' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's| -O2 -Wall | @CXXFLAGS@ |g' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|"getopt.h"|<getopt.h>|g' \
		${WRKSRC}/src/main.cc

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.euc ${DOCSDIR}
.endif

.include <bsd.port.mk>
