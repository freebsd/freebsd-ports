# New ports collection makefile for:	GLPK
# Date created:		16 December 2000
# Whom:			Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glpk
PORTVERSION=	4.47
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	glpk

MAINTAINER=	bf@FreeBSD.org
COMMENT=	A GNU Linear Programming Kit

LIB_DEPENDS=	gmp:${PORTSDIR}/math/gmp

LICENSE=	GPLv3

OPTIONS=	IODBC	"Enable MathProg iodbc support" Off \
		MYSQL	"Enable MathProg mysql support" Off

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
CFLAGS+=	-trigraphs
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-gmp

.include <bsd.port.pre.mk>

.ifdef(WITH_IODBC || WITH_MYSQL)
CONFIGURE_ARGS+=	--enable-dl=dlfcn
.else
CONFIGURE_ARGS+=	--disable-dl
.endif

.ifdef(WITH_IODBC)
CONFIGURE_ARGS+=	--enable-odbc
LIB_DEPENDS+=		iodbc.3:${PORTSDIR}/databases/libiodbc
.else
CONFIGURE_ARGS+=	--disable-odbc
.endif

.ifdef(WITH_MYSQL)
CONFIGURE_ARGS+=	--enable-mysql
USE_MYSQL=		yes
.else
CONFIGURE_ARGS+=	--disable-mysql
.endif

post-patch:
	@${REINPLACE_CMD} -e "s;\/usr\/include\/mysql;${LOCALBASE}\/include\/mysql;g" \
	${WRKSRC}/configure

.if !defined(NOPORTDOCS)
DOCS1=	cnfsat.pdf glpk.pdf glpk_faq.txt gmpl.pdf graphs.pdf miplib2.txt \
	miplib3.txt netlib.txt
DOCS2=	dfeas.pdf gomory.pdf keller.pdf scaling.pdf updating.pdf
PORTDOCS=	${DOCS1} ${DOCS2}

post-install:
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/doc ; \
	${INSTALL_DATA} ${DOCS1} ${DOCS2:S|^|notes/|} ${DOCSDIR}

.endif

check regression-test test: build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} check)

.include <bsd.port.post.mk>
