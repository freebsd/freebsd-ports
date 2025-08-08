PORTNAME=	ksmtp
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Job-based library to send email through an SMTP server
WWW=		https://invent.kde.org/pim/ksmtp

LICENSE=	LGPL21
LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2

USES=		cmake compiler:c++11-lib gettext kde:6 qt:6 tar:xz
USE_KDE=	config coreaddons i18n kio service \
		ecm:build
# pim components
USE_KDE+=	mime
USE_QT=		base

USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
