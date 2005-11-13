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

RUN_DEPENDS=	${LOCALBASE}/sbin/sendmail:${PORTSDIR}/mail/${SENDMAIL_MILTER_PORT}	\
		${JCODE}:${PORTSDIR}/japanese/p5-Jcode			\
		${SITE_PERL}/mach/Quota.pm:${PORTSDIR}/sysutils/p5-Quota		\
		${SITE_PERL}/mach/Locale/gettext.pm:${PORTSDIR}/devel/p5-Locale-gettext	\
		${SITE_PERL}/GD/Graph.pm:${PORTSDIR}/graphics/p5-GD-Graph		\
		${SITE_PERL}/Mail/SPF/Query.pm:${PORTSDIR}/mail/p5-Mail-SPF-Query	\
		logrotate:${PORTSDIR}/sysutils/logrotate	\
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

.if ${PERL_LEVEL} < 500801
JCODE=	${SITE_PERL}/${PERL_ARCH}/Jcode.pm
.else
JCODE=	${SITE_PERL}/Jcode.pm
.endif

.if !defined(SENDMAIL_MILTER_PORT)
SENDMAIL_MILTER_PORT?=	sendmail-sasl
.else
.if ${SENDMAIL_MILTER_PORT} != "sendmail-sasl"
pre-everything::
	@${ECHO_MSG} "SENDMAIL_MILTER_PORT=${SENDMAIL_MILTER_PORT}
	@${ECHO_MSG} "RAQdevil makes use of the sendmail-sasl metaport. Please set"
	@${ECHO_MSG} "SENDMAIL_MILTER_PORT=sendmail-sasl in /etc/make.conf"
	@${FALSE}
.endif
.endif

pre-extract:
.if !defined(PACKAGE_BUILDING)
	@${SH} ${FILESDIR}/warning
.endif

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
