# New ports collection makefile for:	emil
# Date created:		21 April 1998
# Whom:			Josh Gilliam <josh@quick.net>
#
# $FreeBSD$
#

PORTNAME=	emil
PORTVERSION=	2.1b9
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.uu.se/pub/unix/networking/mail/emil/ \
		ftp://ftp.gwdg.de/pub/misc/emil/ \
		ftp://ftp.funet.fi/pub/unix/mail/emil/ \
		ftp://ftp.enst.fr/pub/unix/network/mail/ \
		ftp://sunsite.doc.ic.ac.uk/Mirrors/ftp.uu.se/pub/unix/networking/mail/emil/
DISTNAME=	${PORTNAME}-2.1.0-beta9

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mail format/encoding converter

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	YACC=byacc
MAN1=		emil.1 emil.cf.1

.if defined(NOPORTDOCS)
MAKE_ENV=	NOPORTDOCS=${NOPORTDOCS}
.endif

.include <bsd.port.mk>
