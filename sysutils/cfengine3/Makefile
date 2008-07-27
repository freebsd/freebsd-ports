# New ports collection makefile for:	cfengine
# Date created:		March 16, 1998
# Whom:			jseger@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cfengine
PORTVERSION=	2.2.7
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cfengine.org/downloads/

MAINTAINER=	jrhett@netconsonance.com
COMMENT=	A systems administration tool for networks

USE_RC_SUBR=	cfexecd cfservd

WITH_BDB_VER?=	46
USE_BDB=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-docs \
		--docdir=${DOCSDIR} \
		--htmldir=${DOCSDIR}/html
CONFIGURE_ENV+=	PTHREAD_CFLAGS=${PTHREAD_CFLAGS} PTHREAD_LIBS=${PTHREAD_LIBS} \
		BERKELEY_DB_CFLAGS=-I${BDB_INCLUDE_DIR} \
		BERKELEY_DB_LDFLAGS=-L${BDB_LIB_DIR} \
		BERKELEY_DB_LIB=-l${BDB_LIB_NAME}

MAN8=		cfagent.8 cfengine.8 cfenvd.8 cfenvgraph.8 cfetoolcheck.8 \
		cfetoolcreate.8 cfetooldump.8 cfetoolgraph.8 cfetoolimport.8 \
		cfetoolinfo.8 cfetoolupdate.8 cfexecd.8 cfkey.8 \
		cfrun.8 cfservd.8 cfshow.8

post-patch:
		@${REINPLACE_CMD} -e s,-pthread,${PTHREAD_CFLAGS},g \
				  -e s,-lpthread,${PTHREAD_LIBS},g \
				  -e s,lpthread,${PTHREAD_LIBS},g \
				  ${WRKSRC}/configure
		@${REINPLACE_CMD} -e '/^docdir/s!=.*!= @docdir@!'\
				  ${WRKSRC}/doc/Makefile.in \
				  ${WRKSRC}/Makefile.in
		@${REINPLACE_CMD} -e '/^htmldir/s!=.*!= @htmldir@!'\
				  ${WRKSRC}/doc/Makefile.in \
				  ${WRKSRC}/Makefile.in
		@${REINPLACE_CMD} -e '/^pkgdatadir/s!=.*!= ${EXAMPLESDIR}!'\
				  ${WRKSRC}/inputs/Makefile.in \
				  ${WRKSRC}/contrib/Makefile.in

.include <bsd.port.mk>
