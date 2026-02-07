PORTNAME=	kldfind
PORTVERSION=	0.61
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ricardo.areis@gmail.com
COMMENT=	Find kernel modules by string
WWW=		https://sourceforge.net/projects/kldfind/

NO_BUILD=	yes
USES=	tar:bzip2

PLIST_FILES=	sbin/kldfind share/man/man8/kldfind.8.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}-${PORTVERSION} \
		${STAGEDIR}${PREFIX}/sbin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
