# New ports collection makefile for:	vmailmgr
# Date created:         24.Sep.2003
# Whom:                 patrick@rinke-bochum.de
#
# $FreeBSD$
#

PORTNAME=	vmailmgr
PORTVERSION=	0.96.9
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://www.vmailmgr.org/archive/

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Virtual MAIL ManaGeR for virtual mailboxes and domains

USE_APACHE=	yes
USE_QMAIL_RUN=	yes

HAS_CONFIGURE=	yes

SVC_DIR=	"${QMAIL_PREFIX}/service/vmailmgrd"
PHP_DIR=	${PREFIX}/www/data-dist/${PORTNAME}
CGI_DIR=	${PREFIX}/www/cgi-bin-dist

PLIST_SUB+=	PHP_DIR=${PHP_DIR} CGI_DIR=${CGI_DIR}

MAN1=		checkvpw.1 vauthenticate.1 vpasswd2cdb.1 vrehash.1 \
		listvdomain.1 vadduser.1 vchattr.1 vchforwards.1 \
		vcheckquota.1 vdeliver.1 vdeluser.1 vpasswd.1 \
		vpasswd2db.1 vpasswds.1 vpopbull.1 vsetup.1
MAN7=		vmailmgr.7
MAN8=		vmailmgrd.8

post-patch:
	@${REINPLACE_CMD} -e 's|phpdir=".home.httpd.php"|phpdir="${PHP_DIR}"|g' \
			  -e 's|cgidir=...prefix./cgi-bin.|cgidir="${CGI_DIR}"|g' \
		${WRKSRC}/configure ${WRKSRC}/configure.in
post-install:
	${MKDIR} ${PREFIX}/etc/vmailmgr
	${CP} ${WRKSRC}/scripts/autoresponder.sh ${PREFIX}/etc/vmailmgr/vdeliver-postdeliver
	${ECHO_CMD} "default" >${PREFIX}/etc/vmailmgr/default-username
	${MKDIR} ${SVC_DIR}/log
	${CP} ${WRKSRC}/scripts/vmailmgrd.run ${SVC_DIR}/run
	${CP} ${WRKSRC}/scripts/vmailmgrd-log.run ${SVC_DIR}/log/run

.include <bsd.port.mk>
