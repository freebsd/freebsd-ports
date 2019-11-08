# $FreeBSD$

PORTNAME=	opera
PORTVERSION=	${OPERA_VER}
PORTREVISION=	3
CATEGORIES=	www linux
MASTER_SITES=	ftp://ftp.opera.com/pub/opera/linux/${OPERA_VER:S/.//}/ \
		ftp://ftp.sunet.se/pub/www/clients/Opera/linux/${OPERA_VER:S/.//}/ \
		ftp://sunsite.cnlab-switch.ch/mirror/opera/linux/${OPERA_VER:S/.//}/ \
		ftp://ftp.tiscali.nl/pub/mirrors/opera/linux/${OPERA_VER:S/.//}/ \
		ftp://ftp.ntua.gr/pub/www/Opera/linux/${OPERA_VER:S/.//}/ \
		http://mirrors.pmmf.hu/mirror/opera/linux/${OPERA_VER:S/.//}/ \
		ftp://ftp.task.gda.pl/pub/opera/linux/${OPERA_VER:S/.//}/ \
		ftp://ftp.planetmirror.com/pub/opera/linux/${OPERA_VER:S/.//}/ \
		http://gd.tuwien.ac.at/infosys/browsers/opera/linux/${OPERA_VER:S/.//}/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-${OPERA_VER}-${OPERA_BUILD}.i386.linux

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Blazingly fast, full-featured, standards-compliant browser

RUN_DEPENDS=	update-mime-database:misc/shared-mime-info

USES=		desktop-file-utils gnome linux shared-mime-info tar:xz
USE_LINUX=	gtk2 sqlite3 xorglibs
ONLY_FOR_ARCHS=	i386 amd64
INSTALLS_ICONS=	yes

NO_BUILD=	yes

OPERA_VER?=	12.16
OPERA_BUILD?=	1860
DATADIR=	${PREFIX}/share/${PKGBASE}
DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

RENAME=		opera lib/opera \
		share/applications/opera-browser.desktop \
		share/doc/opera share/opera man/man1/opera.1 \
		share/mime/packages/opera-extension.xml

OPTIONS_DEFINE=	DOCS

post-extract:
	@${GUNZIP_CMD} ${WRKSRC}/share/man/man1/*.gz
	@${MV} ${WRKSRC}/share/man ${WRKSRC}/man
	@for _r in ${RENAME}; do \
		linux=`${ECHO_CMD} $${_r} | \
		       ${SED} -e 's|opera|${PKGBASE}|g'`; \
		${MV} ${WRKSRC}/$${_r} ${WRKSRC}/$${linux}; \
	done; \
	for _f in `find ${WRKSRC}/share/icons -type f | \
		   ${SED} -e 's|${WRKSRC}/||g'`; do \
		linux=`${ECHO_CMD} $${_f} | \
		       ${SED} -e 's|opera|${PKGBASE}|g'`; \
		${MV} ${WRKSRC}/$${_f} ${WRKSRC}/$${linux}; \
	done; \
	for _l in `find ${WRKSRC}/share/icons -name opera-widget.png | \
		   ${SED} -e 's|/opera-widget\.png||g'`; do \
		${RM} $${_l}/opera-widget.png; \
		cd $${_l}; \
		${LN} -s ../mimetypes/${PKGBASE}-widget.png \
			$${_l}/${PKGBASE}-widget.png; \
	done

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g ; \
		s|%%LINUXBASE%%|${LINUXBASE}|g' \
			${WRKSRC}/share/${PKGBASE}/defaults/pluginpath.ini
	@${REINPLACE_CMD} -e '/man1/s|opera|${PKGBASE}|g ; \
		/man1/s|1.gz|1|g ; /man1/s|share/||g ; \
		s|bin/opera|bin/${PKGBASE}|g ; \
		s|name=$$(uname -s)|name=Linux|g ; \
		s|lib/opera|lib/${PKGBASE}|g ; \
		s|applications/opera|applications/${PKGBASE}|g ; \
		s|doc/opera|doc/${PKGBASE}|g ; \
		/hicolor/s|/opera|/${PKGBASE}|g ; \
		s|packages/opera|packages/${PKGBASE}|g ; \
		s|share/opera|share/${PKGBASE}|g ; \
		s|PREFIX=/usr/local|PREFIX=${PREFIX}|g ; \
		/OPERA_PERSONALDIR/s|.opera|.${PKGBASE}|g ; \
		s|opera)|${PKGBASE})|g ; \
		s|opera-widget-manager)|${PKGBASE}-widget-manager)|g ; \
		s|^.*rmdir.*mime/packages.*||g ; \
		s|^.*GX - bin/uninstall-opera@.*||g ; \
		s|[$$]tempdir/damaged|${WRKSRC}/damaged|g ; \
		s|PREFIX/bin/uninstall-opera|PREFIX/bin/disabled-opera|g' \
			${WRKSRC}/install
	@${REINPLACE_CMD} -e '/^Name/s|$$| (Linux version)|g ; \
		/Exec/s|opera|${PKGBASE}|g ; \
		/Icon/s|opera|${PKGBASE}|g ; \
		/StartupWMClass/s|opera|${PKGBASE}|g ; \
		s|TryExec=.*||g ; /^$$/d' \
			${WRKSRC}/share/applications/*.desktop
	@${REINPLACE_CMD} -e 's|lib/opera|lib/${PKGBASE}|g ; \
		s|doc/opera|doc/${PKGBASE}|g ; \
		s|share/opera|share/${PKGBASE}|g ; \
		s|opera-widget-manager|${PKGBASE}-widget-manager|g ; \
		s|opera (1)|${PKGBASE} (1)|g ; \
		s|\.opera@@|\.${PKGBASE}@@|g ; \
		s|B opera@@|B ${PKGBASE}@@|g ; \
		/standards-compliant/s|opera|${PKGBASE}|g' \
			${WRKSRC}/man/man1/*.1
	@${REINPLACE_CMD} -e '/<generic-icon/s|opera|${PKGBASE}|g' \
			${WRKSRC}/share/mime/packages/*.xml
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${FIND} ${WRKSRC} -name '*.bak' -delete

do-install:
	@(cd ${WRKSRC} && ./install --repackage ${STAGEDIR}${PREFIX} --system --quiet --force)

.include <bsd.port.mk>
