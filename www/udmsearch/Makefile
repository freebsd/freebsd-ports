# Created by: Kelly Yancey <kbyanc@posi.net>
# $FreeBSD$

PORTNAME=	udmsearch
PORTVERSION=	3.1.7
CATEGORIES=	www databases
MASTER_SITES=	http://www.mnogosearch.org/Download/ \
		http://udmsearch.real-time.com/Download/

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Full featured SQL-based hypertext search engine

OPTIONS_DEFINE=		MSQL MYSQL PGSQL
OPTIONS_DEFAULT=	MYSQL

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-charset-guesser \
		--enable-freebsd-pthreads \
		--sysconfdir=${PREFIX}/etc/udmsearch \
		--localstatedir=/var/udmsearch

MAN1=		indexer.1
MAN5=		indexer.conf.5

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMSQL}
BUILD_DEPENDS=		${PREFIX}/lib/libmsql.a:${PORTSDIR}/databases/msql
CONFIGURE_ARGS+=	--with-msql=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=		YES
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=		YES
CONFIGURE_ARGS+=	--with-pgsql=${LOCALBASE}/pgsql
.endif

pre-install:
	@${MKDIR} ${DATADIR}

post-install:
	@${CP} -R ${WRKSRC}/create ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCSDIR}
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
