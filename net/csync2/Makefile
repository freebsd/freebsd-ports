PORTNAME=	csync2
PORTVERSION=	2.0
PORTREVISION=	3
CATEGORIES=	net

MAINTAINER=	olevole@olevole.ru
COMMENT=	Cluster synchronization tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	librsync.so:net/librsync \
		libgnutls.so:security/gnutls \
		libsqlite3.so:databases/sqlite3

USES=		autoreconf pkgconfig shebangfix
SHEBANG_FILES=	csync2-compare

OPTIONS_DEFINE=	CSYNC2_COMPARE DOCS
OPTIONS_SUB=	yes
CSYNC2_COMPARE_DESC=		Install csync2-compare script
CSYNC2_COMPARE_RUN_DEPENDS=	bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	LINBIT
GH_PROJECT=	csync2
GH_TAGNAME=	a8d38eb

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	ac_cv_prog_PDFLATEX=
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

USE_RC_SUBR=	csync2

SUB_FILES=	pkg-install

post-patch:
	@${REINPLACE_CMD} -e 's|(localstatedir)/lib|(localstatedir)/db|' \
		-e 's/-ldl//' ${WRKSRC}/Makefile.am

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/csync2.cfg \
		${STAGEDIR}${PREFIX}/etc/csync2.cfg.sample
	${MKDIR} ${STAGEDIR}/var/backups/csync2

.include <bsd.port.mk>
