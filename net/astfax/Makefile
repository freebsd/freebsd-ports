# New ports collection makefile for:   astfax
# Date created:                 13 Aug 2005
# Whom:				Filippo Natali <filippo.natali@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	astfax
PORTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	http://www.inter7.com/astfax/

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	AstFax provides an outgoing email to fax gateway for Asterisk

LIB_DEPENDS=	spandsp.0:${PORTSDIR}/comms/spandsp
BUILD_DEPENDS=	${LOCALBASE}/lib/libeps.a:${PORTSDIR}/mail/eps
RUN_DEPENDS=	${LOCALBASE}/sbin/asterisk:${PORTSDIR}/net/asterisk

MAKE_JOBS_SAFE=  yes

PORTDOCS=	README testfax.eml testfax.tif

MAKE_ENV+=	DEFS="${CFLAGS}"

post-patch:
	@${REINPLACE_CMD} -e 's|^CC =|CC \?=|' \
			  -e 's|^DEFS =|DEFS \?=|' \
			  -e 's|\/usr\/include\/eps|${LOCALBASE}\/include\/eps|' \
			  -e 's|^LIBS=-leps|LIBS=-leps -L${LOCALBASE}\/lib|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|"\/tmp"|"\/var\/tmp"|' \
			  -e 's|"\./ast_fax.call"|"${DATADIR}\/ast_fax.call"|' \
		${WRKSRC}/ast_fax.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ast_fax ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ast_fax.call ${DATADIR}

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	for f in ${PORTDOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$${f} ${DOCSDIR}; \
	done
.endif

.include <bsd.port.mk>
