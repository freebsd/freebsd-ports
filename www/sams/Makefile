# New ports collection makefile for:  sams
# Date created:		12 December 2006
# Whom:			dindin
#
# $FreeBSD$
#

PORTNAME=	sams
DISTVERSION=	1.0.4
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	http://sams.perm.ru/download/ \
		http://grishin.000webhost.info/sams/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	uzgrishin@mail.ru
COMMENT=	Squid 2.x Accounting Management System

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

USE_RC_SUBR=	sams.sh

OPTIONS=	NTLM	"NTLM autorization/ActiveDirectory support"	off \
		APACHE22	"Use apache version 2.2"	on \
		INSTALLGD 	"Graphic reports"		on

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_PHP=	ctype curl gettext hash iconv json mysql \
		pcre pdf pdo pdo_sqlite posix session \
		session simplexml spl sqlite tokenizer  \
		xmlreader xmlwriter zlib

USE_MYSQL=	5.0

CONFIGURE_ARGS=	--with-configfile=${PREFIX}/etc/sams.conf \
		--with-rcd-locations=${PREFIX}/etc/rc.d/

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if defined(WITH_NTLM)
RUN_DEPENDS=	${LOCALBASE}/bin/ntlm_auth:${PORTSDIR}/net/samba3
USE_PHP+=	ldap
.endif

.if defined(WITH_APACHE22)
RUN_DEPENDS+=	${LOCALBASE}/sbin/httpd:${PORTSDIR}/www/apache22
.else
RUN_DEPENDS+=	${LOCALBASE}/sbin/httpd:${PORTSDIR}/www/apache13
.endif

.if defined(WITH_INSTALLGD)
USE_PHP+=	gd
.endif

post-extract:
	${INSTALL_SCRIPT} ${FILESDIR}/setup.sh ${WRKSRC}/

post-install:
	@cp ${PREFIX}/share/sams/icon/classic/proxyes_32.jpg ${PREFIX}/share/sams/icon/bumper/proxyes_32.jpg
	@cp ${PREFIX}/share/sams/icon/classic/cache_32.jpg ${PREFIX}/share/sams/icon/bumper/cache_32.jpg
	@cp ${PREFIX}/share/sams/icon/classic/proxyes_48.jpg ${PREFIX}/share/sams/icon/bumper/proxyes_48.jpg
	@cp ${PREFIX}/share/sams/icon/classic/cache_48.jpg ${PREFIX}/share/sams/icon/bumper/cache_48.jpg
	@${CAT} ${PKGMESSAGE}

setup:
	@cd ${WRKSRC}; ${WRKSRC}/setup.sh

.include <bsd.port.post.mk>
