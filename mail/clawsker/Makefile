# Created by: Pawel Pekala <c0rn@o2.pl>
# $FreeBSD$

PORTNAME=	clawsker
PORTVERSION=	0.7.12
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/tools/

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Applet to edit Claws Mail's hidden preferences

LICENSE=	GPLv3

RUN_DEPENDS=	claws-mail>=3.9.1:${PORTSDIR}/mail/claws-mail \
		p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		p5-Locale-gettext>=0:${PORTSDIR}/devel/p5-Locale-gettext

USES=		shebangfix perl5
SHEBANG_FILES=	${PORTNAME}

PORTDOCS=	NEWS README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} '/^DATADIR/s|/share||' ${WRKSRC}/Makefile
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} '/-C po/d' ${WRKSRC}/Makefile
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|g} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
