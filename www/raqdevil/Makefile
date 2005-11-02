# New ports collection makefile for:    raqdevil
# Date created:         06 September 2005
# Whom:                 Devon H. O'Dell <dodell@offmyserver.com>
#
# $FreeBSD$
#

PORTNAME=	raqdevil
PORTVERSION=	0.9.6
CATEGORIES=	www sysutils
MASTER_SITES=	http://www.raqdevil.com/

MAINTAINER=	dodell@offmyserver.com
COMMENT=	A port of the Sun Cobalt RaQ550 software to FreeBSD

RUN_DEPENDS=	${LOCALBASE}/sbin/sendmail:${PORTSDIR}/mail/sendmail-sasl		\
		${SITE_PERL}/Jcode.pm:${PORTSDIR}/japanese/p5-Jcode			\
		${SITE_PERL}/mach/Quota.pm:${PORTSDIR}/sysutils/p5-Quota		\
		${SITE_PERL}/mach/Locale/gettext.pm:${PORTSDIR}/devel/p5-Locale-gettext	\
		${SITE_PERL}/GD/Graph.pm:${PORTSDIR}/graphics/p5-GD-Graph		\
		${SITE_PERL}/Mail/SPF/Query.pm:${PORTSDIR}/mail/p5-Mail-SPF-Query	\
		logrotate:${PORTSDIR}/sysutils/logrotate	\
		httpd:${PORTSDIR}/www/apache20			\
		perl:${PORTSDIR}/lang/perl5.8			\
		imapd:${PORTSDIR}/mail/imap-uw			\
		pcretest:${PORTSDIR}/devel/pcre			\
		snmpd:${PORTSDIR}/net-mgmt/net-snmp		\
		proftpd:${PORTSDIR}/ftp/proftpd			\
		qpopauth:${PORTSDIR}/mail/qpopper		\
		xinetd:${PORTSDIR}/security/xinetd		\
		spamc:${PORTSDIR}/mail/p5-Mail-SpamAssassin	\
		procmail:${PORTSDIR}/mail/procmail		\
		clamscan:${PORTSDIR}/security/clamav		\
		analog:${PORTSDIR}/www/analog
BUILD_DEPENDS=	re2c:${PORTSDIR}/devel/re2c

USE_GNOME=	glib20
USE_PHP=	pcre session xml
USE_GMAKE=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes
USE_APACHE=	yes

WITH_APACHE2=	yes
REINPLACE_ARGS=	-i""
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	${PREFIX}/raqdevil/lib

.include <bsd.port.pre.mk>

pre-extract:
	@${SH} ${FILESDIR}/warning

pre-configure:
	@if [ -n "`${PKG_INFO} -xI '^sendmail+tls+sasl*' 2> /dev/null`" ]; then \
		${ECHO_CMD} "${PKGNAME}: sendmail with sasl support is required for RAQdevil to properly function."; \
		${ECHO_CMD} "Please install mail/sendmail-sasl." \
		${FALSE}; \
	fi

post-extract:
.if !defined(PACKAGE_BUILDING)
	${CC} -o ${WRKSRC}/rdqchk ${FILESDIR}/rdqchk.c
	${WRKSRC}/rdqchk
.endif

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e \
		's|[(]prefix[)]|${PREFIX}|g' ;
	@${FIND} ${WRKSRC} -type f -name \*-e | ${XARGS} ${RM} -f

post-install:
	@PKG_PREFIX=${PREFIX} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
