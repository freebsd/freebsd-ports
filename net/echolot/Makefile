# ex:ts=8
# Ports collection makefile for:	echolot
# Date created:			Jun 23, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	echolot
PORTVERSION=	0.1.0
CATEGORIES=	net
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITES=	http://echolot.sourceforge.net/download/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnugetopt:${PORTSDIR}/devel/libgnugetopt

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"
USE_GMAKE=	yes

MAN1=	echolot.1

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
