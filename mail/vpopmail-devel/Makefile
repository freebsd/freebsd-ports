# New ports collection makefile for: vpopmail
# Date created:		21 Sep 2000
# Whom:			makeport.pl
#
# $FreeBSD$
#

PORTNAME=	vpopmail
PORTVERSION=	4.9
CATEGORIES=	mail
MASTER_SITES=	http://www.inter7.com/vpopmail/

MAINTAINER=	nbm@FreeBSD.org

BUILD_DEPENDS=	${QMAIL_DIR}/bin/qmail-send:${PORTSDIR}/mail/qmail \
		${LOCALBASE}/bin/tcprules:${PORTSDIR}/sysutils/ucspi-tcp
RUN_DEPENDS=	${QMAIL_DIR}/bin/qmail-send:${PORTSDIR}/mail/qmail \
		${LOCALBASE}/bin/tcprules:${PORTSDIR}/sysutils/ucspi-tcp

GNU_CONFIGURE=	YES
USE_GMAKE=	YES

CONFIGURE_ARGS=	--enable-qmail-dir=${QMAIL_DIR} \
		--enable-tcprules-bin=${LOCALBASE}/bin/tcprules \
		--enable-tcpserver-file=~vpopmail/etc/tcp.smtp

#
# Attempt to set the location of qmail by a simple check.  Override this
# if your qmail lives elsewhere.
#

.if exists(${LOCALBASE}/qmail/bin/qmail-send)
QMAIL_DIR?=     ${LOCALBASE}/qmail
.else
QMAIL_DIR?=     /var/qmail
.endif

#
# This port doesn't honour PREFIX, it honours vpopmail's home directory.
# Since we create vpopmail if it doesn't exist, we set it so that it
# does honour PREFIX. -- nbm
#

pre-configure:
	@PKG_PREFIX=${PREFIX}/vpopmail ${PERL5} ${PKGDIR}/INSTALL

.include <bsd.port.mk>
