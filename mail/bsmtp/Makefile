# New ports collection makefile for:   bsmtp
# Date created:                2000-10-05
# Whom:                        Christian Weisgerber <naddy@mips.inka.de>
#
# $FreeBSD$

PORTNAME=	bsmtp
PORTVERSION=	1.02
PORTREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	naddy

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Batch SMTP support for sendmail, incoming and outgoing

CONFLICTS=	smail-3.*

USE_PERL5=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--redo

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500024
UUPREFIX=	/usr
.else
RUN_DEPENDS=	${LOCALBASE}/bin/uux:${PORTSDIR}/net/freebsd-uucp
UUPREFIX=	${LOCALBASE}
.endif

post-patch:
	@${CP} ${WRKSRC}/bsmtp.m4.8.9.in ${WRKSRC}/bsmtp.m4.8.10.in
	@${CP} ${FILESDIR}/bsmtp.m4.*.in ${WRKSRC}/

pre-configure:
	@${SED} <${FILESDIR}/config.sed >${WRKSRC}/config.sed \
		-e 's:%%CC%%:${CC}:' \
		-e 's:%%CFLAGS%%:${CFLAGS}:' \
		-e 's:%%PREFIX%%:${PREFIX}:' \
		-e 's:%%UUPREFIX%%:${UUPREFIX}:'

post-install:
	${MKDIR} ${PREFIX}/share/doc/bsmtp
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/bsmtp/

.include <bsd.port.post.mk>
