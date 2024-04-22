PORTNAME=	owrep
DISTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.ml1.org.uk/distfiles/ \
		http://www.ancientgeek.org.uk/distfiles/

MAINTAINER=	bob@eager.cx
COMMENT=	Weather reporting program using openweathermap.org
WWW=		https://www.bobeager.uk/software.html

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		localbase:ldflags zip

post-patch:
	@${REINPLACE_CMD} 's|/usr/local|${PREFIX}|' \
		${WRKSRC}/owrep.c ${WRKSRC}/owrep.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/owrep ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/owrep.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/owrep.conf.5 ${STAGEDIR}${PREFIX}/share/man/man5
	${INSTALL_DATA} ${WRKSRC}/owrep.conf.sample ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
