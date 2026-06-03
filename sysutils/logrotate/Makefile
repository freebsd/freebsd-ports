PORTNAME=	logrotate
DISTVERSION=	3.22.0
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	js@iksz.hu
COMMENT=	Daemon to rotate, compress, remove, and mail system log files
WWW=		https://github.com/logrotate/logrotate/

LICENSE=	GPLv2

LIB_DEPENDS=	libpopt.so:devel/popt

USES=		cpe gmake localbase tar:xz
CPE_VENDOR=	logrotate_project
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-default-mail-command=/usr/bin/mailx \
		--with-compress-command=/usr/bin/gzip \
		--with-uncompress-command=/usr/bin/gunzip \
		--with-state-file-path=/var/run/logrotate.status
SUB_FILES=	logrotate.conf.sample

post-install:
	${INSTALL_DATA} ${WRKDIR}/logrotate.conf.sample \
		${STAGEDIR}${PREFIX}/etc/logrotate.conf.sample
	${MKDIR} ${STAGEDIR}${ETCDIR}.d \
		 ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/syslog.sample ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
