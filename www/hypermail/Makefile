# Created by: mjhsieh
# $FreeBSD$

PORTNAME=	hypermail
PORTVERSION=	2.2.0
PORTREVISION=	3
CATEGORIES=	www mail
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program to generate a cross-referenced HTML mail archive

LIB_DEPENDS+=	libgdbm.so:${PORTSDIR}/databases/gdbm \
		libpcre.so:${PORTSDIR}/devel/pcre

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-htmldir=${PREFIX}/share/doc/hypermail \
		--with-gdbm=${LOCALBASE}

CFLAGS+=	-L${LOCALBASE}/lib

MAN1=		hypermail.1
MAN4=		hmrc.4

NO_STAGE=	yes
.include <bsd.port.mk>
