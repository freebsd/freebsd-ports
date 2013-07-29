# Created by: Satoshi Asami <asami@FreeBSD.org>
# $FreeBSD$

PORTNAME=	chimera
PORTVERSION=	1.70p0
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://www.rocklinux.net/people/ripclaw/projects/software/chimera/devel/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X/Athena-based World Wide Web client

RUN_DEPENDS= 	${LOCALBASE}/etc/mime.types:${PORTSDIR}/misc/mime-support

NO_LATEST_LINK=	yes
USES=		imake
USE_XORG=	ice sm x11 xaw xext xmu xpm xt

MAN1=		chimera.1

# Call the port's configure script explicitly, since USES=imake masks it out
pre-configure:
	${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure

.include <bsd.port.mk>
