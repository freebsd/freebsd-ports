# New ports collection makefile for:	hypermail
# Date created:				23 Dec 1997
# Whom:					mjhsieh
#
# $FreeBSD$
#

PORTNAME=	hypermail
PORTVERSION=	2.1.5
CATEGORIES=	www mail
MASTER_SITES=	http://www.landfield.com/hypermail/dist/

MAINTAINER=	petef@FreeBSD.org

LIB_DEPENDS+=	gdbm.2:${PORTSDIR}/databases/gdbm \
		pcre.0:${PORTSDIR}/devel/pcre

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-htmldir=${PREFIX}/share/doc/hypermail \
		--with-gdbm=${LOCALBASE}

CFLAGS+=	-L${LOCALBASE}/lib

MAN1=		hypermail.1
MAN4=		hmrc.4

.include <bsd.port.mk>
