# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	glpk
PORTVERSION=	4.52.1
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU Linear Programming Kit

LICENSE=	GPLv3

LIB_DEPENDS=	libgmp.so:math/gmp

OPTIONS_DEFINE=	IODBC MYSQL DOCS
IODBC_DESC=	MathProg iodbc support
MYSQL_DESC=	MathProg mysql support

GNU_CONFIGURE=	yes
USES=		gmake libtool
USE_LDCONFIG=	yes
CFLAGS+=	-trigraphs
CPPFLAGS+=	-D_LSEEK_DECLARED -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-gmp
CONFLICTS=	goblin-[0-9]*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIODBC} || ${PORT_OPTIONS:MMYSQL}
CONFIGURE_ARGS+=	--enable-dl=dlfcn
.else
CONFIGURE_ARGS+=	--disable-dl
.endif

.if ${PORT_OPTIONS:MIODBC}
CONFIGURE_ARGS+=	--enable-odbc
LIB_DEPENDS+=		libiodbc.so:databases/libiodbc
.else
CONFIGURE_ARGS+=	--disable-odbc
.endif

.if ${PORT_OPTIONS:MMYSQL}
CONFIGURE_ARGS+=	--enable-mysql
USE_MYSQL=		yes
.else
CONFIGURE_ARGS+=	--disable-mysql
.endif

post-patch:
	@${REINPLACE_CMD} -e "s;\/usr\/include\/mysql;${LOCALBASE}\/include\/mysql;g" \
	${WRKSRC}/configure

DOCS1=	cnfsat.pdf glpk.pdf glpk_faq.txt gmpl.pdf graphs.pdf miplib2.txt \
	miplib3.txt netlib.txt
DOCS2=	dfeas.pdf gomory.pdf keller.pdf scaling.pdf updating.pdf
PORTDOCS=	${DOCS1} ${DOCS2}

post-install:
	@${INSTALL_DATA} ${WRKSRC}/src/glplpx.h ${STAGEDIR}${PREFIX}/include
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/doc ; \
	${INSTALL_DATA} ${DOCS1} ${DOCS2:S|^|notes/|} ${STAGEDIR}${DOCSDIR}
.endif

check regression-test test: build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} check)

.include <bsd.port.mk>
