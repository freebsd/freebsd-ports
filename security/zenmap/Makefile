# Created by: Daniel Roethlisberger <daniel@roe.ch>
# $FreeBSD$

PKGNAMEPREFIX=	ze

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	GUI frontend for the Nmap scanning utility

RUN_DEPENDS=	nmap:security/nmap \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${FLAVOR}

MASTERDIR=	${.CURDIR}/../nmap
PATCHDIR=	${.CURDIR}/files
FILESDIR=	${.CURDIR}/files
DATADIR=	${PREFIX}/share/${PKGNAMEPREFIX}${PORTNAME}
PKGDIR=		${.CURDIR}
WRKSRC_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}

USES=		dos2unix python:2.7 tar:bzip2
DOS2UNIX_GLOB=	*.xml
USE_GNOME=	pygtk2
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext

SUB_FILES=	zenmap-root

post-patch:
	@${RM} ${WRKSRC}/install_scripts/unix/su-to-zenmap.sh
	@${CP} -a ${FILESDIR}/pc-su ${WRKSRC}/install_scripts/unix/su-to-zenmap.sh
	@${FIND} ${WRKSRC} -name '*.py' -or -name '*.pyw' | ${XARGS} \
		${REINPLACE_CMD} -e 's|^.*#!.*python.*$$|#!${PYTHON_CMD}|'
	@${REINPLACE_CMD} -e 's|^.*#!.*python.*$$|#!${PYTHON_CMD}|' \
		${WRKSRC}/zenmap
	@${FIND} ${WRKSRC}/../ndiff -name '*.py' | ${XARGS} \
		${REINPLACE_CMD} -e 's|^.*#!.*python.*$$|#!${PYTHON_CMD}|'
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
		-e 's|share/man/man1|man/man1|' \
		-e '/"install": checked_install/d' \
		${WRKSRC}/../ndiff/setup.py
	@${FIND} ${WRKSRC} -name "*.bak" -delete
	@${FIND} ${WRKSRC}/../ndiff -name "*.bak" -delete

post-patch-NLS-off:
	@${REINPLACE_CMD} -i '' '/locale_dir, mo_find, /d' ${WRKSRC}/setup.py

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/zenmap-root ${STAGEDIR}${PREFIX}/bin/
	@${CHMOD} 754 ${STAGEDIR}${DATADIR}/su-to-zenmap.sh
	${INSTALL_MAN} ${WRKSRC}/../docs/zenmap.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1/
	@(cd ${WRKSRC}/../ndiff \
		&& ${PYTHON_CMD} setup.py install --prefix=${STAGEDIR}${PREFIX})
	@(cd ${STAGEDIR}${PYTHON}${PYTHON_SITELIBDIR} && ${RM} ndiff.pyc)
	@(cd ${STAGEDIR}${PYTHON}${PYTHON_SITELIBDIR} && ${PYTHON_CMD} -m compileall .)
	@(cd ${STAGEDIR}${PYTHON}${PYTHON_SITELIBDIR} && ${PYTHON_CMD} -O -m compileall .)
	@(cd ${STAGEDIR}${PREFIX}/share/pixmaps && ${LN} -sf ../zenmap/pixmaps/zenmap.png zenmap.png)

.include "${MASTERDIR}/Makefile"
