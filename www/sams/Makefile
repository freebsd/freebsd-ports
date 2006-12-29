# New ports collection makefile for:  sams
# Date created:		12 December 2006
# Whom:			dindin
#
# $FreeBSD$
#

PORTNAME=	sams
PORTVERSION=	20060417
CATEGORIES=	www
MASTER_SITES=	http://sams.irc.perm.ru/downloads/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	dindin@FreeBSD.org.ua
COMMENT=	Squid Accounting Management System

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_RC_SUBR=	sams.sh

USE_PHP=	gd mysql ldap
USE_MYSQL=	4.1

OPTIONS=	NTLM	"NTLM autorization/ActiveDirectory support"	off \
		APACHE2	"Use apache version 2"	off

OPTIONSFILE?=	${PORT_DBDIR}/${PORTNAME}/options

.if exists(${OPTIONSFILE})
.include "${OPTIONSFILE}"
.endif

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_TARGET=--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=--with-configfile=${LOCALBASE}/etc/sams.conf \
	       --with-rcd-locations=${LOCALBASE}/etc/rc.d/ \
	       --with-httpd-locations=${DOCUMENT_ROOT}

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if defined(WITH_NTLM)
RUN_DEPENDS=	 ${LOCALBASE}/bin/ntlm_auth:${PORTSDIR}/net/samba3
.endif

.if defined(WITH_APACHE2)
RUN_DEPENDS+=	${LOCALBASE}/sbin/httpd:${PORTSDIR}/www/apache13
.else
RUN_DEPENDS+=	${LOCALBASE}/sbin/httpd:${PORTSDIR}/www/apache22
.endif

post-extract:
	${INSTALL_SCRIPT} ${FILESDIR}/setup.sh ${WRKSRC}/

post-install:
	@${CAT} ${PKGMESSAGE}

setup:
	@cd ${WRKSRC}; ${WRKSRC}/setup.sh

.include <bsd.port.post.mk>
