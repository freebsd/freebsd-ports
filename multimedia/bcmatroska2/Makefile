PORTNAME=	bcmatroska2
DISTVERSION=	5.4.24
CATEGORIES=	multimedia

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Belledonne Communications Matroska media container support
WWW=		https://www.linphone.org/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libbctoolbox.a:net/bctoolbox \
		${LOCALBASE}/lib/libbcunit.a:devel/bcunit

USES=		cmake compiler:c++17-lang
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
USE_LDCONFIG=	yes

.include <bsd.port.mk>
