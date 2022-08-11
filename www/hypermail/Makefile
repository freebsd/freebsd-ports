PORTNAME=	hypermail
PORTVERSION=	2.4.0
DISTVERSIONPREFIX=	v
PORTREVISION=	5
CATEGORIES=	www mail

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Program to generate a cross-referenced HTML mail archive

LICENSE=	GPLv2

LIB_DEPENDS+=	libpcre.so:devel/pcre \
		libtrio.so:devel/trio

USES=		localbase iconv desthack

USE_GITHUB=	yes
GH_ACCOUNT=	hypermail-project

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-htmldir=${STAGEDIR}${PREFIX}/share/doc/hypermail \
		--with-external-pcre=${LOCALBASE}/bin/pcre-config \
		--enable-system-libtrio

CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -L${LOCALBASE}/lib"

MAKE_ARGS=	INSTALL_PROG=${INSTALL}

OPTIONS_DEFINE=	DOCS GDBM
OPTIONS_DEFAULT=	GDBM

GDBM_DESC=	Support incremental updates

GDBM_CONFIGURE_WITH=	-with-gdbm=${LOCALBASE}
GDBM_CONFIGURE_OFF=	--without-gdbm
GDBM_LIB_DEPENDS=	libgdbm.so:databases/gdbm

post-install:
	${STRIP_CMD} ${STAGEDIR}/${PREFIX}/bin/hypermail \
		${STAGEDIR}/${PREFIX}/bin/msg2archive \
		${STAGEDIR}/${PREFIX}/bin/rdmsg

.include <bsd.port.mk>
