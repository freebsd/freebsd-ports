# New ports collection makefile for:	msyslog
# Date created:				14 May 2001
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	msyslog
PORTVERSION=	1.08f
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.corest.com/download/msyslog/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/
DISTNAME=	${PORTNAME}-v${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flexible and easy to integrate syslog daemon

.if defined(WITH_MYSQL)
LIB_DEPENDS+=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
.endif
.if defined(WITH_PGSQL)
USE_PGSQL=	yes
.endif

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=	yes
.if !defined(WITH_MYSQL)
CONFIGURE_ARGS+=	--without-mysql
.endif
.if !defined(WITH_PGSQL)
CONFIGURE_ARGS+=	--without-pgsql
.endif
.if defined(WITH_DAEMON_NAME)
CONFIGURE_ARGS+=    --with-daemon-name=${WITH_DAEMON_NAME}
.endif

MAN5=	syslog.conf.5
MAN8=	im_bsd.8 im_tcp.8 im_udp.8 im_unix.8 om_classic.8 om_tcp.8 om_peo.8 \
	om_regex.8 peochk.8 syslogd.8 om_udp.8 im_file.8
.if defined(WITH_MYSQL)
MAN8+=	om_mysql.8
.endif
.if defined(WITH_PGSQL)
MAN8+=	om_pgsql.8
.endif
MANCOMPRESSED=	yes
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/alat

DOCS=	AUTHORS COPYING src/TODO README NEWS doc/HOW_TO_WRITE_A_MODULE \
	doc/HOW-TO-UPGRADE
FIXPREFIX=	README src/man/om_peo.8 src/man/syslog.conf.5 \
		src/man/syslogd.8 src/TODO src/syslogd.h

WRKSRC=		${WRKDIR}/${DISTNAME}

pre-patch:
.for f in ${FIXPREFIX}
	${REINPLACE_CMD} -e "s|/etc/syslog.conf|${PREFIX}/etc/syslog.conf|g" \
		${WRKSRC}/${f}
.endfor

post-patch:
.for f in README src/syslogd.c src/man/im_file.8 src/man/im_streams.8 \
	 src/man/im_unix.8 src/man/syslogd.8 src/modules/im_streams.c src/modules/im_unix.c
	${REINPLACE_CMD} -e "s|/dev/log|/var/run/log|" ${WRKSRC}/${f}
.endfor

post-install:
	${INSTALL} -d -o root -g wheel -m 0755 ${PREFIX}/share/examples/msyslog
	${INSTALL_DATA} ${WRKSRC}/src/examples/* \
		${PREFIX}/share/examples/msyslog
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@if [ ! -f ${PREFIX}/etc/rc.d/msyslog.sh.sample ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/msyslog.sh.sample startup file."; \
		${INSTALL_SCRIPT} ${FILESDIR}/msyslog.sh.sample ${PREFIX}/etc/rc.d/msyslog.sh.sample; \
	fi

.include <bsd.port.mk>
