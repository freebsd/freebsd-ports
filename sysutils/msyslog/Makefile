# New ports collection makefile for:	msyslog
# Date created:				14 May 2001
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	msyslog
PORTVERSION=	1.04b
CATEGORIES=	sysutils
MASTER_SITES=	http://www.core-sdi.com/soft/
DISTNAME=	${PORTNAME}-v${PORTVERSION:S/b//}
EXTRACT_SUFX=	.tgz

MAINTAINER=	anders@fix.no

.if defined(WITH_MYSQL)
LIB_DEPENDS+=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
.endif
.if defined(WITH_PGSQL)
LIB_DEPENDS+=	pq.2:${PORTSDIR}/databases/postgresql7
.endif

USE_AUTOCONF=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
.if !defined(WITH_MYSQL)
CONFIGURE_ARGS+=	--without-mysql
.endif
.if !defined(WITH_PGSQL)
CONFIGURE_ARGS+=	--without-pgsql
.endif

MAN5=	syslog.conf.5
MAN8=	syslogd.8 im_bsd.8 im_unix.8 om_classic.8 om_tcp.8 im_tcp.8 om_peo.8 \
	peochk.8
.if defined(WITH_MYSQL)
MAN8+=	om_mysql.8
.endif
.if defined(WITH_PGSQL)
MAN8+=	om_pgsql.8
.endif
MANCOMPRESSED=	yes
INSTALLS_SHLIB=	yes

DOCDIR=	${PREFIX}/share/doc/${PORTNAME}
FIXPREFIX=	README src/man/om_peo.8 src/man/syslog.conf.5 \
		src/man/syslogd.8 src/TODO src/syslogd.h

pre-patch:
.for f in ${FIXPREFIX}
	${PERL} -pi -e "s|/etc/syslog.conf|${PREFIX}/etc/syslog.conf|g" \
	${WRKSRC}/${f}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0775 ${DOCDIR}/examples
	${INSTALL_DATA} ${WRKSRC}/src/examples/* ${DOCDIR}/examples/
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/src/TODO ${DOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/NEWS ${DOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/HOW_TO_WRITE_A_MODULE  ${DOCDIR}/
.endif
	@if [ ! -f ${PREFIX}/etc/rc.d/msyslog.sh.sample ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/msyslog.sh.sample startup file."; \
		${INSTALL_SCRIPT} ${FILESDIR}/msyslog.sh.sample ${PREFIX}/etc/rc.d/msyslog.sh.sample; \
	fi
	@${ECHO} "================================================================================"
	@${ECHO}
	@${ECHO} "To replace FreeBSD's standard syslogd, do this:"
	@${ECHO}
	@${ECHO} "a) create a configuration in ${PREFIX}/etc/syslog.conf."
.if !defined(NOPORTDOCS)
	@${ECHO} "   See ${DOCDIR}/examples for examples."
.endif
	@${ECHO}
	@${ECHO} "b) Set up a startup script in ${PREFIX}/etc/rc.d. For your convinience, a"
	@${ECHO} "   msyslog.sh.sample has been provided."
	@${ECHO}
	@${ECHO} "c) Stop the standard FreeBSD syslogd from starting automatically by putting this"
	@${ECHO} "   in the end of /etc/rc.conf:"
	@${ECHO}
	@${ECHO} "syslogd_enable=\"NO\""
	@${ECHO}
	@${ECHO} "================================================================================"

.include <bsd.port.mk>
