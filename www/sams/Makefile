# Created by: dindin
# $FreeBSD$

PORTNAME=	sams
DISTVERSION=	1.0.5
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	http://sams.perm.ru/download/ \
		http://gateway11.ath.cx/sams/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Squid 2.x Accounting Management System

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

SAMBA_PORT?=	net/samba36

USE_RC_SUBR=	sams

OPTIONS_DEFINE=	APACHE NTLM GD
OPTIONS_DEFAULT=GD

INSTALLGD_DESC=	Graphic reports

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE=	22+
.endif

USES=		gmake tar:bzip2
GNU_CONFIGURE=	yes
USE_PHP=	ctype curl gettext hash iconv json mysql \
		pcre pdo pdo_sqlite posix session \
		simplexml spl sqlite tokenizer \
		xmlwriter zlib xmlreader
DEFAULT_PHP_VER=53
IGNORE_WITH_PHP=5
MANUAL_PACKAGE_BUILD=	it needs an old PHP version

USE_MYSQL=	5.0

CONFIGURE_ARGS=	--with-configfile=${PREFIX}/etc/sams.conf \
		--with-rcd-locations=${PREFIX}/etc/rc.d/

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MNTLM}
RUN_DEPENDS=	${LOCALBASE}/bin/ntlm_auth:${PORTSDIR}/${SAMBA_PORT}
USE_PHP+=	ldap
.endif

.if ${PORT_OPTIONS:MGD}
USE_PHP+=	pdf gd
.endif

post-extract:
	${INSTALL_SCRIPT} ${FILESDIR}/setup.sh ${WRKSRC}/

post-install:
	@${CAT} ${PKGMESSAGE}

setup:
	@cd ${WRKSRC}; ${WRKSRC}/setup.sh

.include <bsd.port.post.mk>
