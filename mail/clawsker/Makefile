# Created by: Pawel Pekala <c0rn@o2.pl>
# $FreeBSD$

PORTNAME=	clawsker
PORTVERSION=	1.1.1
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/tools/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Applet to edit Claws Mail's hidden preferences

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	p5-Gtk2>=0:x11-toolkits/p5-Gtk2 \
		p5-Locale-gettext>=0:devel/p5-Locale-gettext

USES=		gmake perl5 shebangfix tar:xz
SHEBANG_FILES=	${PORTNAME}
NO_ARCH=	yes

PORTDOCS=	NEWS README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-tools

post-patch:
	@${REINPLACE_CMD} '/^MANDIR/ s|DATADIR|PREFIX|' ${WRKSRC}/Makefile

post-patch-NLS-off:
	@${REINPLACE_CMD} '/-C po/d' ${WRKSRC}/Makefile

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|g} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
