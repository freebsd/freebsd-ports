# Created by: kris@FreeBSD.org
# $FreeBSD$

PORTNAME=	pks
PORTVERSION=	0.9.6.20040312
PORTREVISION=	7
CATEGORIES=	security www
MASTER_SITES=	http://pks.sourceforge.net/ LOCAL/mandree
DISTFILES=	pks-current.tgz

MAINTAINER=	tphilipp@potion-studios.com
COMMENT=	PGP Public Key Server

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_SSL=	openssl111
BROKEN_SSL_REASON_openssl111=	member access into incomplete type 'EVP_PKEY' (aka 'evp_pkey_st')

USES=		bdb ssl
USE_GCC=	any
USE_RC_SUBR=	pksd

WRKSRC=		${WRKDIR}/${PORTNAME}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${DATADIR} \
		--localstatedir=/var/pks \
		--with-libwrap \
		--with-openssl=${OPENSSLBASE}
MAKE_ENV+=	SUBDIRS=
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	DBLIB="-L${BDB_LIB_DIR} -l${BDB_LIB_NAME}" \
		DBINC=-I${BDB_INCLUDE_DIR} DBHDR=db.h

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS
PORTDOCS=	pks_help.* README EMAIL

post-extract:
	@${CP} -a ${FILESDIR}/EMAIL ${WRKSRC}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pgpsplit
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pksdctl
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pksclient
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/pksd
	${MV} ${STAGEDIR}${PREFIX}/etc/pksd.conf ${STAGEDIR}${PREFIX}/etc/pksd.conf.sample

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200085 && ${SSL_DEFAULT} == base
BROKEN=	Does not build with OpenSSL 1.1
.endif

.include <bsd.port.mk>
