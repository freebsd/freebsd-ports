# ex:ts=8
# Ports collection makefile for:	echolot
# Date created:			Jun 23, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	echolot
PORTVERSION=	0.0.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnugetopt:${PORTSDIR}/devel/libgnugetopt

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"

MAN1=	echolot.1

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for file in DESIGN SCRIPTING SYNTAX
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
