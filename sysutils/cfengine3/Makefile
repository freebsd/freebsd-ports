# New ports collection makefile for:	cfengine
# Date created:		March 16, 1998
# Whom:			jseger@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cfengine
PORTVERSION=	2.1.22
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.iu.hio.no/pub/cfengine/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	A systems administration tool for networks

USE_BDB=	44
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-docs
CONFIGURE_ENV+=	PTHREAD_CFLAGS=${PTHREAD_CFLAGS} PTHREAD_LIBS=${PTHREAD_LIBS} \
		BERKELEY_DB_CFLAGS=-I${BDB_INCLUDE_DIR} \
		BERKELEY_DB_LDFLAGS=-L${BDB_LIB_DIR} \
		BERKELEY_DB_LIB=-l${BDB_LIB_NAME}

.if !defined(NOPORTDOCS)
INFO=		cfengine-Anomalies cfengine-Reference cfengine-Tutorial
.endif

MAN8=		cfagent.8 cfengine.8 cfenvd.8 cfenvgraph.8 cfetoolcheck.8 \
		cfetoolcreate.8 cfetooldump.8 cfetoolgraph.8 cfetoolimport.8 \
		cfetoolinfo.8 cfetoolupdate.8 cfexecd.8 cfkey.8 \
		cfrun.8 cfservd.8 cfshow.8

post-patch:
		@${REINPLACE_CMD} -e s,-pthread,${PTHREAD_CFLAGS},g \
				  -e s,-lpthread,${PTHREAD_LIBS},g \
				  -e s,lpthread,${PTHREAD_LIBS},g \
				  ${WRKSRC}/configure

.include <bsd.port.mk>
