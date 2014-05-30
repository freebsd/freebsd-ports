# Created by: jseger@FreeBSD.org
# $FreeBSD$

PORTNAME=	cfengine
PORTVERSION=	2.2.10
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://cfengine.com/source-code/download?file= \
		https://s3.amazonaws.com/cfengine.package-repos/tarballs/
PKGNAMESUFFIX=	22

MAINTAINER=	cy@FreeBSD.org
#		gjb@FreeBSD.org is also committer for this port
COMMENT=	A systems administration tool for networks

FETCH_BEFORE_ARGS=	-o ${DISTDIR}/${DISTFILES}

CONFLICTS=	cfengine-3* cfengine-devel-*

USE_RC_SUBR=	cfexecd cfservd

USES=		libtool shebangfix
SHEBANG_FILES=	contrib/cfdoc

WITH_BDB_VER?=	46
USE_BDB=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-docs \
		--docdir=${DOCSDIR} \
		--htmldir=${DOCSDIR}/html
CONFIGURE_ENV+=	BERKELEY_DB_CFLAGS=-I${BDB_INCLUDE_DIR} \
		BERKELEY_DB_LDFLAGS=-L${BDB_LIB_DIR} \
		BERKELEY_DB_LIB=-l${BDB_LIB_NAME}

INFO=		cfengine-Tutorial cfengine-Reference

post-patch:
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
