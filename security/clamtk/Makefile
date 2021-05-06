# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>

PORTNAME=	clamtk
PORTVERSION=	6.11
DISTVERSIONPREFIX=v
CATEGORIES=	security

MAINTAINER=	nc@FreeBSD.org
COMMENT=	GTK front-end for Clam Antivirus

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

NO_BUILD=	yes
USES=		gettext-runtime:run perl5 shebangfix
USE_PERL5=	run
USE_GITHUB=	yes
GH_ACCOUNT=	dave-theunsub
GH_TAGNAME=	1f026f0
SHEBANG_FILES=	clamtk

LINGUAS=	`${LS} ${WRKSRC}/po/*.mo | ${XARGS} ${BASENAME} -s .mo`

OPTIONS_DEFINE=	DOCS

post-extract:
	@${GUNZIP_CMD} ${WRKSRC}/${PORTNAME}.1.gz

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local|${LOCALBASE}|g ; \
		 s|/usr/share|${PREFIX}/share|g ; \
		 s|/var/lib/clamav|/var/db/clamav|g' ${WRKSRC}/lib/*.pm

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/ClamTk
	${INSTALL_DATA} ${WRKSRC}/lib/*.pm ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/ClamTk
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/images/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/images/${PORTNAME}.xpm ${STAGEDIR}${PREFIX}/share/pixmaps

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in CHANGES DISCLAIMER README.md
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
