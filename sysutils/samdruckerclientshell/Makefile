# $FreeBSD$

PORTNAME=	SamDruckerClientShell
PORTVERSION=	0.0.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=   GH

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Client for sending package information to SamDrucker

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	dlangille
GH_PROJECT=	SamDrucker

NO_BUILD=	YES

SUB_FILES=	999-samdrucker-client samdrucker.conf.sample

RUN_DEPENDS+=	curl>0:ftp/curl
RUN_DEPENDS+=	jo>0:textproc/jo

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/samdrucker
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/clients/samdrucker.sh
	${INSTALL_SCRIPT} ${WRKSRC}/clients/samdrucker.sh  ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/999-samdrucker-client  ${STAGEDIR}${PREFIX}/etc/periodic/daily
	${INSTALL_DATA}   ${WRKDIR}/samdrucker.conf.sample ${STAGEDIR}${PREFIX}/etc/samdrucker

.include <bsd.port.post.mk>
