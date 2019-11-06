# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vee
DISTVERSION=	0.9.9-zeta
CATEGORIES=	www
MASTER_SITES=	http://www.0x743.com/vee/
# Also here: http://code.google.com/p/vee/
EXTRACT_SUFX=	.tgz

MAINTAINER=	estrabd@gmail.com
COMMENT=	Tiny CLI blogging tool

BROKEN=		unfetchable

NO_BUILD=	yes
PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -Ee 's|^function ([[:graph:]]+)|\1 ()|' \
		${WRKSRC}/bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
