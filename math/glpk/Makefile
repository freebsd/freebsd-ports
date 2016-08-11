# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	glpk
PORTVERSION=	4.55
CATEGORIES=	math
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU Linear Programming Kit

LICENSE=	GPLv3

LIB_DEPENDS=	libgmp.so:math/gmp

GNU_CONFIGURE=	yes
USES=		gmake libtool localbase
USE_LDCONFIG=	yes
CFLAGS+=	-trigraphs
CPPFLAGS+=	-D_LSEEK_DECLARED
CONFIGURE_ARGS+=	--with-gmp
CONFLICTS=	goblin-[0-9]*

DOCS1=		cnfsat.pdf glpk.pdf gmpl.pdf graphs.pdf miplib2.txt \
		miplib3.txt netlib.txt
DOCS2=		dfeas.pdf gomory.pdf keller.pdf scaling.pdf
PORTDOCS=	${DOCS1} ${DOCS2}

OPTIONS_DEFINE=	IODBC MYSQL DOCS

IODBC_DESC=		MathProg iodbc support
IODBC_CONFIGURE_ON=	--enable-dl=dlfcn --enable-odbc
IODBC_CONFIGURE_OFF=	--disable-dl --disable-odbc
IODBC_LIB_DEPENDS=	libiodbc.so:databases/libiodbc

MYSQL_DESC=		MathProg mysql support
MYSQL_CONFIGURE_ON=	--enable-dl=dlfcn --enable-mysql
MYSQL_CONFIGURE_OFF=	--disable-mysql
MYSQL_USES=		mysql

post-patch:
	@${REINPLACE_CMD} -e "s;\/usr\/include\/mysql;${LOCALBASE}\/include\/mysql;g" \
	${WRKSRC}/configure

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc ; \
	${INSTALL_DATA} ${DOCS1} ${DOCS2:S|^|notes/|} ${STAGEDIR}${DOCSDIR}

check regression-test test: build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} check)

.include <bsd.port.mk>
