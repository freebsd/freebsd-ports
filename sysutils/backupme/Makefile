# New ports collection makefile for:	backupme
# Date created:				21 May 2010
# Whom:					Yaroslav Berezhinskiy <yaroslav@berezhinskiy.org.ua>
#
# $FreeBSD$
#

PORTNAME=	backupme
PORTVERSION=	0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://backupme.org.ua/

MAINTAINER=	yaroslav@berezhinskiy.org.ua
COMMENT=	Flexible and easy backup utility

RUN_DEPENDS=	${SITE_PERL}/Log/Log4perl.pm:${PORTSDIR}/devel/p5-Log-Log4perl \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/Mail/Sendmail.pm:${PORTSDIR}/mail/p5-Mail-Sendmail \
		${SITE_PERL}/mach/Filesys/Df.pm:${PORTSDIR}/sysutils/p5-Filesys-Df \
		${SITE_PERL}/Filesys/DiskUsage.pm:${PORTSDIR}/sysutils/p5-Filesys-DiskUsage \
		${SITE_PERL}/Net/FTP.pm:${PORTSDIR}/net/p5-Net \
		${SITE_PERL}/Net/SCP/Expect.pm:${PORTSDIR}/net/p5-Net-SCP-Expect \
		${SITE_PERL}/Net/IPv6Addr.pm:${PORTSDIR}/net-mgmt/p5-Net-IPv6Addr \
		${SITE_PERL}/Net/Jabber.pm:${PORTSDIR}/net-im/p5-Net-Jabber \
		${SITE_PERL}/Net/SSH.pm:${PORTSDIR}/net/p5-Net-SSH

USE_PERL5=	yes

NO_BUILD=	yes
NO_INSTALL_MANPAGES=	yes

PLIST_FILES=	bin/${PORTNAME} \
		etc/${PORTNAME}.sample.xml

do-install:
	@${CP} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@${CP} ${WRKSRC}/${PORTNAME}.sample.xml ${PREFIX}/etc/

post-install:
	@${ECHO_CMD} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} ""

.include <bsd.port.mk>
