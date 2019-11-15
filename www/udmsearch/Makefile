# Created by: Kelly Yancey <kbyanc@posi.net>
# $FreeBSD$

PORTNAME=	udmsearch
PORTVERSION=	3.1.7
PORTREVISION=	2
CATEGORIES=	www databases
MASTER_SITES=	http://www.mnogosearch.org/Download/ \
		http://udmsearch.real-time.com/Download/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Full featured SQL-based hypertext search engine

BROKEN=		unfetchable

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-charset-guesser \
		--enable-freebsd-pthreads \
		--sysconfdir=${PREFIX}/etc/udmsearch \
		--localstatedir=/var/udmsearch
USES=		libtool

OPTIONS_DEFINE=		MYSQL PGSQL DOCS
OPTIONS_DEFAULT=	MYSQL

MYSQL_USES=	mysql
MYSQL_CONFIGURE_ON+=	--with-mysql=${LOCALBASE}
PGSQL_USES=	pgsql
PGSQL_CONFIGURE_ON+=	--with-pgsql=${LOCALBASE}/pgsql

PORTDOCS=	*

SUB_FILES=	pkg-message

pre-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}

post-install:
	@${CP} -R ${WRKSRC}/create ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${STAGEDIR}${DOCSDIR}
	${CP} ${WRKSRC}/doc/*.txt ${STAGEDIR}${DOCSDIR}
	${CP} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
