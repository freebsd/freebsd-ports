PORTNAME=	clawsker
DISTVERSION=	1.4.0
PORTREVISION=	2
CATEGORIES=	mail perl5
MASTER_SITES=	http://www.claws-mail.org/tools/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Applet to edit Claws Mail's hidden preferences
WWW=		https://www.claws-mail.org/clawsker.php

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	claws-mail>=3.9.1:mail/claws-mail \
		p5-File-Which>=1.21:sysutils/p5-File-Which \
		p5-Gtk3>=0.030:x11-toolkits/p5-Gtk3 \
		p5-Locale-gettext>=1.05:devel/p5-Locale-gettext

USES=		desktop-file-utils gmake perl5 shebangfix tar:xz
SHEBANG_FILES=	${PORTNAME}
NO_ARCH=	yes

PORTDOCS=	NEWS README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-tools

post-patch-NLS-off:
	@${REINPLACE_CMD} '/-C po/d' ${WRKSRC}/Makefile

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|g} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
