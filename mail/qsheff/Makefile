# New ports collection makefile for:   qsheff
# Date created:                 14 Jul 2005
# Whom:                         Ozkan KIRIK <ozkan@enderunix.org>
#
# $FreeBSD$
#

PORTNAME=	qsheff
PORTVERSION=	1.0.r4
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.enderunix.org/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/-r/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A qmail-queue replacement to filter mail traffic

BUILD_DEPENDS=	${LOCALBASE}/bin/ripmime:${PORTSDIR}/mail/ripmime
RUN_DEPENDS=	${BUILD_DEPENDS}
USE_QMAIL=	yes

GNU_CONFIGURE=	YES
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

PORTDOCS=	spamass-qsheff.en.html README COPYING AUTHORS ChangeLog \
		INSTALL UPGRADE THANKS TODO

OPTIONS=	CLAMAV "Integrate with Clam AntiVirus" on

CONFIGURE_ARGS+=	--with-qmaildir=${QMAIL_PREFIX}

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_CLAMAV)
RUN_DEPENDS+=	${LOCALBASE}/bin/clamdscan:${PORTSDIR}/security/clamav
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|^CFLAGS =|CFLAGS +=|" ${WRKSRC}/Makefile.in
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

.include <bsd.port.post.mk>
