# Created by: Pavel Timofeev <timp87@gmail.com>
# $FreeBSD$

PORTNAME=	ufdbGuard
PORTVERSION=	1.35.3
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME:tl}/1.35

MAINTAINER=	timp87@gmail.com
COMMENT=	URL filter for the Squid web proxy

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 perl5 shebangfix ssl
USE_RC_SUBR=	ufdbguardd

SHEBANG_FILES=	samples/URLblocked.cgi
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-ssl=${OPENSSLBASE} \
		--with-ssl-lib=${OPENSSLLIB} \
		--with-ssl-inc=${OPENSSLINC} \
		--with-bz2=/usr \
		--with-bz2-lib=/usr/lib \
		--with-bz2-inc=/usr/include \
		--with-ufdb-user=root \
		--with-ufdb-mandir=${MANPREFIX}/man \
		--with-ufdb-logdir=${LOGDIR} \
		--with-ufdb-piddir=${RUNDIR} \
		--with-ufdb-samplesdir=${EXAMPLESDIR} \
		--with-ufdb-config=${ETCDIR} \
		--with-ufdb-dbhome=${DBDIR} \
		--with-ufdb-imagesdir=${EXAMPLESDIR}/images

MAKE_JOBS_UNSAFE=	yes

SUB_FILES=	pkg-message

SUB_LIST=	PORTNAME=${PORTNAME} \
		USERS=${USERS} \
		RUNDIR=${RUNDIR} \
		DBDIR=${DBDIR}

USERS=		ufdb
GROUPS=		${USERS}

PLIST_SUB=	USERS=${USERS} \
		GROUPS=${GROUPS} \
		RUNDIR=${RUNDIR} \
		DBDIR=${DBDIR} \
		LOGDIR=${LOGDIR}

OPTIONS_DEFINE=	UNIXSOCKETS EXAMPLES

UNIXSOCKETS_DESC=	Unix sockets support
UNIXSOCKETS_CONFIGURE_WITH=	unix-sockets

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
