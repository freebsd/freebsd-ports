# New ports collection makefile for:	hypermail
# Date created:				23 Dec 1997
# Whom:					mjhsieh
#
# $FreeBSD$
#

PORTNAME=	hypermail
PORTVERSION=	2.1.8
CATEGORIES=	www mail
MASTER_SITES=	http://isc.hypermail.org/dist/

MAINTAINER=	petef@FreeBSD.org
COMMENT=	A program to generate a cross-referenced HTML mail archive

LIB_DEPENDS+=	gdbm.3:${PORTSDIR}/databases/gdbm \
		pcre.0:${PORTSDIR}/devel/pcre

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-htmldir=${PREFIX}/share/doc/hypermail \
		--with-gdbm=${LOCALBASE}

CFLAGS+=	-L${LOCALBASE}/lib

MAN1=		hypermail.1
MAN4=		hmrc.4

.include <bsd.port.mk>
