# New ports collection makefile for:	udmsearch
# Date created:		11/29/1999
# Whom:			Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

PORTNAME=	udmsearch
PORTVERSION=	3.0.23
PORTREVISION=	3
CATEGORIES=	www databases
MASTER_SITES=	http://search.mnogo.ru/Download/	\
		http://udmsearch.real-time.com/Download/	\
		http://www.ghks.de/computer/software/udmsearch/Download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full featured SQL-based hypertext search engine

MAN1=		indexer.1
MAN5=		indexer.conf.5

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-charset-guesser \
		--enable-freebsd-pthreads \
		--sysconfdir=${PREFIX}/etc/udmsearch \
		--localstatedir=/var/udmsearch

.if defined(WITH_PGSQL)
USE_PGSQL=		YES
CONFIGURE_ARGS+=	--with-pgsql=${LOCALBASE}/pgsql

.elif defined(WITH_MSQL)
BUILD_DEPENDS=		${PREFIX}/lib/libmsql.a:${PORTSDIR}/databases/msql
CONFIGURE_ARGS+=	--with-msql=${LOCALBASE}

.else
# default to mysql
USE_MYSQL=		YES
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}

pre-everything::
.if !defined(WITH_MYSQL)
	@${ECHO_MSG}
	@${ECHO_MSG} "Defaulting to udmsearch with mysql support."
	@${ECHO_MSG}
	@${ECHO_MSG} "You may alternately build udmsearch with either msql or"
	@${ECHO_MSG} "postgresql support by invoking make with WITH_MSQL=yes or"
	@${ECHO_MSG} "WITH_PGSQL=yes respectively."
	@${ECHO_MSG}
.endif

.endif

pre-install:
	@${MKDIR} ${PREFIX}/share/udmsearch

post-install:
	@cp -R ${WRKSRC}/create ${PREFIX}/share/udmsearch
	@${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/udmsearch
	@${STRIP_CMD} ${PREFIX}/sbin/indexer
	@${STRIP_CMD} ${PREFIX}/share/udmsearch/search.cgi
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
