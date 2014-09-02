# Created by: Kelly Yancey <kbyanc@posi.net>
# $FreeBSD$

PORTNAME=	udmsearch
PORTVERSION=	3.1.7
PORTREVISION=	2
CATEGORIES=	www databases
MASTER_SITES=	http://www.mnogosearch.org/Download/ \
		http://udmsearch.real-time.com/Download/

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Full featured SQL-based hypertext search engine

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-charset-guesser \
		--enable-freebsd-pthreads \
		--sysconfdir=${PREFIX}/etc/udmsearch \
		--localstatedir=/var/udmsearch
USES=		libtool

OPTIONS_DEFINE=		MSQL MYSQL PGSQL DOCS
OPTIONS_DEFAULT=	MYSQL

MSQL_BUILD_DEPENDS=	${LOCALBASE}/lib/libmsql.a:${PORTSDIR}/databases/msql
MSQL_CONFIGURE_ON+=	--with-msql=${LOCALBASE}
MYSQL_USE=	MYSQL=YES
MYSQL_CONFIGURE_ON+=	--with-mysql=${LOCALBASE}
PGSQL_USE=	PGSQL=YES
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
