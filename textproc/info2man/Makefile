# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	info2man
PORTVERSION=	20040717
CATEGORIES=	textproc
MASTER_SITES=	http://www.cskk.ezoshosting.com/cs/css/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Translate GNU info files into man pages

USES=		perl5
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLSCRIPTS=	info2man info2pod

NO_STAGE=	yes
pre-configure:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' ${WRKSRC}/info2pod

do-install:
	${INSTALL_SCRIPT} ${PLSCRIPTS:S|^|${WRKSRC}/|} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/cs ${DATADIR}

.include <bsd.port.mk>
