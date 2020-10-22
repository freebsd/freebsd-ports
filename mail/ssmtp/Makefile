# Created by: Tomasz Paszkowski <ns88@k.pl>
# $FreeBSD$

PORTNAME=	ssmtp
PORTVERSION=	2.64
PORTREVISION=	7
CATEGORIES=	mail
MASTER_SITES=	DEBIAN_POOL
DISTFILES=	${PORTNAME}_${PORTVERSION}.orig${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extremely simple MTA to get mail off the system to a mail hub

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		gmake tar:bzip2
GNU_CONFIGURE=	yes

MAKE_ENV=	TARGET_ARCH=

SUB_FILES=	pkg-message

GROUPS=		ssmtp

OPTIONS_DEFINE=		CRAMMD5 IPV6 LOGFILE OPENSSL USERPREFS XORIGIP
OPTIONS_DEFAULT=	CRAMMD5 OPENSSL XORIGIP

CRAMMD5_DESC=	CRAM-MD5 authentication support
LOGFILE_DESC=	Log file
USERPREFS_DESC=	User-defined revaliases in ~/.ssmtprc
XORIGIP_DESC=	X-Originating-IP header for REMOTE_ADDR envvar

CRAMMD5_CONFIGURE_ENABLE=	md5auth
IPV6_CONFIGURE_ENABLE=		inet6
LOGFILE_CONFIGURE_ENABLE=	logfile
OPENSSL_USES=			ssl
OPENSSL_CONFIGURE_ENABLE=	ssl
OPENSSL_CFLAGS=			-I${OPENSSLINC}
OPENSSL_LIBS=			-L${OPENSSLLIB} -lcrypto
USERPREFS_CFLAGS=		-DUSERPREFS
XORIGIP_EXTRA_PATCHES=		${FILESDIR}/remote-addr.patch

_MAILERCONF=	/etc/mail/mailer.conf

post-configure:
	@${REINPLACE_CMD} "s|%%ETCDIR%%|${ETCDIR}|" \
		${WRKSRC}/ssmtp.8 \
		${WRKSRC}/ssmtp.c \
		${WRKSRC}/ssmtp.conf \
		${WRKSRC}/ssmtp.conf.5

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ssmtp ${STAGEDIR}${PREFIX}/sbin/ssmtp
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/revaliases \
		${STAGEDIR}${ETCDIR}/revaliases.sample
	${INSTALL_DATA} ${WRKSRC}/ssmtp.conf \
		${STAGEDIR}${ETCDIR}/ssmtp.conf.sample
	${INSTALL_MAN} ${WRKSRC}/ssmtp.8 ${STAGEDIR}${MAN8PREFIX}/share/man/man8
	${INSTALL_MAN} ${WRKSRC}/ssmtp.conf.5 \
		${STAGEDIR}${MAN5PREFIX}/share/man/man5

replace:
	@${REINPLACE_CMD} -e 's,^[^#],#&,g' ${_MAILERCONF}
	@${ECHO_CMD} "sendmail	${PREFIX}/sbin/ssmtp" >> ${_MAILERCONF}
	@${ECHO_CMD} "send-mail	${PREFIX}/sbin/ssmtp" >> ${_MAILERCONF}
	@${ECHO_CMD} "mailq		${PREFIX}/sbin/ssmtp" >> ${_MAILERCONF}
	@${ECHO_CMD} "newaliases	${PREFIX}/sbin/ssmtp" >> ${_MAILERCONF}
	@${ECHO_CMD} "hoststat	/usr/bin/true" >> ${_MAILERCONF}
	@${ECHO_CMD} "purgestat	/usr/bin/true" >> ${_MAILERCONF}

.include <bsd.port.mk>
