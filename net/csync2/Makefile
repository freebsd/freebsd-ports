PORTNAME=	csync2
PORTVERSION=	2.0
PORTREVISION=	3
CATEGORIES=	net

MAINTAINER=	olevole@olevole.ru
COMMENT=	Cluster synchronization tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgnutls.so:security/gnutls \
		librsync.so:net/librsync \
		libsqlite3.so:databases/sqlite3

USES=		autoreconf cpe pkgconfig shebangfix
CPE_VENDOR=	linbit
USE_GITHUB=	yes
GH_ACCOUNT=	LINBIT
GH_TAGNAME=	a8d38eb
USE_RC_SUBR=	csync2

SHEBANG_FILES=	csync2-compare

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	ac_cv_prog_PDFLATEX=
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

SUB_FILES=	pkg-install

OPTIONS_DEFINE=			CSYNC2_COMPARE DOCS
OPTIONS_SUB=			yes
CSYNC2_COMPARE_DESC=		Install csync2-compare script
CSYNC2_COMPARE_RUN_DEPENDS=	bash:shells/bash

post-patch:
	@${REINPLACE_CMD} -e 's|(localstatedir)/lib|(localstatedir)/db|' \
		-e 's/-ldl//' ${WRKSRC}/Makefile.am

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/csync2.cfg \
		${STAGEDIR}${PREFIX}/etc/csync2.cfg.sample
	${MKDIR} ${STAGEDIR}/var/backups/csync2

.include <bsd.port.mk>
