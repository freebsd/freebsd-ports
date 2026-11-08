PORTNAME=	hypermail
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.1
CATEGORIES=	www mail

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program to generate a cross-referenced HTML mail archive
WWW=		https://www.hypermail-project.org/ \
		https://github.com/hypermail-project/hypermail/

LICENSE=	GPLv2

LIB_DEPENDS=	libpcre.so:devel/pcre \
		libtrio.so:devel/trio

USES=		desthack iconv localbase

USE_GITHUB=	yes
GH_ACCOUNT=	hypermail-project

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-htmldir=${STAGEDIR}${PREFIX}/share/doc/hypermail \
		--with-external-pcre=${LOCALBASE}/bin/pcre-config \
		--enable-system-libtrio
MAKE_ARGS=	INSTALL_PROG=${INSTALL}
CFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS GDBM
OPTIONS_DEFAULT=	GDBM

GDBM_DESC=	Support incremental updates

GDBM_LIB_DEPENDS=	libgdbm.so:databases/gdbm
GDBM_CONFIGURE_ON=	--with-gdbm=${LOCALBASE}
GDBM_CONFIGURE_OFF=	--without-gdbm

post-install:
	${STRIP_CMD} ${STAGEDIR}/${PREFIX}/bin/hypermail \
		${STAGEDIR}/${PREFIX}/bin/msg2archive \
		${STAGEDIR}/${PREFIX}/bin/rdmsg

.include <bsd.port.mk>
