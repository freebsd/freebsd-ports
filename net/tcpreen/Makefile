# New ports collection makefile for:	tcpreen
# Date created:				09.08.2002
# Whom:					Janos.Mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	tcpreen
PORTVERSION=	1.0.4
CATEGORIES=	net ipv6
MASTER_SITES=	http://rdenisc.free.fr/tcpreen/

MAINTAINER=	Janos.Mohacsi@bsd.hu

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
MAN1=		tcpreen.1

DOC_FILES=	README

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
