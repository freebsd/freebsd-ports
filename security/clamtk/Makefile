PORTNAME=	clamtk
DISTVERSIONPREFIX=	v
DISTVERSION=	6.19
CATEGORIES=	security

MAINTAINER=	tmp386@live.com
COMMENT=	GTK front-end for Clam Antivirus
WWW=		https://github.com/piposeimandi/clamtk/ \
		https://gitlab.com/dave_m/clamtk/-/wikis/home/

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Locale-gettext>=1.05:devel/p5-Locale-gettext \
		p5-Text-CSV>=0:textproc/p5-Text-CSV \
		p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-JSON>=0:converters/p5-JSON \
		clamscan:security/clamav \
		p5-libwww>=5.822:www/p5-libwww \
		p5-Gtk3>=0:x11-toolkits/p5-Gtk3 \
		gnome-icon-theme>=0:misc/gnome-icon-theme \
		icons-tango>0:x11-themes/icons-tango

USES=		gettext-runtime:run perl5 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	piposeimandi
GH_TAGNAME=	32cc526
USE_PERL5=	run
SHEBANG_FILES=	clamtk
NO_BUILD=	yes
PORTDOCS=	CHANGES DISCLAIMER.md README.md
OPTIONS_DEFINE=	DOCS

post-extract:
	@${GUNZIP_CMD} ${WRKSRC}/${PORTNAME}.1.gz

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local|${LOCALBASE}|g ; \
		 s|/usr/share|${PREFIX}/share|g ; \
		 s|/var/lib/clamav|/var/db/clamav|g' ${WRKSRC}/lib/ClamTk/*.pm

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/ClamTk
	${INSTALL_DATA} ${WRKSRC}/lib/ClamTk/*.pm ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/ClamTk
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/images/${PORTNAME}.png \
			${WRKSRC}/images/${PORTNAME}.xpm ${STAGEDIR}${PREFIX}/share/pixmaps

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
