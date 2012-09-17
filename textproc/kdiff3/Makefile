# New ports collection makefile for:	kdiff3
# Date created:		2003/01/03
# Whom:			Heiner Eichmann <h.eichmann@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	kdiff3
PORTVERSION=	0.9.95
PORTREVISION=	4
CATEGORIES=	textproc kde
MASTER_SITES=	SF

MAINTAINER=	brucec@FreeBSD.org
COMMENT=	A KDE4 graphical frontend for diff

USE_KDE4=	kdelibs libkonq kdeprefix kdehier automoc4
USE_CMAKE=	yes
USE_QT4=	moc_build qmake_build rcc_build uic_build
USE_GETTEXT=	yes
MAKE_JOBS_SAFE=	yes

post-patch:
#Fix build with kdelibs>=4.5.0
	${REINPLACE_CMD} -e 's,V4.1.2-Based,V4.2-Based,g' \
		${WRKSRC}/doc/*/index.docbook

.include <bsd.port.mk>
