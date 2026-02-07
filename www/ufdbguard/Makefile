PORTNAME=	ufdbGuard
DISTVERSION=	1.35.8
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME:tl}/1.35

MAINTAINER=	timp87@gmail.com
COMMENT=	URL filter for the Squid web proxy
WWW=		https://www.urlfilterdb.com/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 perl5 shebangfix ssl
USE_RC_SUBR=	ufdbguardd

SHEBANG_FILES=	samples/URLblocked.cgi
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-bz2-inc=/usr/include \
		--with-bz2-lib=/usr/lib \
		--with-bz2=/usr \
		--with-ssl-inc=${OPENSSLINC} \
		--with-ssl-lib=${OPENSSLLIB} \
		--with-ssl=${OPENSSLBASE} \
		--with-ufdb-config=${ETCDIR} \
		--with-ufdb-dbhome=${DBDIR} \
		--with-ufdb-imagesdir=${EXAMPLESDIR}/images \
		--with-ufdb-logdir=${LOGDIR} \
		--with-ufdb-mandir=${PREFIX}/share/man \
		--with-ufdb-piddir=${RUNDIR} \
		--with-ufdb-samplesdir=${EXAMPLESDIR} \
		--with-ufdb-user=root

MAKE_JOBS_UNSAFE=	yes

SUB_FILES=	pkg-message

SUB_LIST=	DBDIR=${DBDIR} \
		PORTNAME=${PORTNAME} \
		RUNDIR=${RUNDIR} \
		USERS=${USERS}

USERS=		ufdb
GROUPS=		${USERS}

PLIST_SUB=	DBDIR=${DBDIR} \
		GROUPS=${GROUPS} \
		LOGDIR=${LOGDIR} \
		RUNDIR=${RUNDIR} \
		USERS=${USERS}

OPTIONS_DEFINE=	EXAMPLES

DBDIR=		/var/db/${PORTNAME}
LOGDIR=		/var/log/${PORTNAME}
RUNDIR=		/var/run/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ufdbguardd \
		${STAGEDIR}${PREFIX}/bin/ufdbgclient \
		${STAGEDIR}${PREFIX}/bin/ufdbsignal \
		${STAGEDIR}${PREFIX}/bin/ufdbGenTable \
		${STAGEDIR}${PREFIX}/bin/ufdbAnalyse \
		${STAGEDIR}${PREFIX}/bin/ufdbhttpd

.include <bsd.port.mk>
