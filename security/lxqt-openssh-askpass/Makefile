PORTNAME=	lxqt-openssh-askpass
PORTVERSION=	2.2.0
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	LXQT

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	LXQt GUI dialog for OpenSSH authentication
WWW=		https://lxqt-project.org

LICENSE=	LGPL21+

USES=		cmake compiler:c++20-lang gettext-runtime lxqt:2 perl5 \
		pkgconfig qt:6 tar:xz
USE_LXQT=	buildtools2 lxqt
USE_PERL5=	build
USE_QT=		base:run tools:build

.include <bsd.port.mk>
