# New ports collection makefile for:    raqdevil
# Date created:         06 September 2005
# Whom:                 Devon H. O'Dell <dodell@ixsystems.com>
#
# $FreeBSD$
#

PORTNAME=	raqdevil
PORTVERSION=	1.0
CATEGORIES=	www sysutils
MASTER_SITES=	http://www.raqdevil.com/

MAINTAINER=	dodell@iXsystems.com
COMMENT=	A port of the Sun Cobalt RaQ550 software to FreeBSD

# The explicit dependencies on p5-Net, p5-Digest, p5-Authen-SASL,
# p5-Test-Harness, p5-Test-Simple, p5-Authen-SASL and p5-MIME-Base64
# are necessary due to ports/86310. This is a work-around: RAQdevil
# does not depend on these ports itself.

RUN_DEPENDS=	${LOCALBASE}/sbin/sendmail:${PORTSDIR}/mail/${SENDMAIL_MILTER_PORT}	\
		${SITE_PERL}/Authen/SASL.pm:${PORTSDIR}/security/p5-Authen-SASL		\
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/Digest.pm:${PORTSDIR}/security/p5-Digest			\
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/Net/Cmd.pm:${PORTSDIR}/net/p5-Net				\
		${SITE_PERL}/Test/Harness.pm:${PORTSDIR}/devel/p5-Test-Harness		\
		${SITE_PERL}/Test/Simple.pm:${PORTSDIR}/devel/p5-Test-Simple		\
		${LOCALBASE}/libexec/imapd:${PORTSDIR}/mail/imap-uw			\
		${SITE_PERL}/Jcode.pm:${PORTSDIR}/japanese/p5-Jcode			\
		${SITE_PERL}/${PERL_ARCH}/Quota.pm:${PORTSDIR}/sysutils/p5-Quota		\
		${SITE_PERL}/${PERL_ARCH}/Locale/gettext.pm:${PORTSDIR}/devel/p5-Locale-gettext	\
		${SITE_PERL}/GD/Graph.pm:${PORTSDIR}/graphics/p5-GD-Graph		\
		${SITE_PERL}/Mail/SPF/Query.pm:${PORTSDIR}/mail/p5-Mail-SPF-Query	\
		${JCODE}:${PORTSDIR}/japanese/p5-Jcode		\
		expect:${PORTSDIR}/lang/expect			\
		logrotate:${PORTSDIR}/sysutils/logrotate	\
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

NO_PACKAGE=	Conflicting dependencies (apache 1.x vs 2.x)

USE_GNOME=	glib20
USE_PHP=	pcre session xml
USE_GMAKE=	yes
USE_PERL5=	yes
USE_APACHE=	yes

WITHOUT_X11=	yes
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
.if !defined(BATCH)
	@${SH} ${FILESDIR}/warning
.endif

post-extract:
.if !defined(BATCH)
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
