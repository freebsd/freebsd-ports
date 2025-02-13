PORTNAME=	icon-naming-utils
PORTVERSION=	0.8.90
PORTREVISION=	2
CATEGORIES=	x11-themes
MASTER_SITES=	https://tango.freedesktop.org/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utilities of the Tango project
WWW=		http://tango-project.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	p5-XML-Simple>=0:textproc/p5-XML-Simple
RUN_DEPENDS=	p5-XML-Simple>=0:textproc/p5-XML-Simple

USES=		gmake pathfix perl5 pkgconfig

GNU_CONFIGURE=	yes
NO_ARCH=	yes

.include <bsd.port.mk>
