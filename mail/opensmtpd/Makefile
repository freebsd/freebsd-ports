PORTNAME=	opensmtpd
PORTVERSION=	7.3.0
PORTREVISION=	3
DISTVERSIONSUFFIX=	p2
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	https://www.opensmtpd.org/archives/

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Security- and simplicity-focused SMTP server from OpenBSD
WWW=		https://www.OpenSMTPD.org/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libevent.so:devel/libevent

OPTIONS_DEFINE=	MAILERCONF PAM TABLE_DB

OPTIONS_DEFAULT=	PAM TABLE_DB

MAILERCONF_DESC=	Activate OpenSMTPD in mailer.conf(5)
TABLE_DB_DESC=		Build table-db plugin (aliases)

USES=		cpe groff libtool localbase ssl
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

CPE_VENDOR=	openbsd

USE_RC_SUBR=	smtpd
SUB_FILES=	pkg-install pkg-deinstall pkg-message

CONFLICTS_INSTALL=	postfix sendmail opensmtpd-devel

USERS=		_smtpd _smtpq
GROUPS=		_smtpd _smtpq

OPTIONS_SUB=	yes

PAM_CONFIGURE_WITH=	auth-pam=smtpd
TABLE_DB_CONFIGURE_WITH=	table-db

CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc/mail/ \
			--with-libevent=${LOCALBASE} \
			--with-path-mbox=/var/mail \
			--with-user-smtpd=_smtpd \
			--with-user-queue=_smtpq \
			--with-group-queue=_smtpq

post-install-TABLE_DB-on:
	@${LN} -sf ${PREFIX}/sbin/smtpctl ${STAGEDIR}${PREFIX}/libexec/opensmtpd/makemap

.include <bsd.port.mk>
