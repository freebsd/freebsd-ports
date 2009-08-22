# Ports collection makefile for:  pantera
# Date created:			  8 Nov 2006
# Whom:				  Yonatan <onatan@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pantera
PORTVERSION=	0.1.1
CATEGORIES=	security
MASTER_SITES=	SF/owasp/Pantera/Pantera_Release_${PORTVERSION}
DISTNAME=	Pantera_Release_${PORTVERSION}

MAINTAINER=	onatan@gmail.com
COMMENT=	Web Application Penetration Testing Suite

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/OpenSSL/SSL.so:${PORTSDIR}/security/py-openssl \
		${PYTHON_SITELIBDIR}/MySQLdb/connections.pyc:${PORTSDIR}/databases/py-MySQLdb
RUN_DEPENDS=	${BUILD_DEPENDS}

.if !defined(WITHOUT_MYSQL_SERVER)
BUILD_DEPENDS+=	mysql:${PORTSDIR}/databases/mysql${MYSQL_VER}-server
.endif

WRKSRC=		${WRKDIR}/Pantera_Release
USE_ZIP=	yes
USE_PYTHON=	yes
USE_MYSQL=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message pantera.sh
SUB_LIST+=	SCRIPTDIR=${SCRIPTDIR}
PKGMESSAGE=	${WRKDIR}/pkg-message

do-install:
	@${MKDIR} ${DATADIR}
	${CP} -Rp ${WRKSRC}/* ${DATADIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/pantera.sh ${PREFIX}/bin

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
