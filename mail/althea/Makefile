# New ports collection makefile for:	Althea
# Date created:		Feb 26, 2001
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	althea
PORTVERSION=	0.5.7
PORTREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet another GTK-based mail reader for X. Supports IMAP

USE_GETTEXT=	yes
USE_OPENSSL=	yes
MAKE_ENV=	MKDIR="${MKDIR}"
MAKEFILE=	${FILESDIR}/Makefile.bsd
USE_GNOME=	gtk12

post-patch:
.for file in Documentation/help.html load_config.h save_config.h
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g' ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
