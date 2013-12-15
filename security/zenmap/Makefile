# Created by: Daniel Roethlisberger <daniel@roe.ch>
# $FreeBSD$

PORTNAME=	zenmap
PORTVERSION=	6.40
CATEGORIES=	security ipv6
MASTER_SITES=	http://nmap.org/dist/
DISTNAME=	nmap-${PORTVERSION}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	GUI frontend for the Nmap scanning utility

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/bin/nmap:${PORTSDIR}/security/nmap \
		${PYTHON_PACKAGENAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3

WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}

USE_BZIP2=	yes
USES=		desktop-file-utils
USE_GNOME=	pygtk2
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

MLINKS=	zenmap.1 xnmap.1
MAN1=	zenmap.1 ndiff.1

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-extract:
	@${RM} -f ${WRKSRC}/install_scripts/unix/su-to-zenmap.sh
	@${CP} -a ${FILESDIR}/pc-su ${WRKSRC}/install_scripts/unix/su-to-zenmap.sh

post-patch:
	@${REINPLACE_CMD} -e 's|su-to-zenmap.sh %F|su-to-zenmap.sh ${PORTNAME}|' \
		${WRKSRC}/install_scripts/unix/zenmap-root.desktop
	@${REINPLACE_CMD} \
		-e '/self.create_uninstaller/s|^|#|' \
		-e 's,distutils\.command\.install ,setuptools\.command\.install ,' \
		${WRKSRC}/setup.py
	@${REINPLACE_CMD} \
		-e 's|share/man/man1|man/man1|' \
		-e 's,"install": checked_install,,' \
		${WRKSRC}/../ndiff/setup.py
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -i '' '/locale_dir, mo_find, /d' ${WRKSRC}/setup.py
.endif

post-build:
	@(cd ${WRKSRC}/../ndiff \
		&& ${PYTHON_CMD} setup.py build)

post-install:
	${INSTALL_MAN} ${WRKSRC}/../docs/zenmap.1 ${MAN1PREFIX}/man/man1
	@(cd ${WRKSRC}/../ndiff \
		&& ${PYTHON_CMD} setup.py install --prefix=${PREFIX})

.include <bsd.port.mk>
