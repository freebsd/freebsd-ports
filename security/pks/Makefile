PORTNAME=	pks
PORTVERSION=	0.9.6.20040312
PORTREVISION=	12
CATEGORIES=	security www
MASTER_SITES=	http://pks.sourceforge.net/ LOCAL/mandree
DISTFILES=	pks-current.tgz

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	PGP Public Key Server
WWW=		http://www.mit.edu/people/marc/pks/

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		bdb:18 ssl
USE_RC_SUBR=	pksd

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${DATADIR} \
		--localstatedir=/var/pks \
		--with-db --with-ipv6 --with-libwrap \
		--with-openssl=${OPENSSLBASE}
CONFIGURE_ENV=	DBLIB="-L${BDB_LIB_DIR} -l${BDB_LIB_NAME}" \
		DBINC=-I${BDB_INCLUDE_DIR} DBHDR=db.h cflags="${CFLAGS}"

SUB_FILES=	pkg-message
SUB_LIST=	PORTNAME="${PORTNAME}"

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	pks_help.* README EMAIL

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-extract:
	@${CP} -a ${FILESDIR}/EMAIL ${WRKSRC}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pgpsplit \
	${STAGEDIR}${PREFIX}/bin/pksdctl \
	${STAGEDIR}${PREFIX}/bin/pksclient \
	${STAGEDIR}${PREFIX}/sbin/pksd
	${MV} ${STAGEDIR}${PREFIX}/etc/pksd.conf ${STAGEDIR}${PREFIX}/etc/pksd.conf.sample

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
