# New ports collection makefile for:	anyremote2html
# Date created:				26 December 2008
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	anyremote2html
PORTVERSION=	1.0
CATEGORIES=	www deskutils
MASTER_SITES=	SF/anyremote/${PORTNAME}/${PORTVERSION}

MAINTAINER=	avl@FreeBSD.org
COMMENT=	A web interface for anyRemote

RUN_DEPENDS=	anyremote:${PORTSDIR}/comms/anyremote

GNU_CONFIGURE=	yes
USE_PYTHON_RUN=	yes

PORTDOCS=	ChangeLog README COPYING AUTHORS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' ${WRKSRC}/${PORTNAME}
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/doc\/${PORTNAME}/d' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
