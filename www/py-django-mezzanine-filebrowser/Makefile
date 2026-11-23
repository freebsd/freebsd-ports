PORTNAME=	django-mezzanine-filebrowser
DISTVERSION=	1.1.1
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	filebrowser_safe-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Fork of django-filebrowser for Mezzanine CMS
WWW=		https://github.com/stephenmcd/filebrowser-safe

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Mezzanine-specific fork; Mezzanine was removed from the tree in 2021
EXPIRATION_DATE=	2026-12-23

USES=		gettext python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
