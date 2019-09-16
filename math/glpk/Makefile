# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	glpk
DISTVERSION=	4.65
CATEGORIES=	math
MASTER_SITES=	GNU

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	GNU Linear Programming Kit

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgmp.so:math/gmp

CONFLICTS=	goblin-[0-9]*

USES=		gmake libtool localbase
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CFLAGS+=	-trigraphs
CPPFLAGS+=	-D_LSEEK_DECLARED
CONFIGURE_ARGS=	--with-gmp
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

PORTDOCS=	*

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
	cd ${WRKSRC}/doc && ${INSTALL_DATA} cnfsat.pdf glpk.pdf gmpl.pdf \
		graphs.pdf miplib2.txt miplib3.txt netlib.txt ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc/notes && ${INSTALL_DATA} gomory.pdf keller.pdf \
		scf.pdf simplex1.pdf simplex2.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
