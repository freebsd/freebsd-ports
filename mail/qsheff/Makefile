# New ports collection makefile for:   qsheff
# Date created:                 14 Jul 2005
# Whom:                         Ozkan KIRIK <ozkan@enderunix.org>
#
# $FreeBSD$
#

PORTNAME=	qsheff
PORTVERSION=	1.0.r1
CATEGORIES=	mail
MASTER_SITES=	http://www.enderunix.org/qsheff/
DISTNAME=	${PORTNAME}-1.0-r1

MAINTAINER=	ozkan@enderunix.org
COMMENT=	A qmail-queue replacement to filter mail traffic

RUN_DEPENDS=	${QMAIL_DIR}/bin/qmail-queue:${PORTSDIR}/mail/qmail \
		${LOCALBASE}/bin/ripmime:${PORTSDIR}/mail/ripmime

USE_REINPLACE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

PORTDOCS=	spamass-qsheff.en.html README COPYING AUTHORS ChangeLog \
		INSTALL UPGRADE THANKS TODO

SUB_FILES=	pkg-message

OPTIONS=	CLAMAV "Integrate with Clam AntiVirus" on

.if exists(${LOCALBASE}/qmail/bin/qmail-queue)
QMAIL_DIR?=	${LOCALBASE}/qmail
.else
QMAIL_DIR?=	/var/qmail
.endif

PREFIX?=	${QMAIL_DIR}

CONFIGURE_ARGS+=	--with-qmaildir=${QMAIL_DIR}

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_CLAMAV)
RUN_DEPENDS+=	${LOCALBASE}/bin/clamdscan:${PORTSDIR}/security/clamav
.endif
.if !defined(WITHOUT_FPROT) & defined(WITHOUT_CLAMAV)
RUN_DEPENDS+=	${LOCALBASE}/bin/f-prot:${PORTSDIR}/security/f-prot
.endif

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|\(install-data-am: \)install-qsheffdocDATA|\1|g' \
			  -e 's| contribute$$||g' \
		${WRKSRC}/Makefile.in
.endif

post-build:
.if defined(WITHOUT_CLAMAV)
	@${REINPLACE_CMD} -e 's|enable_virus_prog = 1|enable_virus_prog = 0|g' \
		${WRKSRC}/etc/qsheff.conf-default
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
