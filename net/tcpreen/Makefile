# New ports collection makefile for:	tcpreen
# Date created:				09.08.2002
# Whom:					Janos.Mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	tcpreen
PORTVERSION=	1.2.2
CATEGORIES=	net ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	Janos.Mohacsi@bsd.hu
COMMENT=	A simple TCP session re-engineering tool

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"
MAN1=		tcpreen.1

DOC_FILES=	README

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Configure fails"
.endif

.if ${OSVERSION} < 500000
LIB_DEPENDS+=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt
.endif

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
