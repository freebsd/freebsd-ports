PORTNAME=	destroy
PORTVERSION=	20130926
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.mod6.net/destroy/ \
		http://www.kinneysoft.com/destroy/

MAINTAINER=	modsix@gmail.com
COMMENT=	Securely destroy files on the hard disk
WWW=		http://www.mod6.net

LICENSE=	BSD4CLAUSE

PLIST_FILES=	bin/destroy share/man/man1/destroy.1.gz

do-build:
	(cd ${WRKSRC} ; ${CC} ${CFLAGS} ${LDFLAGS} -o ${PORTNAME} destroy.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/destroy ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/destroy.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
