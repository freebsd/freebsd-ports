# Created by: Tomasz Paszkowski <ns88@k.pl>
# $FreeBSD$

PORTNAME=	ssmtp
PORTVERSION=	2.64
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	DEBIAN_POOL
DISTFILES=	${PORTNAME}_${PORTVERSION}.orig${EXTRACT_SUFX}

MAINTAINER=	aragon@phat.za.net
COMMENT=	Extremely simple MTA to get mail off the system to a mail hub

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

GNU_CONFIGURE=	yes
USES=		gmake tar:bzip2
GROUPS=		ssmtp

SUB_FILES+=	pkg-message
MAKE_ENV+=	TARGET_ARCH=
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
MAILERCONF=	/etc/mail/mailer.conf

OPTIONS_DEFINE=	LOGFILE IPV6 USERPREFS XORIGIP CRAMMD5 OPENSSL
OPTIONS_DEFAULT=XORIGIP CRAMMD5 OPENSSL
LOGFILE_DESC=	Log file
USERPREFS_DESC=	User-defined revaliases
XORIGIP_DESC=	X-Originating-IP header for REMOTE_ADDR envvar
CRAMMD5_DESC=	CRAM-MD5 authentication support

LOGFILE_CONFIGURE_ON=	--enable-logfile
XORIGIP_EXTRA_PATCHES=	${FILESDIR}/remote-addr.patch
IPV6_CONFIGURE_ON=	--enable-inet6
CRAMMD5_CONFIGURE_ON=	--enable-md5auth
OPENSSL_CONFIGURE_ON=	--enable-ssl
OPENSSL_USES=		ssl

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MUSERPREFS}
CFLAGS+=	-DUSERPREFS
pre-everything::
	@${ECHO_CMD} "If you don't want to let your users set their own revalias address"
	@${ECHO_CMD} "(in ~/.ssmtprc), please define WITHOUT_USERPREFS."
.endif

post-configure:
	@${REINPLACE_CMD} -e "s,/etc/ssl/certs/ssmtp.pem,${PREFIX}/etc/ssmtp/ssmtp.pem,g" \
		${WRKSRC}/ssmtp.c ${WRKSRC}/ssmtp.conf
	@${REINPLACE_CMD} -e "s, /etc, ${PREFIX}/etc,g" ${WRKSRC}/ssmtp.8

replace:
	@${REINPLACE_CMD} -e 's,^[^#],#&,g' ${MAILERCONF}
	@${ECHO_CMD} "sendmail	${PREFIX}/sbin/ssmtp" >> ${MAILERCONF}
	@${ECHO_CMD} "send-mail	${PREFIX}/sbin/ssmtp" >> ${MAILERCONF}
	@${ECHO_CMD} "mailq		${PREFIX}/sbin/ssmtp" >> ${MAILERCONF}
	@${ECHO_CMD} "newaliases	${PREFIX}/sbin/ssmtp" >> ${MAILERCONF}
	@${ECHO_CMD} "hoststat	/usr/bin/true" >> ${MAILERCONF}
	@${ECHO_CMD} "purgestat	/usr/bin/true" >> ${MAILERCONF}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ssmtp ${STAGEDIR}${PREFIX}/sbin/ssmtp
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/ssmtp
	${INSTALL_DATA} ${WRKSRC}/revaliases \
		${STAGEDIR}${PREFIX}/etc/ssmtp/revaliases.sample
	${INSTALL_DATA} ${WRKSRC}/ssmtp.conf \
		${STAGEDIR}${PREFIX}/etc/ssmtp/ssmtp.conf.sample
	${INSTALL_MAN} ${WRKSRC}/ssmtp.8 ${STAGEDIR}${MANPREFIX}/man/man8/ssmtp.8
	${INSTALL_MAN} ${WRKSRC}/ssmtp.conf.5 \
		${STAGEDIR}${MANPREFIX}/man/man5/ssmtp.conf.5

.include <bsd.port.mk>
