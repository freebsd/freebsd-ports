# $FreeBSD$

PORTNAME=	igor
PORTVERSION=	1.589
CATEGORIES=	textproc
MASTER_SITES=	http://docscripts.glenbarber.us/tags/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	wblock@FreeBSD.org
COMMENT=	FreeBSD Documentation Project sanity check script

LICENSE=	BSD2CLAUSE

USES=		perl5
USE_PERL5=	run

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

post-patch:
	@${REINPLACE_CMD} 's|/usr/local|${PREFIX}|' ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
