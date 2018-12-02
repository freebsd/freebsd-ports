# Created by: Markus Brueffer <brueffer@phoenix-systems.de>
# $FreeBSD$

PORTNAME=	kshowmail
PORTVERSION=	4.1
PORTREVISION=	6
CATEGORIES=	mail kde
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20for%20KDE4/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	POP3 mail checker for KDE

LICENSE=	GPLv2

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2018-12-31

USES=		cmake gettext kde:4 perl5 qt:4
USE_KDE=	automoc4 kdelibs pimlibs
USE_QT=		corelib dbus gui network svg xml \
		qmake_build uic_build rcc_build
USE_PERL5=	build

.include <bsd.port.mk>
