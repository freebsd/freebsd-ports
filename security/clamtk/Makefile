# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clamtk
PORTVERSION=	4.45
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/ClamTk/${PORTVERSION}

MAINTAINER=	tj@FreeBSD.org
COMMENT=	GTK front-end for Clam Antivirus

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Config-Tiny>=2.12:devel/p5-Config-Tiny \
		p5-Date-Calc>=5.5.1:devel/p5-Date-Calc \
		p5-File-Find-Rule>=0.30:devel/p5-File-Find-Rule \
		p5-Locale-gettext>=1.05:devel/p5-Locale-gettext \
		p5-Net-DNS>=0.65:dns/p5-Net-DNS \
		clamscan:security/clamav \
		p5-libwww>=5.822:www/p5-libwww \
		zenity:x11/zenity \
		p5-Gtk2>=1.144:x11-toolkits/p5-Gtk2

NO_BUILD=	yes
USES=		gettext-runtime:run perl5 shebangfix
USE_PERL5=	run
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
	${INSTALL_DATA} ${WRKSRC}/images/${PORTNAME}-loader.gif ${STAGEDIR}${PREFIX}/share/pixmaps
	for l in ${LINGUAS}; do \
		${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/$${l}/LC_MESSAGES; \
		${INSTALL_DATA} ${WRKSRC}/po/$${l}.mo \
		${STAGEDIR}${PREFIX}/share/locale/$${l}/LC_MESSAGES/${PORTNAME}.mo; \
	done

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in CHANGES DISCLAIMER README
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
