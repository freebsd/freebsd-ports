# Created by: Remington Lang <MrL0Lz@gmail.com>
# $FreeBSD$

PORTNAME=	gcfilms
PORTVERSION=	6.4
PORTREVISION=	3
CATEGORIES=	multimedia perl5
MASTER_SITES=	http://download.gna.org/gcfilms/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to manage movie collections

BUILD_DEPENDS=	p5-Archive-Tar>=0:archivers/p5-Archive-Tar \
		p5-XML-Simple>=0:textproc/p5-XML-Simple \
		p5-Gtk2>=0:x11-toolkits/p5-Gtk2 \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		shebangfix
NO_BUILD=	yes

SHEBANG_FILES=	bin/gcfilms install

do-install:
	cd ${WRKSRC} ; ./install --prefix=${STAGEDIR}${PREFIX}

.include <bsd.port.mk>
