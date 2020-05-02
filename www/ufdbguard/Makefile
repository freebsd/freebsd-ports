# Created by: Pavel Timofeev <timp87@gmail.com>
# $FreeBSD$

PORTNAME=	ufdbGuard
PORTVERSION=	1.34.5
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME:tl}/1.34

MAINTAINER=	timp87@gmail.com
COMMENT=	URL filter for the Squid web proxy

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5 shebangfix ssl

SHEBANG_FILES=	samples/URLblocked.cgi
GNU_CONFIGURE=	yes
USE_RC_SUBR=	ufdbguardd

USERS=		ufdb
GROUPS=		${USERS}

RUNDIR=		/var/run/${PORTNAME}
DBDIR=		/var/db/${PORTNAME}
LOGDIR=		/var/log/${PORTNAME}

PLIST_SUB=	USERS=${USERS} \
		GROUPS=${GROUPS} \
		RUNDIR=${RUNDIR} \
		DBDIR=${DBDIR} \
		LOGDIR=${LOGDIR}

SUB_LIST=	PORTNAME=${PORTNAME} \
		USERS=${USERS} \
		RUNDIR=${RUNDIR} \
		DBDIR=${DBDIR}

SUB_FILES=	pkg-message

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

OPTIONS_DEFINE=	UNIXSOCKETS EXAMPLES

UNIXSOCKETS_CONFIGURE_WITH=	unix-sockets

UNIXSOCKETS_DESC=	Unix sockets support

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ufdbguardd \
		${STAGEDIR}${PREFIX}/bin/ufdbgclient \
		${STAGEDIR}${PREFIX}/bin/ufdbsignal \
		${STAGEDIR}${PREFIX}/bin/ufdbGenTable \
		${STAGEDIR}${PREFIX}/bin/ufdbAnalyse \
		${STAGEDIR}${PREFIX}/bin/ufdbhttpd

.include <bsd.port.mk>
