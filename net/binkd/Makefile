# New ports collection makefile for:	binkd
# Date created:		19 August 1998
# Whom:			Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	binkd
PORTVERSION=	0.9.4
CATEGORIES=	net
MASTER_SITES=	ftp://happy.kiev.ua/pub/fidosoft/mailer/binkd/
DISTNAME=	binkd094

MAINTAINER=	dsh@vlink.ru

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_ZIP=	yes
GNU_CONFIGURE=	yes

MAN8=		binkd.8

.if defined(WITH_AMIGA4D)
PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	binkdaso.diff
DEFINES+=	-DAMIGADOS_4D_OUTBOUND
MAKE_ENV+=	DEFINES="${DEFINES}"
.endif

pre-configure:
	@ ${CP} ${WRKSRC}/mkfls/unix/* ${WRKSRC}
	@ ${CHMOD} a+x ${WRKSRC}/configure

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/binkd ${PREFIX}/sbin
	@ ${INSTALL_MAN} ${WRKSRC}/binkd.8 ${PREFIX}/man/man8
	@ ${INSTALL_DATA} ${WRKSRC}/binkd.cfg ${PREFIX}/etc/binkd.cfg.sample

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/binkd
	@ ${INSTALL_DATA} ${WRKSRC}/!README ${PREFIX}/share/doc/binkd/README
	@ ${INSTALL_DATA} ${WRKSRC}/!README.FIX ${PREFIX}/share/doc/binkd/README.FIX
	@ ${INSTALL_DATA} ${WRKSRC}/!SRIF.TXT ${PREFIX}/share/doc/binkd/SRIF.TXT
	@ ${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/binkd
.endif

.include <bsd.port.mk>
