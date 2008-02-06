# New ports collection makefile for:	clamtk
# Date created:		24 February 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clamtk
PORTVERSION=	3.08
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	GTK front-end for Clam Antivirus

RUN_DEPENDS=	p5-Gtk2>=1.144:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		p5-File-Find-Rule>=0.30:${PORTSDIR}/devel/p5-File-Find-Rule \
		p5-Date-Calc>=5.5.1:${PORTSDIR}/devel/p5-Date-Calc \
		p5-gettext>=1.05:${PORTSDIR}/devel/p5-Locale-gettext \
		p5-Config-Tiny>=2.12:${PORTSDIR}/devel/p5-Config-Tiny \
		clamscan:${PORTSDIR}/security/clamav

NO_BUILD=	yes
USE_GETTEXT=	yes
MAN1=		${PORTNAME}.1
PORTDOCS=	CHANGES DISCLAIMER LICENSE README

post-extract:
	@${GUNZIP_CMD} ${WRKSRC}/${PORTNAME}.1.gz

post-patch:
	@${REINPLACE_CMD} -e '/command.*--un/d;/bin\/file/!s|/usr/bin|${LOCALBASE}/bin|g;\
		s|/var/lib/clamav|/var/db/clamav|;s|/usr/share|${PREFIX}/share|g'\
			${WRKSRC}/${PORTNAME}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1/
	@${INSTALL} -d ${PREFIX}/share/applications/
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${PREFIX}/share/applications/
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.png ${PREFIX}/share/pixmaps/
	@cd ${WRKSRC}/po/&&for i in *.mo;do\
		${MKDIR} ${PREFIX}/share/locale/$${i%.mo}/LC_MESSAGES/;\
		${INSTALL_DATA} $$i ${PREFIX}/share/locale/$${i%.mo}/LC_MESSAGES/${PORTNAME}.mo;\
	done
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
