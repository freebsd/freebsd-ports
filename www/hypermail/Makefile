# New ports collection makefile for:	hypermail
# Date created:				23 Dec 1997
# Whom:					mjhsieh
#
# $FreeBSD$
#

PORTNAME=	hypermail
PORTVERSION=	2.1.3
CATEGORIES=	www mail
MASTER_SITES=	http://www.landfield.com/hypermail/dist/

MAINTAINER=	petef@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-htmldir=${PREFIX}/share/doc/hypermail

.if defined(WITH_GDBM)
CONFIGURE_ARGS+=	--with-gdbm
LIB_DEPENDS+=	gdbm.2:${PORTSDIR}/databases/gdbm
.endif

MAN1=		hypermail.1
MAN4=		hmrc.4

.include <bsd.port.mk>
