# $FreeBSD$

PORTNAME=	igor
PORTVERSION=	1.397
CATEGORIES=	textproc
MASTER_SITES=	https://docscripts.glenbarber.us/tags/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	wblock@FreeBSD.org
COMMENT=	FreeBSD Documentation Project sanity check script

LICENSE=	BSD

USES=		perl5
USE_PERL5=	run

NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

post-patch:
	@${REINPLACE_CMD} 's|/usr/local|${PREFIX}|' ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
