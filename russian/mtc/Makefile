# New ports collection makefile for:	mtc
# Date created:			13 Nov 2001
# Whom:				Artem Koutchine <matrix@ipform.ru>, Alexander Trapeznikov <infoteacher@ipform.ru>
#
# $FreeBSD$
#

PORTNAME=	mtc
PORTVERSION=	1.3
CATEGORIES=	russian
MASTER_SITES=	# disappeared

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multifile text Encoding Converter 1.3

BROKEN=		"mastersite disappeared"
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=	2005-12-09
NO_BUILD=	yes

MAN7=		mtc.7

do-install:
.for file in mtc wee
	${INSTALL_SCRIPT} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
.for file in koi8 win1251 dos866
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/etc
.endfor
	${INSTALL_MAN} ${WRKSRC}/mtc.7 ${MANPREFIX}/man/man7

.include <bsd.port.mk>
