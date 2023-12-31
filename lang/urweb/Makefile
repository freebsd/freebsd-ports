PORTNAME=	urweb
PORTVERSION=	20200209
PORTREVISION=	2
CATEGORIES=	lang www

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Ultimate host for embedded domain-specific languages
WWW=		http://www.impredicative.com/ur/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386

BUILD_DEPENDS=	mlton:lang/mlton
LIB_DEPENDS=	libgmp.so:math/gmp \
		libicudata.so:devel/icu

USES=		autoreconf gmake libtool ssl tar:tgz
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
CONFIGURE_ENV=		CCARGS="-I${LOCALBASE}/include"

CFLAGS+=	-pthread

OPTIONS_DEFINE=		ELISP PGSQL SQLITE
OPTIONS_DEFAULT=	ELISP PGSQL
OPTIONS_EXCLUDE=	DOCS NLS
OPTIONS_SUB=		yes

ELISP_DESC=	Install contributed Emacs Lisp

ELISP_CONFIGURE_ON=		with_emacs=yes
ELISP_CONFIGURE_OFF=		with_emacs=no
PGSQL_USES=			pgsql
PGSQL_CONFIGURE_ENV_OFF=	PGHEADER="no"
PGSQL_VARS=			WANT_PGSQL=server
SQLITE_USES=			sqlite
SQLITE_CONFIGURE_ENV_OFF=	SQHEADER="no"

post-patch:
	@${REINPLACE_CMD} -e "s|postgresql/libpq-fe.h|libpq-fe.h|g" \
		${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e "s|uw_Basis_int true|uw_Basis_int utrue|" \
		-e "s|uw_Basis_int false|uw_Basis_int ufalse|" \
		-e "s|uw_Basis_bool true|uw_Basis_bool utrue|" \
		-e "s|uw_Basis_bool false|uw_Basis_bool ufalse|" \
		-e "s|\&true|\&utrue|g" -e "s|\&false|\&ufalse|g" \
		-e "s|abs(ret)|llabs(ret)|" \
		${WRKSRC}/src/c/urweb.c

.include <bsd.port.mk>
