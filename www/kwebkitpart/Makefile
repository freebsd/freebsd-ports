# New ports collection makefile for:	kwebkitpart
# Date created:				4 March 2010
# Whom:					Alberto Villa <avilla@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kwebkitpart
DISTVERSION=	0.9.0svn1119520
CATEGORIES=	www kde
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~avilla/distfiles/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Web browser component for KDE (KPart)

USE_KDE4=	automoc4 kdehier kdelibs kdeprefix
USE_QT_VER=	4
QT_COMPONENTS=	designer webkit \
		moc_build qmake_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes
USE_CMAKE=	yes
USE_LDCONFIG=	yes

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
