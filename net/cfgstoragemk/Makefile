# ex:ts=8
# Ports collection makefile for:	cfgstoragemk
# Date created:			Jul 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cfgstoragemk
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://savannah.gnu.org/download/cfgstoragemk/
DISTNAME=	cfgstoragemaker-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MRTG configuration generator for storage monitoring via SNMP

USE_PERL5=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=	cfgstoragemaker.1

post-patch:
	@${PERL} -pi -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/cfgstoragemaker
	@${PERL} -pi -e "s,%%PREFIX%%,${PREFIX},g ; \
		s,%%LOCALBASE%%,${LOCALBASE},g" ${WRKSRC}/cfgstoragemaker.1

.include <bsd.port.mk>
