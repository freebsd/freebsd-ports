# New ports collection makefile for: autorespond
# Date created:		24 Jan 2000
# Whom:			Neil Blakey-Milner <nbm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	autorespond
PORTVERSION=	2.0.5
CATEGORIES=	mail
MASTER_SITES=	http://www.inter7.com/devel/

PATCH_SITES=	http://people.FreeBSD.org/~roam/ports/patches/mail/
PATCHFILES=	${DISTNAME}-conf-strcasestr.patch

MAINTAINER=	roam@FreeBSD.org
COMMENT=	Simple autoresponder for qmail

MAN1=		autorespond.1
PLIST_FILES=	bin/autorespond

.if defined(WITHOUT_MDOC_MANPAGE)
AR_MANPAGE=	${WRKSRC}/autorespond.1
.else
AR_MANPAGE=	${FILESDIR}/autorespond.1
.endif

post-patch:
	${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	${ECHO_CMD} "${CC} ${STRIP}" > ${WRKSRC}/conf-ld
	${ECHO_CMD} "${PREFIX}" > ${WRKSRC}/conf-home

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/autorespond ${PREFIX}/bin/
	${INSTALL_MAN} ${AR_MANPAGE} ${PREFIX}/man/man1/

.include <bsd.port.mk>
