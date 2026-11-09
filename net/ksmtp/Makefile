PORTNAME=	ksmtp
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Job-based library to send email through an SMTP server
WWW=		https://invent.kde.org/pim/ksmtp

LICENSE=	LGPL21

LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2

USES=		cmake gettext-tools kde:6 qt:6 tar:xz
# KDE Frameworks
USE_KDE=	coreaddons i18n kio \
		ecm:build
USE_QT=		base

USE_LDCONFIG=	yes

.include <bsd.port.mk>
