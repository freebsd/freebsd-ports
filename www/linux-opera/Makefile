# $FreeBSD: head/www/linux-opera/Makefile 362447 2014-07-21 16:17:27Z rene $

PORTNAME=	opera
PORTVERSION=	${OPERA_VER}
CATEGORIES=	www linux
MASTER_SITES=	ftp://ftp.opera.com/pub/opera/linux/${OPERA_VER:S/.//}/ \
		ftp://ftp.sunet.se/pub/www/clients/Opera/linux/${OPERA_VER:S/.//}/ \
		ftp://sunsite.cnlab-switch.ch/mirror/opera/linux/${OPERA_VER:S/.//}/ \
		ftp://ftp.tiscali.nl/pub/mirrors/opera/linux/${OPERA_VER:S/.//}/ \
		ftp://ftp.ntua.gr/pub/www/Opera/linux/${OPERA_VER:S/.//}/ \
		http://mirrors.pmmf.hu/mirror/opera/linux/${OPERA_VER:S/.//}/ \
		ftp://ftp.task.gda.pl/pub/opera/linux/${OPERA_VER:S/.//}/ \
		ftp://ftp.planetmirror.com/pub/opera/linux/${OPERA_VER:S/.//}/ \
		http://gd.tuwien.ac.at/infosys/browsers/opera/linux/${OPERA_VER:S/.//}/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/www/opera/linux/${OPERA_VER:S/.//}/&,}
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-${OPERA_VER}-${OPERA_BUILD}.i386.linux

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Blazingly fast, full-featured, standards-compliant browser

RUN_DEPENDS=	update-mime-database:${PORTSDIR}/misc/shared-mime-info

USE_LINUX=	yes
USE_LINUX_APPS=	gdkpixbuf gtk2 naslibs png sqlite3 xorglibs
ONLY_FOR_ARCHS=	i386 amd64
USES=		desktop-file-utils shared-mime-info tar:xz
WANT_GNOME=	yes
INSTALLS_ICONS=	yes

NO_BUILD=	yes

OPERA_VER?=	12.16
OPERA_BUILD?=	1860
DATADIR=	${PREFIX}/share/${UNIQUENAME}
DOCSDIR=	${PREFIX}/share/doc/${UNIQUENAME}

RENAME=		opera lib/opera \
		share/applications/opera-browser.desktop \
		share/doc/opera share/opera man/man1/opera.1 \
		share/mime/packages/opera-extension.xml

post-extract:
	@${GUNZIP_CMD} ${WRKSRC}/share/man/man1/*.gz
	@${MV} ${WRKSRC}/share/man ${WRKSRC}/man
	@for _r in ${RENAME}; do \
		linux=`${ECHO_CMD} $${_r} | \
		       ${SED} -e 's|opera|${UNIQUENAME}|g'`; \
		${MV} ${WRKSRC}/$${_r} ${WRKSRC}/$${linux}; \
	done; \
	for _f in `find ${WRKSRC}/share/icons -type f | \
		   ${SED} -e 's|${WRKSRC}/||g'`; do \
		linux=`${ECHO_CMD} $${_f} | \
		       ${SED} -e 's|opera|${UNIQUENAME}|g'`; \
		${MV} ${WRKSRC}/$${_f} ${WRKSRC}/$${linux}; \
	done; \
	for _l in `find ${WRKSRC}/share/icons -name opera-widget.png | \
		   ${SED} -e 's|/opera-widget\.png||g'`; do \
		${RM} $${_l}/opera-widget.png; \
		cd $${_l}; \
		${LN} -s ../mimetypes/${UNIQUENAME}-widget.png \
			$${_l}/${UNIQUENAME}-widget.png; \
	done

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g ; \
		s|%%LINUXBASE%%|${LINUXBASE}|g' \
			${WRKSRC}/share/${UNIQUENAME}/defaults/pluginpath.ini
	@${REINPLACE_CMD} -e '/man1/s|opera|${UNIQUENAME}|g ; \
		/man1/s|1.gz|1|g ; /man1/s|share/||g ; \
		s|bin/opera|bin/${UNIQUENAME}|g ; \
		s|name=$$(uname -s)|name=Linux|g ; \
		s|lib/opera|lib/${UNIQUENAME}|g ; \
		s|applications/opera|applications/${UNIQUENAME}|g ; \
		s|doc/opera|doc/${UNIQUENAME}|g ; \
		/hicolor/s|/opera|/${UNIQUENAME}|g ; \
		s|packages/opera|packages/${UNIQUENAME}|g ; \
		s|share/opera|share/${UNIQUENAME}|g ; \
		s|PREFIX=/usr/local|PREFIX=${PREFIX}|g ; \
		/OPERA_PERSONALDIR/s|.opera|.${UNIQUENAME}|g ; \
		s|opera)|${UNIQUENAME})|g ; \
		s|opera-widget-manager)|${UNIQUENAME}-widget-manager)|g ; \
		s|^.*rmdir.*mime/packages.*||g ; \
		s|^.*GX - bin/uninstall-opera@.*||g ; \
		s|[$$]tempdir/damaged|${WRKSRC}/damaged|g ; \
		s|PREFIX/bin/uninstall-opera|PREFIX/bin/disabled-opera|g' \
			${WRKSRC}/install
	@${REINPLACE_CMD} -e '/^Name/s|$$| (Linux version)|g ; \
		/Exec/s|opera|${UNIQUENAME}|g ; \
		/Icon/s|opera|${UNIQUENAME}|g ; \
		/StartupWMClass/s|opera|${UNIQUENAME}|g ; \
		s|TryExec=.*||g ; /^$$/d' \
			${WRKSRC}/share/applications/*.desktop
	@${REINPLACE_CMD} -e 's|lib/opera|lib/${UNIQUENAME}|g ; \
		s|doc/opera|doc/${UNIQUENAME}|g ; \
		s|share/opera|share/${UNIQUENAME}|g ; \
		s|opera-widget-manager|${UNIQUENAME}-widget-manager|g ; \
		s|opera (1)|${UNIQUENAME} (1)|g ; \
		s|\.opera@@|\.${UNIQUENAME}@@|g ; \
		s|B opera@@|B ${UNIQUENAME}@@|g ; \
		/standards-compliant/s|opera|${UNIQUENAME}|g' \
			${WRKSRC}/man/man1/*.1
	@${REINPLACE_CMD} -e '/<generic-icon/s|opera|${UNIQUENAME}|g' \
			${WRKSRC}/share/mime/packages/*.xml
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${FIND} ${WRKSRC} -name '*.bak' -delete

do-install:
	@(cd ${WRKSRC} && ./install --repackage ${STAGEDIR}${PREFIX} --system --quiet --force)

.include <bsd.port.mk>
