# ex:ts=8
# New ports collection makefile for:	xmlppm
# Date created:			May 15, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xmlppm
PORTVERSION=	0.96
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.cs.cornell.edu/People/jcheney/xmlppm/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	expat.4:${PORTSDIR}/textproc/expat2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
USE_REINPLACE=	yes
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE},g" ${WRKSRC}/Makefile

do-install:
	@(cd ${WRKSRC} ; ${INSTALL_PROGRAM} xmlppm xmlunppm ${PREFIX}/bin)

.include <bsd.port.mk>
