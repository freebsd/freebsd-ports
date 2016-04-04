# Created by: Yuan-Chen Cheng <ycheng@sinica.edu.tw>
# $FreeBSD$

PORTNAME=	logrotate
PORTVERSION=	3.9.2
CATEGORIES=	sysutils

MAINTAINER=	js@iksz.hu
COMMENT=	Daemon to rotate, compress, remove, and mail system log files

LICENSE=	GPLv2

LIB_DEPENDS=	libpopt.so:devel/popt

USE_GITHUB=	yes

PATCH_STRIP=		-p1
USES=		gmake autoreconf
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CPPFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib

post-install:
	@${SED} -e 's|__PREFIX__|${PREFIX}|' \
		< ${FILESDIR}/logrotate.conf.sample > ${STAGEDIR}${PREFIX}/etc/logrotate.conf.sample
	@${MKDIR} ${STAGEDIR}${ETCDIR}.d
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/syslog.sample ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
