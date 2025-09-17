PORTNAME=	bcmatroska2
DISTVERSION=	5.4.29
CATEGORIES=	multimedia

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Belledonne Communications Matroska media container support
WWW=		https://www.linphone.org/

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox \
		libbcunit.so:devel/bcunit

USES=		cmake compiler:c++17-lang
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
