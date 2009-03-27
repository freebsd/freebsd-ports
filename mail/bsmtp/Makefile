# New ports collection makefile for:   bsmtp
# Date created:                2000-10-05
# Whom:                        Christian Weisgerber <naddy@mips.inka.de>
#
# $FreeBSD$

PORTNAME=	bsmtp
PORTVERSION=	1.02
PORTREVISION=	5
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
MAKE_JOBS_SAFE=	yes

.include <bsd.port.pre.mk>

RUN_DEPENDS=	${LOCALBASE}/bin/uux:${PORTSDIR}/net/freebsd-uucp
UUPREFIX=	${LOCALBASE}

post-patch:
	@${CP} ${WRKSRC}/bsmtp.m4.8.9.in ${WRKSRC}/bsmtp.m4.8.10.in
	@${CP} ${FILESDIR}/bsmtp.m4.8.11.in ${WRKSRC}/
.for v in 12 13 14
	@${CP} ${FILESDIR}/bsmtp.m4.8.12.in ${WRKSRC}/bsmtp.m4.8.$v.in
.endfor

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
