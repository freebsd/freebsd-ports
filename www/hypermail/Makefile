# Created by: mjhsieh
# $FreeBSD$

PORTNAME=	hypermail
PORTVERSION=	2.2.0
PORTREVISION=	3
CATEGORIES=	www mail
MASTER_SITES=	SF

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	Program to generate a cross-referenced HTML mail archive

LICENSE=	GPLv2

LIB_DEPENDS+=	libgdbm.so:${PORTSDIR}/databases/gdbm \
		libpcre.so:${PORTSDIR}/devel/pcre

USES=		desthack

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-htmldir=${STAGEDIR}${PREFIX}/share/doc/hypermail \
		--with-gdbm=${LOCALBASE}

CFLAGS+=	-L${LOCALBASE}/lib

post-install:
	${STRIP_CMD} ${STAGEDIR}/${PREFIX}/bin/hypermail \
		${STAGEDIR}/${PREFIX}/bin/msg2archive \
		${STAGEDIR}/${PREFIX}/bin/rdmsg

.include <bsd.port.mk>
