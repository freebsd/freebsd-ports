# Ports collection makefile for:	zenmap
# Date created:				2008-01-13
# Whom:					Daniel Roethlisberger <daniel@roe.ch>
#
# $FreeBSD$
#

PORTNAME=	zenmap
PORTVERSION=	6.01
CATEGORIES=	security ipv6
MASTER_SITES=	http://nmap.org/dist/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	nmap-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI frontend for the nmap scanning utility

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/bin/nmap:${PORTSDIR}/security/nmap \
		${PYTHON_PACKAGENAMEPREFIX}sqlite3>:${PORTSDIR}/databases/py-sqlite3

WRKSRC=	${WRKDIR}/${DISTNAME}/${PORTNAME}

USE_BZIP2=	yes
USE_GNOME=	pygtk2
USE_GETTEXT=	yes
USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes

MLINKS=	zenmap.1 xnmap.1
MAN1=	zenmap.1 xnmap.1 ndiff.1

post-patch:
	@${REINPLACE_CMD} -e \
		'/self.create_uninstaller/s|^|#|' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e \
		's|share/man/man1|man/man1|' ${WRKSRC}/../ndiff/setup.py
post-build:
	@(cd ${WRKSRC}/../ndiff \
		&& ${PYTHON_CMD} setup.py build)
post-install:
	${INSTALL_MAN} ${WRKSRC}/../docs/zenmap.1 ${MAN1PREFIX}/man/man1
	@(cd ${WRKSRC}/../ndiff \
		&& ${PYTHON_CMD} setup.py install --prefix ${PREFIX})
.include <bsd.port.mk>
