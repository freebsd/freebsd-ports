# New ports collection makefile for:   aria
# Date created:        30 March 2001
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aria
PORTVERSION=	1.0.0
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	SF/aria-rpm

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Yet another download tool

MAKE_JOBS_SAFE=  yes

USE_BZIP2=	yes
.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif
USE_GNOME=	gnometarget gtk12
USE_OPENSSL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
PORTDOCS=	README README.euc

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
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
