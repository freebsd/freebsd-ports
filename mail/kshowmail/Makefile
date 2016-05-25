# Created by: Markus Brueffer <brueffer@phoenix-systems.de>
# $FreeBSD$

PORTNAME=	kshowmail
PORTVERSION=	4.1
PORTREVISION=	4
CATEGORIES=	mail kde
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20for%20KDE4/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	POP3 mail checker for KDE

LICENSE=	GPLv2

USE_KDE4=	automoc4 kdelibs pimlibs
USE_QT4=	corelib dbus gui network svg xml \
		qmake_build uic_build rcc_build
USE_PERL5=	build
USES=		cmake gettext perl5

.include <bsd.port.mk>
