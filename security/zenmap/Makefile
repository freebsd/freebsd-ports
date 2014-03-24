# Created by: Daniel Roethlisberger <daniel@roe.ch>
# $FreeBSD$

PORTNAME=	zenmap
PORTVERSION=	6.40
PORTREVISION=	1
CATEGORIES=	security ipv6
MASTER_SITES=	http://nmap.org/dist/ \
		SF/nemysisfreebsdp/security/:icons
DISTNAME=	nmap-${PORTVERSION}
DISTFILES=	nmap-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	nmap-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	GUI frontend for the Nmap scanning utility

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/bin/nmap:${PORTSDIR}/security/nmap \
		${PYTHON_PACKAGENAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3

WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}

USES=		dos2unix tar:bzip2
DOS2UNIX_GLOB=	*.xml
USE_GNOME=	pygtk2
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext

PLIST_FILES=	bin/ndiff \
		bin/zenmap-root \
		man/man1/ndiff.1.gz \
		man/man1/zenmap.1.gz \
		share/pixmaps/zenmap.png

SUB_FILES=	zenmap-root

.include <bsd.port.options.mk>

post-extract:
	@${RM} -f ${WRKSRC}/install_scripts/unix/su-to-zenmap.sh
	@${CP} -a ${FILESDIR}/pc-su ${WRKSRC}/install_scripts/unix/su-to-zenmap.sh

post-patch:
	@${REINPLACE_CMD} -e 's|su-to-zenmap.sh|zenmap-root|; \
		s| %F||' \
		${WRKSRC}/install_scripts/unix/zenmap-root.desktop
	@${REINPLACE_CMD} -e 's|Security;|Security;System;|' \
		${WRKSRC}/install_scripts/unix/zenmap-root.desktop \
		${WRKSRC}/install_scripts/unix/zenmap.desktop
	@${REINPLACE_CMD} \
		-e '/self.create_uninstaller/s|^|#|; \
		s|distutils\.command\.install |setuptools\.command\.install |; \
		s|self.saved_prefix, pixmaps_dir, ||' \
		${WRKSRC}/setup.py
	@${REINPLACE_CMD} \
		-e 's|share/man/man1|man/man1|; \
		s|"install": checked_install||' \
		${WRKSRC}/../ndiff/setup.py

.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -i '' '/locale_dir, mo_find, /d' ${WRKSRC}/setup.py
.endif

post-build:
	@(cd ${WRKSRC}/../ndiff \
		&& ${PYTHON_CMD} setup.py build)

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/zenmap-root ${STAGEDIR}${PREFIX}/bin/
	 @(cd ${STAGEDIR}${DATADIR} && ${CHMOD} 754 su-to-zenmap.sh)
	${INSTALL_MAN} ${WRKSRC}/../docs/zenmap.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1/
	@(cd ${WRKSRC}/../ndiff \
		&& ${PYTHON_CMD} setup.py install --prefix=${STAGEDIR}${PREFIX})
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
