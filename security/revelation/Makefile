# New ports collection makefile for:	revelation
# Date created:		2004-08-10
# Whom:			ports@c0decafe.net
#
# $FreeBSD$
#

PORTNAME=	revelation
PORTVERSION=	0.3.2
CATEGORIES=	security gnome
MASTER_SITES=	ftp://oss.codepoet.no/revelation/

MAINTAINER=	ports@c0decafe.net
COMMENT=	Password manager for the GNOME 2 desktop

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2\
		${PYTHON_SITELIBDIR}/Crypto/test.py:${PORTSDIR}/security/py-pycrypto

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	pygnome2
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} 's#share/#share/gnome/#g' \
		${WRKSRC}/setup.py ${WRKSRC}/src/lib/__init__.py
	@${REINPLACE_CMD} 's#sys\.prefix#"${PREFIX}"#g' \
		${WRKSRC}/src/lib/__init__.py

.include <bsd.port.mk>
