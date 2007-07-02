# New ports collection makefile for:	udmsearch
# Date created:		11/29/1999
# Whom:			Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

PORTNAME=	udmsearch
PORTVERSION=	3.1.5
CATEGORIES=	www databases
MASTER_SITES=	http://search.mnogo.ru/Download/ \
		http://udmsearch.real-time.com/Download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full featured SQL-based hypertext search engine

OPTIONS=	MSQL "MSQL support" off \
		MYSQL "MYSQL support" on \
		PGSQL "PGSQL support" off

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-charset-guesser \
		--enable-freebsd-pthreads \
		--sysconfdir=${PREFIX}/etc/udmsearch \
		--localstatedir=/var/udmsearch

MAN1=		indexer.1
MAN5=		indexer.conf.5

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Does not compile with GCC 4.2
.endif

.if defined(WITH_MSQL)
BUILD_DEPENDS=		${PREFIX}/lib/libmsql.a:${PORTSDIR}/databases/msql
CONFIGURE_ARGS+=	--with-msql=${LOCALBASE}
.endif

.if !defined(WITHOUT_MYSQL)
USE_MYSQL=		YES
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
.endif

.if defined(WITH_PGSQL)
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

.include <bsd.port.post.mk>
