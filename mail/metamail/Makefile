# New ports collection makefile for:	metamail
# Date created:		17 Oct 1994
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	metamail
PORTVERSION=	2.7
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	http://ftp.funet.fi/pub/unix/mail/metamail/
DISTNAME=	mm${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of MIME, the Multipurpose Internet Mail Extensions

BUILD_DEPENDS=	bdftopcf:${X_CLIENTS_PORT}
RUN_DEPENDS=	xloadimage:${PORTSDIR}/x11/xloadimage \
		mkfontdir:${X_CLIENTS_PORT}

USE_XLIB=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src
MAN1=		audiocompose.1 audiosend.1 extcompose.1 \
		getfilename.1 mailto-hebrew.1 mailto.1 metamail.1 \
		metasend.1 mime.1 mimencode.1 mmencode.1 \
		patch-metamail.1 richtext.1 showaudio.1 \
		showexternal.1 shownonascii.1 showpartial.1 \
		showpicture.1 splitmail.1
MAN4=		mailcap.4

post-patch:
	@${RM} ${WRKSRC}/bin/*.orig

.include <bsd.port.mk>
