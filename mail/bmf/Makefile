PORTNAME=	bmf
PORTVERSION=	0.9.4
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast Bayesian Mail Filter compatible with maildrop and procmail
WWW=		https://sourceforge.net/projects/bmf/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		mysql

HAS_CONFIGURE=	yes

BINARY_ALIAS=	gcc=${CC} g++=${CXX}

CFLAGS+=	-I${LOCALBASE}/include/mysql
LDFLAGS+=	-L${LOCALBASE}/lib/mysql

CONFIGURE_ARGS=	--with-mysql --without-libdb

OPTIONS_DEFINE=	DEBUG DOCS MANPAGES
OPTIONS_DEFAULT=MANPAGES
OPTIONS_SUB=	yes

DEBUG_CONFIGURE_ON=	--debug=yes

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} bmf bmfconv ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

do-install-MANPAGES-on:
	cd ${WRKSRC} && ${INSTALL_MAN} bmf.1 bmfconv.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
