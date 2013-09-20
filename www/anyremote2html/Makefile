# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	anyremote2html
PORTVERSION=	1.4
CATEGORIES=	www deskutils
MASTER_SITES=	SF/anyremote/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A web interface for anyRemote

RUN_DEPENDS=	anyremote:${PORTSDIR}/comms/anyremote

GNU_CONFIGURE=	yes
USE_PYTHON_RUN=	yes

PORTDOCS=	ChangeLog README COPYING AUTHORS

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' ${WRKSRC}/${PORTNAME}
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/doc\/${PORTNAME}/d' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
