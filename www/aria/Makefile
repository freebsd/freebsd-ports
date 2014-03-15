# Created by: Yukihiro Nakai <nakai@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aria
PORTVERSION=	1.0.0
PORTREVISION=	5
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}-rpm/Aria%20Sources/${PORTVERSION}-official

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet another download tool

LICENSE=	GPLv2 # (or later)

OPTIONS_DEFINE=	NLS DOCS

USE_GNOME=	gtk12
USE_OPENSSL=	yes
USES=		gmake tar:bzip2
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
NO_PACKAGE=	hangs on pointyhat

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	README README.euc

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64: just hangs
.endif

post-extract:
	@${RM} -f ${WRKSRC}/src/getopt*

post-patch:
	@${REINPLACE_CMD} -e 's|-lssl|-lcrypto -lssl|g ; \
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
	@${REINPLACE_CMD} -e 's|\*infile|infile|g ; \
		s|(gzFile \*)||' ${WRKSRC}/src/RetrieveHTTP.cc

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
