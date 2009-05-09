# New ports collection makefile for:	clamtk
# Date created:		24 February 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clamtk
PORTVERSION=	4.12
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK front-end for Clam Antivirus

RUN_DEPENDS=	p5-Config-Tiny>=2.12:${PORTSDIR}/devel/p5-Config-Tiny \
		p5-Date-Calc>=5.5.1:${PORTSDIR}/devel/p5-Date-Calc \
		p5-File-Find-Rule>=0.30:${PORTSDIR}/devel/p5-File-Find-Rule \
		p5-File-Path>=2.07:${PORTSDIR}/devel/p5-File-Path \
		p5-gettext>=1.05:${PORTSDIR}/devel/p5-Locale-gettext \
		p5-Net-DNS>=0.65:${PORTSDIR}/dns/p5-Net-DNS \
		clamscan:${PORTSDIR}/security/clamav \
		p5-libwww>=5.822:${PORTSDIR}/www/p5-libwww \
		zenity:${PORTSDIR}/x11/zenity \
		p5-Gtk2>=1.144:${PORTSDIR}/x11-toolkits/p5-Gtk2

NO_BUILD=	yes
USE_PERL5_RUN=	yes
USE_GETTEXT=	yes

MAN1=		${PORTNAME}.1

post-extract:
	@${GUNZIP_CMD} ${WRKSRC}/${PORTNAME}.1.gz

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/bin|${LOCALBASE}/bin|g ; \
		 s|/usr/share|${PREFIX}/share|g ; \
		 s|/var/lib/clamav|/var/db/clamav|g' ${WRKSRC}/lib/*.pm

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1
	@${MKDIR} ${SITE_PERL}/ClamTk
	${INSTALL_DATA} ${WRKSRC}/lib/*.pm ${SITE_PERL}/ClamTk
	@${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.png ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.xpm ${PREFIX}/share/pixmaps
.for lang in cs_CZ da de es fr gl it ja ko nl pl pt_BR ro ru sk sl sv tr zh_CN
	@${MKDIR} ${PREFIX}/share/locale/${lang}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${lang}.mo \
		${PREFIX}/share/locale/${lang}/LC_MESSAGES/${PORTNAME}.mo
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in CHANGES DISCLAIMER LICENSE README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
