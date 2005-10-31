# New ports collection makefile for:    raqdevil
# Date created:         06 September 2005
# Whom:                 Devon H. O'Dell <dodell@offmyserver.com>
#
# $FreeBSD$
#

PORTNAME=	raqdevil
PORTVERSION=	0.9.4
CATEGORIES=	www sysutils
MASTER_SITES=	http://raqdevil.alkeninternet.com/ \
		http://www.sitetronics.com/

MAINTAINER=	dodell@offmyserver.com
COMMENT=	A port of the Sun Cobalt RaQ550 software to FreeBSD

RUN_DEPENDS=	\
		${LOCALBASE}/libexec/imapd:${PORTSDIR}/mail/imap-uw	\
		${LOCALBASE}/libexec/qpopper:${PORTSDIR}/mail/qpopper	\
		${SITE_PERL}/${PERL_ARCH}/Locale/gettext.pm:${PORTSDIR}/devel/p5-Locale-gettext	\
		${SITE_PERL}/${PERL_ARCH}/Quota.pm:${PORTSDIR}/sysutils/p5-Quota		\
		${SITE_PERL}/Jcode.pm:${PORTSDIR}/japanese/p5-Jcode	\
		analog:${PORTSDIR}/www/analog				\
		clamscan:${PORTSDIR}/security/clamav			\
		logrotate:${PORTSDIR}/sysutils/logrotate		\
		pcretest:${PORTSDIR}/devel/pcre				\
		procmail:${PORTSDIR}/mail/procmail			\
		proftpd:${PORTSDIR}/ftp/proftpd				\
		sendmail:${PORTSDIR}/mail/sendmail-sasl			\
		snmpd:${PORTSDIR}/net-mgmt/net-snmp			\
		spamc:${PORTSDIR}/mail/p5-Mail-SpamAssassin		\
		xinetd:${PORTSDIR}/security/xinetd
BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison				\
	        re2c:${PORTSDIR}/devel/re2c

USE_GNOME=	glib20
USE_PHP=	xml pcre
USE_GMAKE=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes
REINPLACE_ARGS=	-i""
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	${PREFIX}/raqdevil/lib

.include <bsd.port.pre.mk>

.ifdef (WITH_APACHE)
WITH_APACHE2=		yes
.endif

.ifndef (WITH_APACHE2)
BROKEN?=	"This port requires Apache 2. Use make -DWITH_APACHE."
.endif

pre-extract:
	@${SH} ${FILESDIR}/warning

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
	@${SETENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
