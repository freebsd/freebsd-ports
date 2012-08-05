# New ports collection makefile for:	binkd
# Date created:		19 August 1998
# Whom:			Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	binkd
PORTVERSION=	0.9.9
CATEGORIES=	net
MASTER_SITES=	ftp://happy.kiev.ua/pub/fidosoft/mailer/binkd/ \
		ftp://ftp.rsu.ru/pub/FreeBSD/ports/distfiles/
DISTNAME=	binkd${PORTVERSION:S/.//g}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Fidonet TCP/IP mailer

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_ZIP=	yes
USE_RC_SUBR=	binkd
GNU_CONFIGURE=	yes

MAN8=		binkd.8

.if !defined(WITHOUT_AMIGA4D)
CONFIGURE_ARGS+=	--with-aso
.endif

.if !defined(WITHOUT_HTTPS)
CONFIGURE_ARGS+=	--with-https
.endif

pre-configure:
	@${RM} -rf ${WRKSRC}/mkfls/unix/CVS
	@${CP} ${WRKSRC}/mkfls/unix/* ${WRKSRC}/
	@${CHMOD} a+x ${WRKSRC}/configure

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/binkd ${PREFIX}/sbin
	@${INSTALL_MAN} ${WRKSRC}/binkd.8 ${MANPREFIX}/man/man8
	@${INSTALL_DATA} ${WRKSRC}/binkd.cfg ${PREFIX}/etc/binkd.cfg.sample

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/!README ${DOCSDIR}/README
	@${INSTALL_DATA} ${WRKSRC}/!README.FIX ${DOCSDIR}/README.FIX
	@${INSTALL_DATA} ${WRKSRC}/!SRIF.TXT ${DOCSDIR}/SRIF.TXT
.endif

.include <bsd.port.mk>
