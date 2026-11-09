PORTNAME=	libksieve
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Sieve libraries for KDE PIM
WWW=		https://invent.kde.org/pim/libksieve

LICENSE=	LGPL21

LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2

USES=		cmake gettext-tools kde:6 qt:6 tar:xz
# KDE Frameworks
USE_KDE=	archive colorscheme coreaddons i18n iconthemes kio \
		ktextaddons mime newstuff sonnet syntaxhighlighting \
		ecm:build
# KDE PIM
USE_KDE+=	identitymanagement imap libkdepim mailtransport \
		pimcommon
USE_QT=		base declarative webengine
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
