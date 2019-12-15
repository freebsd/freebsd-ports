# Created by: Zane C. Bowers
# $FreeBSD$

PORTNAME=	shell-include
PORTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	shells devel
MASTER_SITES=	http://vvelox.net/src/shell-include/

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Include system for shell scripts

BROKEN=		unfetchable

USES=		perl5 tar:tgz
USE_PERL5=	build
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/bin/pod2man|${LOCALBASE}/bin/pod2man|' \
		${WRKSRC}/install

do-install:
	cd ${WRKSRC}/ ; ${SETENV} DESTDIR=${STAGEDIR} \
		${SH} ${WRKSRC}/install ${PREFIX}

.include <bsd.port.mk>
