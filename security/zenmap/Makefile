# Ports collection makefile for:	zenmap
# Date created:				2008-01-13
# Whom:					Daniel Roethlisberger <daniel@roe.ch>
#
# $FreeBSD$
#

PORTNAME=	zenmap
PORTVERSION=	4.52
CATEGORIES=	security ipv6
MASTER_SITES=	http://download.insecure.org/nmap/dist/ \
		http://www.mirrors.wiretapped.net/security/network-mapping/nmap/ \
		http://www.mirrorservice.org/sites/ftp.wiretapped.net/pub/security/network-mapping/nmap/ \
		http://mirror.sg.depaul.edu/pub/security/nmap/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	nmap-${PORTVERSION}

MAINTAINER=	daniel@roe.ch
COMMENT=	GUI frontend for the nmap scanning utility

RUN_DEPENDS=	${LOCALBASE}/bin/nmap:${PORTSDIR}/security/nmap \
		${PYTHON_SITELIBDIR}/pysqlite2/__init__.py:${PORTSDIR}/databases/py-pysqlite23

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_GNOME=	pygtk2
INSTALLS_EGGINFO=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
WITHOUT_PSYCO=	yes
.endif

.ifndef(WITHOUT_PSYCO)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psyco/_psyco.so:${PORTSDIR}/devel/py-psyco
.endif

pre-everything::
.ifndef(WITHOUT_PSYCO)
	@${ECHO_MSG} '===> Define WITHOUT_PSYCO to disable devel/py-psyco optimization'
.endif

do-build:
	cd ${WRKSRC}/${PORTNAME} && \
		${PYTHON_CMD} setup.py build

do-install:
	cd ${WRKSRC}/${PORTNAME} && \
		${PYTHON_CMD} setup.py install --prefix ${PREFIX}

.include <bsd.port.post.mk>
