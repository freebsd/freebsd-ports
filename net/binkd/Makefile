# New ports collection makefile for:	binkd
# Version required:	0.9.2
# Date created:		19 August 1998
# Whom:			Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=	binkd-0.9.2
CATEGORIES=	net
MASTER_SITES=	http://www.corbina.net/~maloff/binkd/

MAINTAINER=	dsh@vlink.ru

USE_ZIP=	yes
GNU_CONFIGURE=	yes
MAN8=		binkd.8

.if defined(WITH_AMIGA4D)
EXTRA_PATCHES+=	${FILESDIR}/patch-amiga4d
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
