# $FreeBSD$

PORTNAME=	opera
PORTVERSION=	${OPERA_VER}
PORTREVISION=	5
CATEGORIES=	www linux
MASTER_SITES=	http://snapshot.opera.com/${MASTER_SITES_VER_PATH}/
PKGNAMEPREFIX=	linux-
PKGNAMESUFFIX=	-devel
DISTNAME=	${OPERA_NEXT}-${OPERA_VER}-${OPERA_BUILD}.i386.linux
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	A blazingly fast, full-featured, standards-compliant browser (next version)
IGNORE=		Development version is not currently active. Use www/linux-opera instead of

RUN_DEPENDS=	update-mime-database:${PORTSDIR}/misc/shared-mime-info

USE_XZ=		yes
USE_LINUX=	yes
USE_LINUX_APPS=	aspell naslibs png xorglibs
ONLY_FOR_ARCHS=	i386 amd64
USE_GNOME=	desktopfileutils
WANT_GNOME=	yes
INSTALLS_ICONS=	yes

NO_BUILD=	yes
LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}

OPERA_NEXT?=	${PORTNAME}-next
OPERA_VER?=	12.00
OPERA_BUILD?=	1213
MASTER_SITES_VER_PATH=	unix/hwa_${OPERA_VER}-${OPERA_BUILD}
DATADIR=	${PREFIX}/share/${PKGNAMEPREFIX}${OPERA_NEXT}
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${OPERA_NEXT}

MAN1=		linux-opera-next.1 linux-opera-next-widget-manager.1

RENAME=		opera-next opera-next-widget-manager lib/opera-next \
		share/applications/opera-next-browser.desktop \
		share/applications/opera-next-widget-installer.desktop \
		share/applications/opera-next-widget-manager.desktop \
		share/doc/opera-next share/opera-next man/man1/opera-next.1 \
		man/man1/opera-next-widget-manager.1 \
		share/mime/packages/opera-next-extension.xml \
		share/mime/packages/opera-next-unite-application.xml \
		share/mime/packages/opera-next-widget.xml

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION}<700055
IGNORE=	you need FreeBSD>=7.0 RELEASE with Linux emulation 2.6.x.
.elif ${OSVERSION}<800076 && ! defined (OVERRIDE_LINUX_NONBASE_PORTS)
IGNORE=	you need to use non-default linux ports (define OVERRIDE_LINUX_BASE_PORT=f8 and OVERRIDE_LINUX_NONBASE_PORTS=f8). You also can use f10 instead of f8, but I only have tested it with f8.
.endif

post-extract:
	@${GUNZIP_CMD} ${WRKSRC}/share/man/man1/*.gz
	@${MV} ${WRKSRC}/share/man ${WRKSRC}/man
	@for _r in ${RENAME}; do \
		linux=`${ECHO_CMD} $${_r} | \
		       ${SED} -e 's|opera-next|${PKGNAMEPREFIX}${OPERA_NEXT}|g'`; \
		${MV} ${WRKSRC}/$${_r} ${WRKSRC}/$${linux}; \
	done; \
	for _f in `find ${WRKSRC}/share/icons -type f | \
		   ${SED} -e 's|${WRKSRC}/||g'`; do \
		linux=`${ECHO_CMD} $${_f} | \
		       ${SED} -e 's|opera-next|${PKGNAMEPREFIX}${OPERA_NEXT}|g'`; \
		${MV} ${WRKSRC}/$${_f} ${WRKSRC}/$${linux}; \
	done; \
	for _l in `find ${WRKSRC}/share/icons -name opera-widget.png | \
		   ${SED} -e 's|/opera-widget\.png||g'`; do \
		${RM} $${_l}/opera-widget.png; \
		cd $${_l}; \
		${LN} -s ../mimetypes/${PKGNAMEPREFIX}${OPERA_NEXT}-widget.png \
			$${_l}/${PKGNAMEPREFIX}${OPERA_NEXT}-widget.png; \
	done

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g ; \
		s|%%LINUXBASE%%|${LINUXBASE}|g' \
			${WRKSRC}/share/${PKGNAMEPREFIX}${OPERA_NEXT}/defaults/pluginpath.ini
	@${REINPLACE_CMD} -e '/man1/s|opera|${PKGNAMEPREFIX}${PORTNAME}|g ; \
		/man1/s|1.gz|1|g ; /man1/s|share/||g ; \
		s|bin/opera|bin/${PKGNAMEPREFIX}${PORTNAME}|g ; \
		s|name=$$(uname -s)|name=Linux|g ; \
		s|lib/opera|lib/${PKGNAMEPREFIX}${PORTNAME}|g ; \
		s|applications/opera|applications/${PKGNAMEPREFIX}${PORTNAME}|g ; \
		s|doc/opera|doc/${PKGNAMEPREFIX}${PORTNAME}|g ; \
		/hicolor/s|/opera|/${PKGNAMEPREFIX}${PORTNAME}|g ; \
		s|packages/opera|packages/${PKGNAMEPREFIX}${PORTNAME}|g ; \
		s|share/opera|share/${PKGNAMEPREFIX}${PORTNAME}|g ; \
		s|PREFIX=/usr/local|PREFIX=${PREFIX}|g ; \
		/OPERA_PERSONALDIR/s|.opera|.${PKGNAMEPREFIX}${PORTNAME}|g ; \
		s|opera-next)|${PKGNAMEPREFIX}${OPERA_NEXT})|g ; \
		s|opera-next-widget-manager)|${PKGNAMEPREFIX}${OPERA_NEXT}-widget-manager)|g ; \
		s|^.*rmdir.*mime/packages.*||g ; \
		s|^.*GX - bin/uninstall-opera@.*||g ; \
		s|[$$]tempdir/damaged|${WRKSRC}/damaged|g ; \
		s|PREFIX/bin/uninstall-opera|PREFIX/bin/disabled-opera|g' \
			${WRKSRC}/install
	@${REINPLACE_CMD} -e '/^Name/s|$$| (Linux version)|g ; \
		/Exec/s|opera|${PKGNAMEPREFIX}${PORTNAME}|g ; \
		/Icon/s|opera|${PKGNAMEPREFIX}${PORTNAME}|g ; \
		/StartupWMClass/s|opera|${PKGNAMEPREFIX}${OPERA_NEXT}|g ; \
		s|TryExec=.*||g ; /^$$/d' \
			${WRKSRC}/share/applications/*.desktop
	@${REINPLACE_CMD} -e 's|lib/opera|lib/${PKGNAMEPREFIX}${PORTNAME}|g ; \
		s|doc/opera|doc/${PKGNAMEPREFIX}${PORTNAME}|g ; \
		s|share/opera|share/${PKGNAMEPREFIX}${PORTNAME}|g ; \
		s|opera-widget-manager|${PKGNAMEPREFIX}${OPERA_NEXT}-widget-manager|g ; \
		s|opera (1)|${PKGNAMEPREFIX}${OPERA_NEXT} (1)|g ; \
		s|\.opera@@|\.${PKGNAMEPREFIX}${OPERA_NEXT}@@|g ; \
		s|B opera@@|B ${PKGNAMEPREFIX}${OPERA_NEXT}@@|g ; \
		/standards-compliant/s|opera|${PKGNAMEPREFIX}${OPERA_NEXT}|g' \
			${WRKSRC}/man/man1/*.1
	@${REINPLACE_CMD} -e '/<generic-icon/s|opera|${PKGNAMEPREFIX}${PORTNAME}|g' \
			${WRKSRC}/share/mime/packages/*.xml
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${FIND} ${WRKSRC} -name '*.bak' -delete

do-install:
	@(cd ${WRKSRC} && ./install --system --quiet --force)

.include <bsd.port.post.mk>
